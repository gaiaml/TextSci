#include "../include/gen_code.h"



void gen_precompiled_comparison()
{
	// generation du =
	fprintf(stdout, "LABEL_EQUAL:\n");
	// on recupere les variables a tester
	fprintf(stdout, "\tlw $t0,0($sp)\n");
	fprintf(stdout, "\tlw $t1,4($sp)\n");
	//on effectue le test
	fprintf(stdout, "\tbeq $t0, $t1, LABEL_EQUAL_TRUE\n");
	fprintf(stdout, "\tli $v1, 0\n"); // les arguments ne sont pas egaux
	fprintf(stdout, "\t j LABEL_EQUAL_END\n");
	fprintf(stdout, "LABEL_EQUAL_TRUE:\n");
	fprintf(stdout, "\tli $v1,1\n");
	fprintf(stdout, "LABEL_EQUAL_END:\n");
	fprintf(stdout, "\t jr $ra\n");
	// generation du >=
	fprintf(stdout, "LABEL_SEQUAL:\n");
	// on recupere les variables a tester
	fprintf(stdout, "\tlw $t0,0($sp)\n");
	fprintf(stdout, "\tlw $t1,4($sp)\n");
	fprintf(stdout, "\tbge $t0, $t1, LABEL_SEQUAL_TRUE\n");
	fprintf(stdout, "\tli $v1, 0\n");
	fprintf(stdout, "\t j LABEL_SEQUAL_END\n");
	fprintf(stdout, "LABEL_SEQUAL_TRUE:\n");
	fprintf(stdout, "\tli $v1,1\n");
	fprintf(stdout, "LABEL_SEQUAL_END:\n");
	fprintf(stdout, "\t jr $ra\n");
	// generation du >
	fprintf(stdout, "LABEL_SUP:\n");
	fprintf(stdout, "\tlw $t0,0($sp)\n");
	fprintf(stdout, "\tlw $t1,4($sp)\n");
	fprintf(stdout, "\tbgt $t0, $t1, LABEL_SUP_TRUE\n");
	fprintf(stdout, "\tli $v1, 0\n");
	fprintf(stdout, "\t j LABEL_SUP_END\n");
	fprintf(stdout, "LABEL_SUP_TRUE:\n");
	fprintf(stdout, "\tli $v1,1\n");
	fprintf(stdout, "LABEL_SUP_END:\n");
	fprintf(stdout, "\t jr $ra\n");
	//generation du <=
	fprintf(stdout, "LABEL_IEQUAL:\n");
	fprintf(stdout, "\tlw $t0,0($sp)\n");
	fprintf(stdout, "\tlw $t1,4($sp)\n");
	fprintf(stdout, "\tble $t0, $t1, LABEL_IEQUAL_TRUE\n");
	fprintf(stdout, "\tli $v1, 0\n");
	fprintf(stdout, "\t j LABEL_IEQUAL_END\n");
	fprintf(stdout, "LABEL_IEQUAL_TRUE:\n");
	fprintf(stdout, "\tli $v1,1\n");
	fprintf(stdout, "LABEL_IEQUAL_END:\n");
	fprintf(stdout, "\t jr $ra\n");

	//generation du <
	fprintf(stdout, "LABEL_INF:\n");
	fprintf(stdout, "\tlw $t0,0($sp)\n");
	fprintf(stdout, "\tlw $t1,4($sp)\n");
	fprintf(stdout, "\tblt $t0, $t1, LABEL_INF_TRUE\n");
	fprintf(stdout, "\tli $v1, 0\n");
	fprintf(stdout, "\t j LABEL_INF_END\n");
	fprintf(stdout, "LABEL_INF_TRUE:\n");
	fprintf(stdout, "\tli $v1,1\n");
	fprintf(stdout, "LABEL_INF_END:\n");
	fprintf(stdout, "\t jr $ra\n");

	//generation du !=
	fprintf(stdout, "LABEL_NEQUAL:\n");
	fprintf(stdout, "\tlw $t0,0($sp)\n");
	fprintf(stdout, "\tlw $t1,4($sp)\n");
	fprintf(stdout, "\tbeq $t0, $t1, LABEL_NEQUAL_TRUE\n");
	fprintf(stdout, "\tli $v1, 0\n"); // les arguments ne sont pas egaux
	fprintf(stdout, "\t j LABEL_NEQUAL_END\n");
	fprintf(stdout, "LABEL_NEQUAL_TRUE:\n");
	fprintf(stdout, "\tli $v1,1\n");
	fprintf(stdout, "LABEL_NEQUAL_END:\n");
	fprintf(stdout, "\t jr $ra\n");

	// generation > 0
	fprintf(stdout, "LABEL_SUP0:\n");
	fprintf(stdout, "\tlw $t0,0($sp)\n");
	fprintf(stdout, "\tbgtz $t0, LABEL_SUP0_TRUE\n");
	fprintf(stdout, "\tli $v1, 0\n"); // les arguments ne sont pas egaux
	fprintf(stdout, "\t j LABEL_SUP0_END\n");
	fprintf(stdout, "LABEL_SUP0_TRUE:\n");
	fprintf(stdout, "\tli $v1,1\n");
	fprintf(stdout, "LABEL_SUP0_END:\n");
	fprintf(stdout, "\t jr $ra\n");


}

