%{
  #include <stdlib.h>
  #include <string.h>
  #include "include/symbol_array.h"
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
type_int      "\\Integer"
type_real     "\\Real"


id        [a-zA-Z_][a-zA-Z0-9_]*
symbole       ","|"$"
%%

{begin}             { BEGIN(texsci);   // Start TexSci scanning mode
                      return TEXSCI_BEGIN;
                    }
<texsci>{end}       { BEGIN(INITIAL); // Reset to default scanning mode
                      return TEXSCI_END;
		    }
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
                      yylval.variable.scope = SCOPE_INPUT;
                      return INPUT_DECLARATION;
                    }
<texsci>{output}    {
                      yylval.variable.scope = SCOPE_OUTPUT;
                      return OUTPUT_DECLARATION;
                    }
<texsci>{global}    {
                      yylval.variable.scope = SCOPE_GLOBAL;
                      return GLOBAL_DECLARATION;
                    }
<texsci>{local}     {
                      yylval.variable.scope = SCOPE_LOCAL;
                      return LOCAL_DECLARATION;
                    }

<texsci>{symbole}   { return yytext[0]; }
<texsci>{blankline} { return BLANKLINE; }
<texsci>[{}]        { return yytext[0]; }

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
