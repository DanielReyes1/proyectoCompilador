%code requires {
    #include <vector>
    #include <utility>
    #include <string>
    #include "ast.h"   
}

%{
#include <iostream>
#include <cstdlib>
#include <vector>       
#include "ast.h"
void yyerror(const char *s);
int yylex(void);
std::vector<Function*>* programa = nullptr;
%}


%union {
    int num;
    double fval;
    char* id;

    Expr* expr;
    Stmt* stmt;
    std::vector<Stmt*>* stmt_list;
    std::vector<Expr*>* expr_list;
    Function* function;
    std::vector<Function*>* function_list;
    std::vector<std::pair<std::string,std::string>>* param_list;
    std::pair<std::string,std::string>* param;
    char* type_str;
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

%type <function_list> function_list
%type <function> function
%type <param_list> param_list param_list_nonempty
%type <param> param
%type <stmt_list> stmt_list
%type <stmt> stmt
%type <expr> expr
%type <expr_list> arg_list arg_list_nonempty
%type <type_str> type

%%

program:
      function_list
      {
          programa = $1;  // Guardamos la lista de funciones en la variable global
      }
;


function_list:
      function_list function { $1->push_back($2); $$ = $1; }
    | function { $$ = new std::vector<Function*>(); $$->push_back($1); }
;

function:
      FN IDENTIFIER LPAREN param_list RPAREN ARROW type LBRACE stmt_list RBRACE
      {
          Function* f = new Function();
          f->name = $2;             
          f->params = *$4;          
          delete $4;                
          f->ret_type = $7;         
          f->body = *$9;            
          delete $9;                
          $$ = f;
      }
    | FN IDENTIFIER LPAREN param_list RPAREN LBRACE stmt_list RBRACE
      {
          Function* f = new Function();
          f->name = $2;
          f->params = *$4;          
          delete $4;
          f->ret_type = "";         
          f->body = *$7;
          delete $7;
          $$ = f;
      }
;

param_list:
      { $$ = new std::vector<std::pair<std::string,std::string>>(); }
    | param_list_nonempty { $$ = $1; }
;


param_list_nonempty:
      param
    {
        $$ = new std::vector<std::pair<std::string,std::string>>();
        $$->push_back(*$1);
        delete $1;
    }
    | param_list_nonempty COMMA param
    {
        $$ = $1;
        $$->push_back(*$3);
        delete $3;
    }
;


param:
    IDENTIFIER COLON type
    {
        std::cout << "Parámetro: " << $1 << std::endl;
        // Crear par<string,string> y devolverlo para agregar al vector
        $$ = new std::pair<std::string,std::string>($1, $3);
        free($1);
    }
;


stmt_list:
      stmt_list stmt { $$ = $1; $$->push_back($2); }
    | stmt { $$ = new std::vector<Stmt*>(); $$->push_back($1); }
;


stmt:
      LET IDENTIFIER ASSIGN expr SEMICOLON
      { $$ = new Stmt($2, $4); }
    | RETURN expr SEMICOLON
      { $$ = new Stmt(nullptr, $2); } // return con valor
    | RETURN SEMICOLON
      { $$ = new Stmt(nullptr, nullptr); } // return vacío
;


expr:
      NUMBER 
        { $$ = new Expr(); $$->kind = Expr::INT; $$->int_val = $1; }
    | FLOAT  
        { $$ = new Expr(); $$->kind = Expr::FLOAT; $$->float_val = $1; }
    | IDENTIFIER 
        { $$ = new Expr(); $$->kind = Expr::VAR; $$->var_name = $1; }
    | IDENTIFIER LPAREN arg_list RPAREN
        { $$ = new Expr(); $$->kind = Expr::CALL; $$->call.callee = $1; $$->call.args = $3; }
    | expr PLUS expr
        { $$ = new Expr(); $$->kind = Expr::BINOP; $$->binop.left = $1; $$->binop.op = "+"; $$->binop.right = $3; }
    | expr MINUS expr
        { $$ = new Expr(); $$->kind = Expr::BINOP; $$->binop.left = $1; $$->binop.op = "-"; $$->binop.right = $3; }
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
