#include "../include/gen_code.h"



void gen_precompiled_comparison()
{
	// generation du =
	fprintf(stdout, "LABEL_EQUAL:\n");
	// on stocke l'instruction parente
	fprintf(stdout, "\tsub $sp,$sp,4\n");
	fprintf(stdout, "\tsw $ra, 0($sp)\n");
	// on recupere les variables a tester
	fprintf(stdout, "\tlw $t0,8($sp)\n");
	fprintf(stdout, "\tlw $t1,4($sp)\n");

	//on effectue le test
	fprintf(stdout, "\tbeq $t0, $t1, LABEL_EQUAL_TRUE\n");
	fprintf(stdout, "\tli $v0, 0\n"); // les arguments ne sont pas egaux
	fprintf(stdout, "\t j LABEL_EQUAL_END\n");
	fprintf(stdout, "LABEL_EQUAL_TRUE:\n");
	fprintf(stdout, "\tli $v0,1\n");
	fprintf(stdout, "LABEL_EQUAL_END:\n");
	fprintf(stdout,"\tadd $sp, $sp,4\n");
	fprintf(stdout, "\t jr $ra\n");
	// generation du >=


	//generation du <=

	//generationn du !=

}

void gen_init_var(quad q)
{
	fprintf(stdout, "\n");
	fprintf(stdout, "%s :\n", q->res->name);
    fprintf(stdout, "\t.word 0\n\n");
}

void gen_affec_var(quad q)
{
	if(q->arg1->isconst)
		fprintf(stdout, "\tli $t0,%d\n\n", q->arg1->value.int_value);
	fprintf(stdout, "\tsw $t0,%s\n\n", q->res->name);
}

// Pour tout les calculs arithmetiques, nous aurons besoins au max de 3 registres
// 2 registres pour calculer les termes actuels et le 3 eme pour recuperer
// la valeur du precedent calcul (si besoin)
void gen_arithmetic(quad q)
{
	fprintf(stdout, "\t# arithmetic\n");
	// si l'expression de gauche a deja ete calculee, on recupere
	// sa valeur dans le registre
	if(q->arg1->address != NULL)
	{
		fprintf(stdout, "\tmove $t0,%s\n", q->arg1->address);
		// on met a jour les registres
		if(strcmp(q->arg1->address, "$t2") == 0)
		{
			temp_register[0] = 0;
		}
		if(strcmp(q->arg1->address, "$t3") == 0)
		{
			temp_register[1] = 0;
		}
	}
	else
	{
		// on recupere la valeur si on a utilise un identifiant
		if(q->arg1->isconst == FALSE && q->arg1->name != NULL)
			fprintf(stdout, "\tlw $t0,%s\n", q->arg1->name);
		else // on declare une nouvelle constante
			fprintf(stdout, "\tli $t0,%d\n", q->arg1->value.int_value);
	}

	// meme test qu'avant mais pour le second argument
	if(q->arg2->address != NULL)
	{
		fprintf(stdout, "\tmove $t1,%s\n", q->arg2->address);

		// on met a jour les registres
		if(strcmp(q->arg2->address, "$t2") == 0)
		{
			temp_register[0] = 0;
			q->res->address = strdup("$t2");
		}
		if(strcmp(q->arg2->address, "$t3") == 0)
		{
			temp_register[1] = 0;
		}
	}
	else
	{
		// on recupere la valeur si on a utilise un identifiant
		if(q->arg2->isconst == FALSE && q->arg2->name != NULL)
			fprintf(stdout, "\tlw $t1,%s\n", q->arg2->name);
		else // on declare une nouvelle constante
			fprintf(stdout, "\tli $t1,%d\n", q->arg2->value.int_value);
	}


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
		default:
			break;
	}
	fprintf(stdout, " $t0,$t0,$t1\n");


	// on stocke le resultat dans un autre registre temporraire
	if(temp_register[0] == 0)
	{
		temp_register[0] = 1;
		q->res->address = strdup("$t2");
		fprintf(stdout, "\tmove $t%d,$t0\n", 2);
	}
	else
	{
		temp_register[1] = 2;
		q->res->address = strdup("$t3");

		fprintf(stdout, "\tmove $t%d,$t0\n", 3);
	}
	fprintf(stdout, "\n");

}

void gen_boolexpr_equal(quad q)
{

	fprintf(stdout, "\t# BOOL_EXPR =\n");

	// on met dans la pile les arguments
	fprintf(stdout, "\tsub $sp,$sp,8\n");
	fprintf(stdout, "\tlw $s0,%s\n", q->arg1->name);
	fprintf(stdout, "\tsw $s0,0($sp)\n");
	fprintf(stdout, "\tlw $s0,%s\n", q->arg2->name);
	fprintf(stdout, "\tsw $s0,4($sp)\n");

	// on effectue le test d'egalite
	fprintf(stdout, "\tjal LABEL_EQUAL\n");



}

void gen_syscall_print_int(quad q)
{
	fprintf(stdout, "\t# print_int\n");
	fprintf(stdout, "\tli $v0,1\n");
	if(q->res->isconst == TRUE)
		fprintf(stdout, "\tli $a0,%d\n", q->res->value.int_value);
	else if(q->res->is_tmp == TRUE)
		fprintf(stdout, "\tmove $a0,%s\n", q->res->address);
	else
		fprintf(stdout, "\tlw $a0,%s\n", q->res->name);
	fprintf(stdout, "\tsyscall\n\n");

}
