%{
#include "parser.tab.h"
%}

%%
"fn"        { return FN; }
"let"       { return LET; }
"if"        { return IF; }
"else"      { return ELSE; }
"while"     { return WHILE; }
"return"    { return RETURN; }

[a-zA-Z_][a-zA-Z0-9_]*   { return IDENTIFIER; }
[0-9]+                  { return NUMBER; }

"+"     { return PLUS; }
"-"     { return MINUS; }
"*"     { return MULT; }
"/"     { return DIV; }

"("     { return LPAREN; }
")"     { return RPAREN; }
"{"     { return LBRACE; }
"}"     { return RBRACE; }
";"     { return SEMICOLON; }

[ \t\n]+    ;   /* ignorar espacios */
%%
int yywrap() {
    return 1; 
}

