%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "include/symbol_array.h"
  #include "include/quad.h"
  #include "include/gen_code.h"
  #define TEXCC_ERROR_GENERAL 4


  // Functions and global variables provided by Lex.
  int yylex();
  int id_label;
  int id_str; // tmp
  void texcc_lexer_free();
  extern FILE* yyin;
  extern int yylineno;
  extern char* yytext;

  symbol_array symbol_table;
  quad all_quad;
  void yyerror(char* s)
  {
    printf("Ligne %d: %s sur le token : %s\n", yylineno, s, yytext);
  }
%}

%union {
  char* name;
  int value;
  symbol variable;
  enum TYPE type;

  struct{
    symbol variable;
    quad listquad;
  }code;
}

%token <value> TEXSCI_BEGIN TEXSCI_END BLANKLINE
%token <value> AFFECTATION INF_EQUAL SUP_EQUAL

%token <value> MBOX PRINT_INT_TK PRINT_TEXT_TK PRINT_REAL_TK

%token INPUT_DECLARATION OUTPUT_DECLARATION GLOBAL_DECLARATION LOCAL_DECLARATION
%token IN_KEY
%token WHILE FOR KWTO
%token <type> TYPE_KEY

%token <name> ID
%token <name> ID_VARS

%token IF EIF

%token <variable> NUMBER STRING REAL
%type <variable> VARIABLE LIST_VARS
%type <code> EXPRESSION BOOL_EXPR IF EIF LIST_CODE CODE FUNCTION AFFEC CONDITION_FOR

%right '=' AFFECTATION
%left '<' '>' INF_EQUAL SUP_EQUAL
%left '+' '-'
%left '*' '/'


%%

algorithm_list:
    algorithm_list algorithm
  | algorithm
  ;