void gen_init_var(quad q)
{
	fprintf(stdout, "\n");
	fprintf(stdout, "%s :\n", q->res->name);

	switch (q->res->type)
	{
		case INT_TYPE:
		case BOOL_TYPE:
			fprintf(stdout, "\t.word 0\n");
			break;
		case REAL_TYPE:
			fprintf(stdout, "\t.float 0.0\n");
			break;
		case TEXT_TYPE:
			fprintf(stdout, "\t.asciiz %s\n", q->res->value.string_value);
			break;
		default:
			break;
	}

	fprintf(stdout, "\n");
}

void gen_affec_var(quad q)
{
	gen_affect_var(strdup("$t0"), q->arg1);
	switch (q->res->type)
	{
		case BOOL_TYPE:
		case INT_TYPE:
			fprintf(stdout, "\tsw $t0,%s\n\n", q->res->name);
			break;
		case REAL_TYPE:
			fprintf(stdout, "\ts.s $f0,%s\n\n", q->res->name);
			break;
		default:
			break;
	}
}

// Pour tout les calculs arithmetiques, nous aurons besoins au max de 3 registres
// 2 registres pour calculer les termes actuels et le 3 eme pour recuperer
// la valeur du precedent calcul (si besoin)
void gen_arithmetic(quad q)
{

	// registre tmp pour les calculs
	char *reg_0;
	char *reg_1;
	char *reg_2;
	char *reg_3;

	// instructions a utiliser
	char *li;
	char *lw;
	char *move;



	// recupere par defaut le registre a utiliser
	// s'adapte pour tout les types
	switch (q->res->type)
	{
		case INT_TYPE:
		case BOOL_TYPE:
			reg_0 = strdup("$t0");
			reg_1 = strdup("$t1");
			reg_2 = strdup("$t2");
			reg_3 = strdup("$t3");

			li = strdup("li");
			lw = strdup("lw");
			move = strdup("move");

			break;
		case REAL_TYPE:
			reg_0 = strdup("$f0");
			reg_1 = strdup("$f1");
			reg_2 = strdup("$f2");
			reg_3 = strdup("$f3");

			li = strdup("li.s");
			lw = strdup("l.s");
			move = strdup("mov.s");

			break;
		default:
			break;
	}

	fprintf(stdout, "\t# arithmetic\n");
	// si l'expression de gauche a deja ete calculee, on recupere
	// sa valeur dans le registre
	if(q->arg1->address != NULL)
	{
		fprintf(stdout, "\t%s %s,%s\n", move, reg_0, q->arg1->address);
		// on met a jour les registres
		if(strcmp(q->arg1->address, reg_2) == 0)
		{
			temp_register[0] = 0;
		}
		if(strcmp(q->arg1->address, reg_3) == 0)
		{
			temp_register[1] = 0;
		}
	}
	else
	{

		// on recupere la valeur si on a utilise un identifiant
		if(q->arg1->isconst == FALSE && q->arg1->name != NULL)
			fprintf(stdout, "\t%s %s,%s\n", lw, reg_0, q->arg1->name);
		else // on declare une nouvelle constante
		{
			if(q->arg1->type == REAL_TYPE)
				fprintf(stdout, "\t%s %s,%f\n",li, reg_0,q->arg1->value.float_value);
			else
				fprintf(stdout, "\t%s %s,%d\n",li, reg_0,q->arg1->value.int_value);
		}
	}

	// meme test qu'avant mais pour le second argument
	if(q->arg2->address != NULL)
	{
		fprintf(stdout, "\t%s %s,%s\n", move, reg_1, q->arg2->address);

		// on met a jour les registres
		if(strcmp(q->arg2->address, reg_2) == 0)
		{
			temp_register[0] = 0;
			q->res->address = strdup(reg_2);
		}
		if(strcmp(q->arg2->address, reg_3) == 0)
		{
			temp_register[1] = 0;
		}
	}
	else
	{
		// on recupere la valeur si on a utilise un identifiant
		if(q->arg2->isconst == FALSE && q->arg2->name != NULL)
			fprintf(stdout, "\t%s %s,%s\n", lw,reg_1,q->arg2->name);
		else // on declare une nouvelle constante
		{
			if(q->arg2->type == REAL_TYPE)
				fprintf(stdout, "\t%s %s,%f\n",li, reg_1,q->arg2->value.float_value);
			else
				fprintf(stdout, "\t%s %s,%d\n", li,reg_1, q->arg2->value.int_value);
		}
	}

	switch (q->res->type)
	{
		case INT_TYPE:
		case BOOL_TYPE:
			switch(q->op)
			{
				case OP_PLUS:
					fprintf(stdout, "\tadd");
					break;
				case OP_MINUS:
					fprintf(stdout, "\tsub");
					break;
				case OP_TIMES:
					fprintf(stdout, "\tmul");
					break;
				case OP_DIV:
					fprintf(stdout, "\tdiv");
				default:
					break;
			}
			break;
		case REAL_TYPE:
		switch(q->op)
		{
			case OP_PLUS:
				fprintf(stdout, "\tadd.s");
				break;
			case OP_MINUS:
				fprintf(stdout, "\tsub.s");
				break;
			case OP_TIMES:
				fprintf(stdout, "\tmul.s");
				break;
			case OP_DIV:
				fprintf(stdout, "\tdiv.s");
			default:
				break;
		}
			break;
		default:
			break;


	}

	fprintf(stdout, " %s,%s,%s\n", reg_0, reg_0, reg_1);


	// on stocke le resultat dans un autre registre temporraire
	if(temp_register[0] == 0)
	{
		temp_register[0] = 1;
		q->res->address = strdup(reg_2);
		fprintf(stdout, "\t%s %s,%s\n", move, reg_2, reg_0);
	}
	else
	{
		temp_register[1] = 2;
		q->res->address = strdup(reg_3);

		fprintf(stdout, "\t%s %s,%s\n", move, reg_3,reg_0);
	}
	fprintf(stdout, "\n");

}

