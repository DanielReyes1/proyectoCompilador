%{
#include <iostream>
using namespace std;

int yylex();                       
int yyerror(const char *s);       
%}


%token FN LET IF ELSE WHILE RETURN
%token IDENTIFIER NUMBER
%token PLUS MINUS MULT DIV
%token LPAREN RPAREN LBRACE RBRACE SEMICOLON

%%
program:
    program function
    | /* vacío */
;

function:
    FN IDENTIFIER LPAREN RPAREN LBRACE stmt_list RBRACE
;

stmt_list:
    stmt_list statement
    | /* vacío */
;

statement:
    LET IDENTIFIER SEMICOLON
    | RETURN NUMBER SEMICOLON
;
%%

int main() {
    return yyparse();
}

int yyerror(const char *s) {
    cerr << "Error sintáctico: " << s << endl;
    return 0;
}
