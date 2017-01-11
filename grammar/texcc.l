%{
  #include <stdlib.h>
  #include <string.h>
  #include "include/symbol_array.h"
  #include "include/quad.h"
  #include "y.tab.h"
%}
%option yylineno
%s texsci

integer		[0-9]+
letters [a-zA-Z]
space ""


begin     "\\begin{texsci}"
end       "\\end{texsci}"
blankline "\\BlankLine"

input     "\\Input"
output    "\\Output"
global    "\\Global"
local     "\\Local"
in        "\\in"
if        "\\If"
emptyset  "\\emptyset"
type_int      "\\Integer"
type_real     "\\Real"
commentaire "\\tcc{".*"}"
affectation   "\\leftarrow"
mbox "\\mbox"
printInt "printInt"
id        [a-zA-Z_][a-zA-Z0-9_]*

symbole       ","|"$"|"+"|"("|")"|"*"|"-"|"="


%%

{begin}             { BEGIN(texsci);   // Start TexSci scanning mode
                      return TEXSCI_BEGIN;
                    }
<texsci>{end}       { BEGIN(INITIAL); // Reset to default scanning mode
                      return TEXSCI_END;
		    }
<texsci>{printInt}  {return PRINT_INT;}
<texsci>{id}        { yylval.name = strdup(yytext);
                        return ID;
                      }
<texsci>{in}        { return IN_KEY; }
<texsci>{type_int}  {
                      yylval.type = INT_TYPE;
                      return TYPE_KEY;
                    }
<texsci>{type_real} {
                      yylval.type = REAL_TYPE;
                      return TYPE_KEY;
                    }

<texsci>{input}     {
                      yylval.variable = (symbol)malloc(sizeof(s_symbol));
                      yylval.variable->address = NULL;
                      yylval.variable->scope = SCOPE_INPUT;
                      return INPUT_DECLARATION;
                    }
<texsci>{output}    {
yylval.variable =     (symbol)malloc(sizeof(s_symbol));
yylval.variable->address = NULL;
                      yylval.variable->scope = SCOPE_OUTPUT;
                      return OUTPUT_DECLARATION;
                    }
<texsci>{global}    {
yylval.variable =     (symbol)malloc(sizeof(s_symbol));
yylval.variable->address = NULL;
                      yylval.variable->scope = SCOPE_GLOBAL;
                      return GLOBAL_DECLARATION;
                    }
<texsci>{local}     {
yylval.variable =     (symbol)malloc(sizeof(s_symbol));
yylval.variable->address = NULL;
                      yylval.variable->scope = SCOPE_LOCAL;
                      return LOCAL_DECLARATION;
                    }
<texsci>{integer}   {
yylval.variable =     (symbol)malloc(sizeof(s_symbol));
yylval.variable->address = NULL;
                      yylval.variable->value.int_value = atoi(yytext);
                      yylval.variable->isconst = TRUE;
                      yylval.variable->type = INT_TYPE;
                      yylval.variable->scope = SCOPE_LOCAL;
                      yylval.variable->unit = SCALAR;
                      yylval.variable->name = strcat(strdup("tmp_"), yytext);
                      return NUMBER;}
<texsci>{symbole}   { return yytext[0]; }
<texsci>{blankline} { return BLANKLINE; }
<texsci>[{}]        { return yytext[0]; }
<texsci>{commentaire} {}
<texsci>{affectation} { return AFFECTATION; }

<texsci>{mbox}        {return MBOX;}
<texsci>{if}          {return IF;}


.                   { }
[\t\n ]             { }

%%

/**
 * texcc_lexer_free function:
 * this function frees the memory allocated for the lexer. It frees
 * flex's buffer (it supposes there is only one buffer) since flex does
 * never free it itself.
 */
void texcc_lexer_free() {
  yy_delete_buffer(YY_CURRENT_BUFFER);
  free(yy_buffer_stack);
}