void gen_boolexpr_equal(quad q)
{

	fprintf(stdout, "\t# BOOL_EXPR =\n");

	// on met dans la pile les arguments
	fprintf(stdout, "\tsub $sp,$sp,8\n");
	gen_affect_var(strdup("$s0"), q->arg1);
	fprintf(stdout, "\tsw $s0,0($sp)\n");
	gen_affect_var(strdup("$s0"), q->arg2);
	fprintf(stdout, "\tsw $s0,4($sp)\n");

	// on effectue le test d'egalite
	fprintf(stdout, "\tjal LABEL_EQUAL\n");
	fprintf(stdout, "\tadd $sp,$sp,8\n");
	fprintf(stdout, "\tbeq $v1,0,IF_%d_FALSELIST\n", q->label_id);
	fprintf(stdout, "\t#TRUE LIST\n");

}

void gen_boolexpr_iequal(quad q)
{

	fprintf(stdout, "\t# BOOL_EXPR <=\n");

	// on met dans la pile les arguments
	fprintf(stdout, "\tsub $sp,$sp,8\n");
	gen_affect_var(strdup("$s0"), q->arg1);
	fprintf(stdout, "\tsw $s0,0($sp)\n");
	gen_affect_var(strdup("$s0"), q->arg2);
	fprintf(stdout, "\tsw $s0,4($sp)\n");

	// on effectue le test d'egalite
	fprintf(stdout, "\tjal LABEL_IEQUAL\n");
	fprintf(stdout, "\tadd $sp,$sp,8\n");
	fprintf(stdout, "\tbeq $v1,0,IF_%d_FALSELIST\n", q->label_id);
	fprintf(stdout, "\t#TRUE LIST\n");

}
void gen_boolexpr_sequal(quad q)
{

	fprintf(stdout, "\t# BOOL_EXPR >=\n");

	// on met dans la pile les arguments
	fprintf(stdout, "\tsub $sp,$sp,8\n");
	gen_affect_var(strdup("$s0"), q->arg1);
	fprintf(stdout, "\tsw $s0,0($sp)\n");
	gen_affect_var(strdup("$s0"), q->arg2);
	fprintf(stdout, "\tsw $s0,4($sp)\n");

	// on effectue le test d'egalite
	fprintf(stdout, "\tjal LABEL_SEQUAL\n");
	fprintf(stdout, "\tadd $sp,$sp,8\n");
	fprintf(stdout, "\tbeq $v1,0,IF_%d_FALSELIST\n", q->label_id);
	fprintf(stdout, "\t#TRUE LIST\n");

}
void gen_boolexpr_inf(quad q)
{
	fprintf(stdout, "\t# BOOL_EXPR <\n");

	// on met dans la pile les arguments
	fprintf(stdout, "\tsub $sp,$sp,8\n");
	gen_affect_var(strdup("$s0"), q->arg1);
	fprintf(stdout, "\tsw $s0,0($sp)\n");
	gen_affect_var(strdup("$s0"), q->arg2);
	fprintf(stdout, "\tsw $s0,4($sp)\n");

	// on effectue le test d'egalite
	fprintf(stdout, "\tjal LABEL_INF\n");
	fprintf(stdout, "\tadd $sp,$sp,8\n");
	fprintf(stdout, "\tbeq $v1,0,IF_%d_FALSELIST\n", q->label_id);
	fprintf(stdout, "\t#TRUE LIST\n");

}
void gen_boolexpr_sup(quad q)
{
	fprintf(stdout, "\t# BOOL_EXPR >\n");

	// on met dans la pile les arguments
	fprintf(stdout, "\tsub $sp,$sp,8\n");
	gen_affect_var(strdup("$s0"), q->arg1);
	fprintf(stdout, "\tsw $s0,0($sp)\n");
	gen_affect_var(strdup("$s0"), q->arg2);
	fprintf(stdout, "\tsw $s0,4($sp)\n");

	// on effectue le test d'egalite
	fprintf(stdout, "\tjal LABEL_SUP\n");
	fprintf(stdout, "\tadd $sp,$sp,8\n");
	fprintf(stdout, "\tbeq $v1,0,IF_%d_FALSELIST\n", q->label_id);
	fprintf(stdout, "\t#TRUE LIST\n");

}
void gen_boolexpr_sup0(quad q)
{
	fprintf(stdout, "\t# BOOL_EXPR > 0\n");

	// on met dans la pile les arguments
	fprintf(stdout, "\tsub $sp,$sp,4\n");
	gen_affect_var(strdup("$s0"), q->arg1);
	fprintf(stdout, "\tsw $s0,0($sp)\n");

	// on effectue le test d'egalite
	fprintf(stdout, "\tjal LABEL_SUP0\n");
	fprintf(stdout, "\tadd $sp,$sp,4\n");
	fprintf(stdout, "\tbeq $v1,0,IF_%d_FALSELIST\n", q->label_id);
	fprintf(stdout, "\t#TRUE LIST\n");

}
void gen_syscall_print_int(quad q)
{
	fprintf(stdout, "\t# print_int\n");
	fprintf(stdout, "\tli $v0,1\n");
	gen_affect_var(strdup("$a0"), q->res);
	fprintf(stdout, "\tsyscall\n\n");

}

