%{
#include "parser.tab.h"
#include <stdlib.h>
#include <string.h>
%}

%%
"fn"        { return FN; }
"let"       { return LET; }
"if"        { return IF; }
"else"      { return ELSE; }
"while"     { return WHILE; }
"return"    { return RETURN; }
"for"       { return FOR; }
"in"        { return IN; }
"mut"       { return MUT; }
"i32"       { return I32; }
"f64"       { return F64; }
"bool"      { return BOOL; }
"char"      { return CHAR; }
"str"       { return STR; }
"="         { return ASSIGN; }
"true"      { yylval.num = 1; return TRUE; }
"false"     { yylval.num = 0; return FALSE; }


[a-zA-Z_][a-zA-Z0-9_]*   { yylval.id = strdup(yytext); return IDENTIFIER; }
[0-9]+\.[0-9]+          { yylval.fval = atof(yytext); return FLOAT; }
[0-9]+                  { yylval.num = atoi(yytext); return NUMBER; }
\'([^\'\\]|\\.)\'       { yylval.id = strdup(yytext); return CHAR_LITERAL; }
\"([^\"\\]|\\.)*\"      { yylval.id = strdup(yytext); return STRING_LITERAL; }

"//".*      {  }

"+"     { return PLUS; }
"-"     { return MINUS; }
"*"     { return MULT; }
"/"     { return DIV; }
"&&"    { return AND; }
"||"    { return OR; }
"!"     { return NOT; }
"("     { return LPAREN; }
")"     { return RPAREN; }
"{"     { return LBRACE; }
"}"     { return RBRACE; }
";"     { return SEMICOLON; }
","     { return COMMA; }
"=="    { return EQ; }
"!="    { return NEQ; }
"<="    { return LEQ; }
">="    { return GEQ; }
"<"     { return LT; }
">"     { return GT; }
"%"     { return MOD;}
":"     { return COLON; }
"->"    { return ARROW; }

[ \t\n]+    ;   
\r          ;   
.           { printf("Caracter no reconocido: '%c'\n", yytext[0]); }

%%
int yywrap() {
    return 1; 
}