%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "include/symbol_array.h"
  #define TEXCC_ERROR_GENERAL 4


  // Functions and global variables provided by Lex.
  int yylex();
  void texcc_lexer_free();
  extern FILE* yyin;
  extern int yylineno;
  extern char* yytext;

  symbol_array symbol_table;
  void yyerror(char* s)
  {
    printf("Ligne %d: %s sur le token : %s\n", yylineno, s, yytext);
  }
%}

%union {
  char* name;
  symbol variable;
  enum TYPE type;
}

%token TEXSCI_BEGIN TEXSCI_END BLANKLINE


%token INPUT_DECLARATION OUTPUT_DECLARATION GLOBAL_DECLARATION LOCAL_DECLARATION
%token IN_KEY
%token <type> TYPE_KEY

%token <name> ID
%token <name> ID_VARS

%type <variable> VARIABLE LIST_VARS

%%

algorithm_list:
    algorithm_list algorithm
  | algorithm
  ;

algorithm:
    TEXSCI_BEGIN '{' ID '}' DECLARATIONS BLANKLINE TEXSCI_END
    {
      fprintf(stderr, "[texcc] info: algorithm \"%s\" parsed\n", $3);
      print_symbol_table(symbol_table, $3);
      free($3);
    }
    ;

  DECLARATIONS:
    INPUT OUTPUT GLOBAL LOCAL
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
    ID IN_KEY TYPE_KEY { $$.name = strdup($1);
                         $$.type = $3;
                         // on ajoute l'element dans la table des symboles s'il n'est pas existant
                         symbol s = search($$, symbol_table);
                         if(s.name == NULL)
                            add_to_symbol_array($$, symbol_table);
                         else
                         {
                           fprintf(stderr, "Erreur ligne : %d la variable %s est deja utilise !\n",yylineno, s.name);
                           exit(1);
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
  symbol_table = (symbol_array)malloc(sizeof(s_symbol_array));
  symbol_table->length = 0;
  memset(symbol_table->symbol, 0, sizeof symbol_table->symbol);

  yyparse();
  fclose(yyin);
  texcc_lexer_free();
  return EXIT_SUCCESS;
}