void gen_syscall_print_text(quad q)
{
	fprintf(stdout, "\t# print_text\n");
	fprintf(stdout, "\tli $v0,4\n");
	gen_affect_var(strdup("$a0"), q->res);
	fprintf(stdout, "\tsyscall\n\n");
}

void gen_syscall_print_real(quad q)
{
	fprintf(stdout, "\t# print_float\n");
	fprintf(stdout, "\tli $v0,2\n");
	gen_affect_var(strdup("$f12"), q->res);
	fprintf(stdout, "\tsyscall\n\n");
}

void gen_affect_var(char *reg, symbol s)
{
	if(s->type == REAL_TYPE)
		reg[1] = 'f';
	if(s->isconst == TRUE)
	{
		switch (s->type)
		{
			case INT_TYPE:
			case BOOL_TYPE:
				fprintf(stdout, "\tli %s,%d\n", reg, s->value.int_value);
				break;
			case REAL_TYPE:
				fprintf(stdout, "\tli.s %s,%f\n", reg, s->value.float_value);
				break;
			default:
				break;
		}

	}
	else if(s->is_tmp == TRUE)
	{
		if(s->type == REAL_TYPE)
			fprintf(stdout, "\tmov.s %s,%s\n", reg, s->address);
		else
			fprintf(stdout, "\tmove %s,%s\n", reg, s->address);
	}
	else
	{
		switch (s->type)
		{
			case TEXT_TYPE:
				fprintf(stdout, "\tla %s,%s\n", reg, s->name);
				break;
			case INT_TYPE:
			case BOOL_TYPE:
				fprintf(stdout, "\tlw %s,%s\n", reg, s->name);
				break;
			case REAL_TYPE:
				fprintf(stdout, "\tl.s %s,%s\n", reg, s->name);
				break;
			default:
				break;
		}
	}
}

