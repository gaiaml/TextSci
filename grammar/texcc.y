%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "include/symbol_array.h"
  #include "include/quad.h"
  #define TEXCC_ERROR_GENERAL 4


  // Functions and global variables provided by Lex.
  int yylex();
  int id_label;
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
}

%token TEXSCI_BEGIN TEXSCI_END BLANKLINE
%token AFFECTATION

%token MBOX PRINT_INT

%token INPUT_DECLARATION OUTPUT_DECLARATION GLOBAL_DECLARATION LOCAL_DECLARATION
%token IN_KEY
%token IF
%token <type> TYPE_KEY

%token <name> ID
%token <name> ID_VARS


%token <variable> NUMBER
%type <variable> VARIABLE LIST_VARS EXPRESSION

%right AFFECTATION
%left '+' '-'
%left '*'

%%

algorithm_list:
    algorithm_list algorithm
  | algorithm
  ;

algorithm:
    TEXSCI_BEGIN '{' ID '}' DECLARATIONS BLANKLINE LIST_CODE TEXSCI_END
    {
      fprintf(stderr, "[texcc] info: algorithm \"%s\" parsed\n", $3);


      //print_symbol_table(symbol_table, $3);
      free($3);
    }
    ;

  LIST_CODE:
      LIST_CODE CODE
      | CODE
  CODE:
    {}
    |
    '$' ID AFFECTATION EXPRESSION '$'
    {
      symbol s = search($2, symbol_table);
      if(s != NULL )
      {
        if(s->type != $4->type)
        {
          fprintf(stderr, "Erreur de typage ligne : %d entre %s et %s!\n",yylineno, s->name, $4->name);
          exit(3);
        }
        all_quad = create_quad(all_quad, OP_AFFEC, $4 , NULL,s);

      }
      else
      {
        fprintf(stderr, "Erreur ligne : %d la variable %s n'est pas declare !\n",yylineno, $2);
        exit(3);
      }
    }
    |
    EXPRESSION
    {
    }
    |
    FUNCTION
    ;

  FUNCTION:
    '$' MBOX '{' PRINT_INT '(' '$' EXPRESSION '$' ')'  '}' '$'
    {
      all_quad = create_quad(all_quad, PRINT_INTEGER, NULL, NULL, $7);
    }
    ;
  EXPRESSION:
    EXPRESSION '+' EXPRESSION
    {
      symbol res = (symbol)malloc(sizeof(s_symbol));
      res->name = strdup("tmp_res");
      res->is_tmp = TRUE;
      res->address = strdup("$t0");
      res->type = $1->type;
      // verification du type
      if($1->type == $3->type)
      {
        all_quad = create_quad(all_quad, OP_PLUS, $1,$3, res);
        $$ = res;
      }
      else
      {
        fprintf(stderr, "Erreur de typage ligne : %d entre %s et %s!\n",yylineno, $1->name, $3->name);
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
      res->type = $1->type;
      // verification du type
      if($1->type == $3->type)
      {
        all_quad = create_quad(all_quad, OP_TIMES, $1,$3, res);
        $$ = res;
      }
      else
      {
        fprintf(stderr, "Erreur de typage ligne : %d entre %s et %s!\n",yylineno, $1->name, $3->name);
        exit(3);
      }
    }
    |
    '('EXPRESSION ')' { $$ = $2; }
    |
    NUMBER { // ajout dans la table des symboles;
              $1->isconst = TRUE;
              $$ = add_to_symbol_array($1, symbol_table);
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
      $$ = s;
    }
    |
    IF '{' '$' BOOL_EXPR '$' '}'
    {
      printf("MATCH BOOL_EXPR\n");
    }

    ;
  BOOL_EXPR:
    EXPRESSION '=' EXPRESSION
    {
      all_quad = create_quad(all_quad, OP_BOOL_EQUAL, $1, $3, NULL);
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
                            all_quad = create_quad(all_quad, OP_INIT_VAR, NULL , NULL, $$);
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
  fprintf(stdout, ".data\n");
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
