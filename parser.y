%{
#include <iostream>
#include <stdlib.h>
void yyerror(const char *s);
int yylex(void);
%}

%union {
    int num;
    double fval;
    char* id;
}

%token <id> IDENTIFIER STRING_LITERAL CHAR_LITERAL
%token <num> NUMBER TRUE FALSE
%token <fval> FLOAT
%token LET FN IF ELSE WHILE FOR IN RETURN
%token I32 F64 BOOL CHAR STR
%token ASSIGN PLUS MINUS MULT DIV AND OR NOT
%token LPAREN RPAREN LBRACE RBRACE SEMICOLON COMMA
%token EQ NEQ LEQ GEQ LT GT COLON ARROW

%left OR
%left AND
%left PLUS MINUS
%left MULT DIV
%right NOT
%left EQ NEQ LT GT LEQ GEQ   
%right ASSIGN

%%

program:
    function_list
;

function_list:
      function_list function
    | function
;

function:
    FN IDENTIFIER LPAREN param_list RPAREN ARROW type LBRACE stmt_list RBRACE
        { std::cout << "Función con retorno: " << $2 << std::endl; free($2); }
    | FN IDENTIFIER LPAREN param_list RPAREN LBRACE stmt_list RBRACE
        { std::cout << "Función sin retorno: " << $2 << std::endl; free($2); }
;

param_list:
    /* vacío */
    | param_list_nonempty
;

param_list_nonempty:
      param
    | param_list_nonempty COMMA IDENTIFIER
;

param:
    IDENTIFIER COLON type
    { std::cout << "Parámetro: " << $1 << std::endl; free($1); }
;

stmt_list:
      stmt_list stmt
    | stmt
;

stmt:
      LET IDENTIFIER ASSIGN expr SEMICOLON
        { std::cout << "Declaración de variable con asignación: " << $2 << std::endl; free($2); }
    | LET IDENTIFIER COLON type ASSIGN expr SEMICOLON
        { std::cout << "Declaración con tipo y asignación: " << $2 << std::endl; free($2); }
    | LET IDENTIFIER SEMICOLON
        { std::cout << "Declaración de variable sin asignación: " << $2 << std::endl; free($2); }
    | RETURN expr SEMICOLON
        { std::cout << "Return con valor\n"; }
    | RETURN SEMICOLON
        { std::cout << "Return vacío\n"; }
    | IF expr LBRACE stmt_list RBRACE ELSE LBRACE stmt_list RBRACE
        { std::cout << "If-Else encontrado\n"; }
    | WHILE expr LBRACE stmt_list RBRACE
        { std::cout << "While encontrado\n"; }
    | FOR LPAREN IDENTIFIER IN expr RPAREN LBRACE stmt_list RBRACE
        { std::cout << "For encontrado con variable: " << $3 << std::endl; free($3); }
    | expr SEMICOLON
        { std::cout << "Expresión evaluada\n"; }
    | LBRACE stmt_list RBRACE
        { std::cout << "Bloque independiente\n"; }
;

expr:
      expr PLUS expr
    | expr MINUS expr
    | expr MULT expr
    | expr DIV expr
    | expr AND expr
    | expr OR expr
    | expr EQ expr
    | expr NEQ expr
    | expr LT expr
    | expr GT expr
    | expr LEQ expr
    | expr GEQ expr
    | IDENTIFIER ASSIGN expr        
    | NOT expr
    | NUMBER
    | FLOAT
    | TRUE
    | FALSE
    | CHAR_LITERAL
    | STRING_LITERAL
    | IDENTIFIER
    | IDENTIFIER LPAREN arg_list RPAREN
        { std::cout << "Llamada a función: " << $1 << std::endl; free($1); }
    | LPAREN expr RPAREN
;

arg_list:
      /* vacío */
    | arg_list_nonempty
;

arg_list_nonempty:
      expr
    | arg_list_nonempty COMMA expr
;

type:
      IDENTIFIER
    | I32
    | F64
    | BOOL
    | CHAR
    | STR
;

%%

void yyerror(const char *s) {
    std::cerr << "Error de sintaxis: " << s << std::endl;
}