void gen_loop_increment(quad q)
{
	char *reg;
	char *lw;
	char *sw;
	switch (q->arg1->type)
	{
		case BOOL_TYPE:
		case INT_TYPE:
			reg = strdup("$t0");
			lw = strdup("lw");
			sw = strdup("sw");
			break;
		case REAL_TYPE:
			reg = strdup("$f0");
			lw = strdup("l.s");
			sw = strdup("s.s");
			break;
		default:
			break;

	}
	fprintf(stdout, "\t%s %s,%s\n", lw,reg,q->arg1->name);
	if(q->arg1->type == REAL_TYPE)
	{
		fprintf(stdout, "\tli.s $f1,1.0\n");
		fprintf(stdout, "\tadd.s %s,%s,$f1\n", reg,reg);
	}
	else
		fprintf(stdout, "\tadd %s,%s,1\n", reg,reg);

	fprintf(stdout, "\t%s %s,%s\n", sw,reg,q->arg1->name);
}
void gen_init_var_array(quad q)
{
		fprintf(stdout, "\n");
		fprintf(stdout, "%s :\n", q->res->name);

		char *value;
		switch (q->res->type)
		{
			case INT_TYPE:
			case BOOL_TYPE:
				fprintf(stdout, "\t.word ");
				value = strdup("0");
				break;
			case REAL_TYPE:
				fprintf(stdout, "\t.float ");
				value = strdup("0.0");
				break;
			default:
				break;
		}
		for(int i = 0; i < q->res->vector.size; i++)
		{
			fprintf(stdout, "%s,", value);
		}
		fprintf(stdout, "\n");

}