algorithm:
    TEXSCI_BEGIN '{' ID '}' DECLARATIONS BLANKLINE LIST_CODE TEXSCI_END
    {
      fprintf(stdout, ".data\n");
      mips_generate_symbol(symbol_table);
      symbol_table->length = 0;

      fprintf(stderr, "[texcc] info: algorithm \"%s\" parsed\n", $3);
      //print_symbol_table(symbol_table, $3);
      free($3);
    }
    ;

  LIST_CODE:
      CODE LIST_CODE
      | CODE
      ;
  CODE:
    {}
    |
    AFFEC
    |
    FUNCTION
    |
    IF '{' '$' BOOL_EXPR '$' '}' '{' LIST_CODE  '}'
    {
      fprintf(stdout, "\t#FALSE LIST\n");
      fprintf(stdout, "\tIF_%d_FALSELIST:\n", $4.listquad->label_id);
    }
    |
    EIF '{' '$' BOOL_EXPR '$' '}' '{' LIST_CODE  '}' M_BOOL '{' LIST_CODE '}'
    {
      fprintf(stdout, "\tIF_%d_END:\n", $4.listquad->label_id);
    }
    |
    WHILE M_WHILE '{' '$' BOOL_EXPR '$' '}' '{' LIST_CODE '}'
    {
      fprintf(stdout, "\tj WHILE_%d_BEGIN\n", $5.listquad->label_id);
      fprintf(stdout, "\tIF_%d_FALSELIST:\n", $5.listquad->label_id);
    }
    |
    FOR CONDITION_FOR '{' LIST_CODE '}'
    {
      //lw $t0,i
      //add $t0,$t0,1
      //sw $t0,i

      // incremente le compteur
      mips_generate($2.listquad);
      fprintf(stdout, "\tj WHILE_%d_BEGIN\n", $2.listquad->label_id);
      fprintf(stdout, "\tIF_%d_FALSELIST:\n", $2.listquad->label_id);
    }
    ;
    CONDITION_FOR:
    '{' AFFEC KWTO '$' NUMBER '$' '}'
    {
      // on converti  le for en while :

      fprintf(stdout, "\tWHILE_%d_BEGIN:\n", id_label);
      mips_generate(create_quad(NULL, OP_BOOL_INF,$2.variable,$5, NULL));
      $$.listquad = create_quad(NULL, OP_LOOP_FOR, $2.variable, NULL,NULL);
    }
    ;
    M_WHILE:
    {
      fprintf(stdout, "\tWHILE_%d_BEGIN:\n", id_label);
    };
    M_BOOL:
    {
      fprintf(stdout, "\tj IF_%d_END\n", id_label-1);
      fprintf(stdout, "\t#FALSE LIST\n");
      fprintf(stdout, "\tIF_%d_FALSELIST:\n", id_label-1);
    };
    AFFEC:
    '$' ID AFFECTATION EXPRESSION '$'
    {
      symbol s = search($2, symbol_table);
      if(s != NULL )
      {
        if(s->type != $4.variable->type)
        {
          fprintf(stderr, "Erreur de typage ligne : %d entre %s et %s!\n",yylineno, s->name, $4.variable->name);
          exit(3);
        }
        //s->isconst = FALSE;
        //s->name = strdup($2);
        mips_generate($4.listquad);
        quad q = create_quad(NULL,OP_AFFEC,$4.variable, NULL, s);
        mips_generate(q);
        $$.variable = s;

      }
      else
      {
        fprintf(stderr, "Erreur ligne : %d la variable %s n'est pas declare !\n",yylineno, $2);
        exit(3);
      }
    }
    ;
  FUNCTION:
    '$' MBOX '{' PRINT_INT_TK '(' '$' EXPRESSION '$' ')'  '}' '$'
    {
      if($7.variable->type == INT_TYPE)
      {
        mips_generate($7.listquad);
        quad q = create_quad(NULL, PRINT_INTEGER, NULL, NULL, $7.variable);
        mips_generate(q);
      }
      else
      {
        fprintf(stderr, "Erreur de typage ligne : %d %s n'est pas de type int!\n",yylineno, $7.variable->name);
        exit(3);
      }
    }
    |
    '$' MBOX '{' PRINT_REAL_TK '(' '$' EXPRESSION '$' ')'  '}' '$'
    {
      if($7.variable->type == REAL_TYPE)
      {
        mips_generate($7.listquad);
        quad q = create_quad(NULL, PRINT_REAL, NULL, NULL, $7.variable);
        mips_generate(q);
      }
      else
      {
        fprintf(stderr, "Erreur de typage ligne : %d %s n'est pas de type real!\n",yylineno, $7.variable->name);
        exit(3);
      }
    }
    |
    '$' MBOX '{' PRINT_TEXT_TK '(' '$' STRING '$' ')'  '}' '$'
    {
      if($7->type == TEXT_TYPE)
      {
        // On verifie si la chaine existe
        symbol s = search_string($7->value.string_value, symbol_table);
        if(s == NULL)
        {
          char id[LENGTH_MAX_STRING];
          sprintf(id, "%d", id_str);

          $7->name = strcat(strdup($7->name), id);
          s = add_to_symbol_array($7, symbol_table);
          id_str++;
        }
        quad q = create_quad(NULL, PRINT_STRING, NULL, NULL, s);
        mips_generate(q);
      }
      else
      {
        fprintf(stderr, "Erreur de typage ligne : %d %s n'est pas de type string!\n",yylineno, $7->name);
        exit(3);
      }
    }
    ;


  EXPRESSION:
    EXPRESSION '+' EXPRESSION
    {
      symbol res = (symbol)malloc(sizeof(s_symbol));
      res->name = strdup("tmp_res");
      res->is_tmp = TRUE;
      res->address = strdup("$t0");
      res->type = $1.variable->type;
      // verification du type
      if($1.variable->type == $3.variable->type)
      {
        $$.variable = res;
        quad q = quad_concat($3.listquad, $1.listquad);
        $$.listquad = create_quad(q, OP_PLUS, $1.variable,$3.variable, res);
      }
      else
      {
        fprintf(stderr, "Erreur de typage ligne : %d entre %s et %s!\n",yylineno, $1.variable->name, $3.variable->name);
        exit(3);
      }
    }
    |
    EXPRESSION '-' EXPRESSION
    {
      symbol res = (symbol)malloc(sizeof(s_symbol));
      res->name = strdup("tmp_res");
      res->is_tmp = TRUE;
      res->address = strdup("$t0");
      res->type = $1.variable->type;
      // verification du type
      if($1.variable->type == $3.variable->type)
      {
        $$.variable = res;
        quad q = quad_concat($3.listquad, $1.listquad);
        $$.listquad = create_quad(q, OP_MINUS, $1.variable,$3.variable, res);
      }
      else
      {
        fprintf(stderr, "Erreur de typage ligne : %d entre %s et %s!\n",yylineno, $1.variable->name, $3.variable->name);
        exit(3);
      }
    }
    |
    EXPRESSION '/' EXPRESSION
    {
      symbol res = (symbol)malloc(sizeof(s_symbol));
      res->name = strdup("tmp_res");
      res->is_tmp = TRUE;
      res->address = strdup("$t0");
      res->type = $1.variable->type;
      // verification du type
      if($1.variable->type == $3.variable->type)
      {
        $$.variable = res;
        quad q = quad_concat($3.listquad, $1.listquad);
        $$.listquad = create_quad(q, OP_DIV, $1.variable,$3.variable, res);
      }
      else
      {
        fprintf(stderr, "Erreur de typage ligne : %d entre %s et %s!\n",yylineno, $1.variable->name, $3.variable->name);
        exit(3);
      }
    }
    |
    EXPRESSION '*' EXPRESSION
    {
      symbol res = (symbol)malloc(sizeof(s_symbol));
      res->name = strdup("tmp_res");
      res->is_tmp = TRUE;
      res->address = strdup("$t0");
      res->type = $1.variable->type;
      // verification du type
      if($1.variable->type == $3.variable->type)
      {
        //all_quad = create_quad(all_quad, OP_TIMES, $1.variable,$3.variable, res);
        $$.variable = res;
        quad q = quad_concat($1.listquad, $3.listquad);
        $$.listquad = create_quad(q, OP_TIMES, $1.variable,$3.variable, res);
      }
      else
      {
        fprintf(stderr, "Erreur de typage ligne : %d entre %s et %s!\n",yylineno, $1.variable->name, $3.variable->name);
        exit(3);
      }
    }
    |
    '('EXPRESSION ')'
    {
      $$ = $2;
    }
    |
    NUMBER
    { // ajout dans la table des symboles;
      $1->isconst = TRUE;
      $$.variable = add_to_symbol_array($1, symbol_table);
    }
    |
    REAL
    {
      $1->isconst = TRUE;
      $$.variable = add_to_symbol_array($1, symbol_table);
    }
    |
    ID
    {
      symbol s = search($1, symbol_table);
      if(s == NULL)
      {
        fprintf(stderr, "Erreur ligne : %d la variable %s n'est pas declare !\n",yylineno, $1);
        exit(3);
      }
      s->address = NULL;
      $$.variable = s;
    }

    ;
  BOOL_EXPR:
    EXPRESSION '=' EXPRESSION
    {
      quad q = quad_concat($1.listquad, $3.listquad);
      $$.listquad = create_quad(q, OP_BOOL_EQUAL, $1.variable, $3.variable, NULL);
      $$.listquad->label_id = id_label++;
      mips_generate($$.listquad);
    }
    |
    EXPRESSION INF_EQUAL EXPRESSION
    {
      quad q = quad_concat($1.listquad, $3.listquad);
      $$.listquad = create_quad(q, OP_BOOL_IEQUAL, $1.variable, $3.variable, NULL);
      $$.listquad->label_id = id_label++;
      mips_generate($$.listquad);
    }
    |
    EXPRESSION SUP_EQUAL EXPRESSION
    {
      quad q = quad_concat($1.listquad, $3.listquad);
      $$.listquad = create_quad(q, OP_BOOL_SEQUAL, $1.variable, $3.variable, NULL);
      $$.listquad->label_id = id_label++;
      mips_generate($$.listquad);
    }
    |
    EXPRESSION '<' EXPRESSION
    {
      quad q = quad_concat($1.listquad, $3.listquad);
      $$.listquad = create_quad(q, OP_BOOL_INF, $1.variable, $3.variable, NULL);
      $$.listquad->label_id = id_label++;
      mips_generate($$.listquad);
    }
    |
    EXPRESSION '>' EXPRESSION
    {
      quad q = quad_concat($1.listquad, $3.listquad);
      $$.listquad = create_quad(q, OP_BOOL_SUP, $1.variable, $3.variable, NULL);
      $$.listquad->label_id = id_label++;
      mips_generate($$.listquad);
    }
    |
    EXPRESSION
    {
      $$.listquad = create_quad(NULL, OP_BOOL_SUP0, $1.variable, NULL, NULL);
      $$.listquad->label_id = id_label++;
      mips_generate($$.listquad);
    }
    ;
  DECLARATIONS:
    INPUT OUTPUT GLOBAL LOCAL
    {
      printf("\n");
      fprintf(stdout, "\t# Initialisation a 0 des variables\n");
      for(int i = 0; i < symbol_table->length && symbol_table->symbol[i]->name != NULL; i++)
      {
        fprintf(stdout, "\tli $t0,0\n");
        fprintf(stdout, "\tsw $t0,%s\n", symbol_table->symbol[i]->name);
      }
      printf("\n");
    }
    ;

  INPUT:
    {} |
    INPUT_DECLARATION '{' '$' LIST_VARS '$' '}'

  OUTPUT:
    {} |
    OUTPUT_DECLARATION '{' '$' LIST_VARS '$' '}'

  GLOBAL:
    {} |
    GLOBAL_DECLARATION '{' '$' LIST_VARS '$' '}'

  LOCAL:
    {} |
    LOCAL_DECLARATION '{' '$' LIST_VARS '$' '}'

  LIST_VARS:
    VARIABLE ',' LIST_VARS { $$ = $1; }
    |
    VARIABLE { }
    ;

  VARIABLE:
    ID IN_KEY TYPE_KEY { $$->name = strdup($1);
                         $$->type = $3;
                         // on ajoute l'element dans la table des symboles s'il n'est pas existant
                         symbol s = search($$->name, symbol_table);
                         if(s == NULL)
                         {
                            add_to_symbol_array($$, symbol_table);
                            //all_quad = create_quad(all_quad, OP_INIT_VAR, NULL , NULL, $$);
                         }
                         else
                         {
                           fprintf(stderr, "Erreur ligne : %d la variable %s est deja utilise !\n",yylineno, s->name);
                           exit(3);
                         }
                       }
    |
    ID IN_KEY TYPE_KEY '^' '{' NUMBER '}' {
                         $$->name = strdup($1);
                         $$->type = $3;
                         $$->unit = VECTOR;
                         $$->vector.size = $6->value.int_value;
                         // on ajoute l'element dans la table des symboles s'il n'est pas existant
                         symbol s = search($$->name, symbol_table);
                         if(s == NULL)
                         {
                            add_to_symbol_array($$, symbol_table);
                            //all_quad = create_quad(all_quad, OP_INIT_VAR, NULL , NULL, $$);
                         }
                         else
                         {
                           fprintf(stderr, "Erreur ligne : %d la variable %s est deja utilise !\n",yylineno, s->name);
                           exit(3);
                         }
                       }
    ;
%%

int main(int argc, char* argv[]) {
  if (argc == 2) {
    if ((yyin = fopen(argv[1], "r")) == NULL) {
      fprintf(stderr, "[texcc] error: unable to open file %s\n", argv[1]);
      exit(TEXCC_ERROR_GENERAL);
    }
  } else {
    fprintf(stderr, "[texcc] usage: %s input_file\n", argv[0]);
    exit(TEXCC_ERROR_GENERAL);
  }

  id_label = 0;
  symbol_table = (symbol_array)malloc(sizeof(s_symbol_array));
  symbol_table->length = 0;
  memset(symbol_table->symbol, 0, sizeof symbol_table->symbol);
  all_quad = init_quad();
  yyparse();

  FILE * fp;
	fp = fopen ("mips.s", "w+");
	if (fp == NULL) {
	  perror("mips.s");
	  exit(EXIT_FAILURE);
	}

  fclose(yyin);

  //print_quad(all_quad);

  texcc_lexer_free();
  return EXIT_SUCCESS;
}
