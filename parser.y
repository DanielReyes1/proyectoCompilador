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
    const char* type_str;
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
          programa = $1; 
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
        $$ = new std::pair<std::string,std::string>($1, $3);
        free($1);
    }
;


stmt_list:
      /* vacío */             { $$ = new std::vector<Stmt*>(); }
    | stmt_list stmt          { $1->push_back($2); $$ = $1; }
    | stmt                    { $$ = new std::vector<Stmt*>(); $$->push_back($1); }
;

stmt:
      LET IDENTIFIER ASSIGN expr SEMICOLON
        { $$ = new StmtLet($2, $4, nullptr, ""); }

    | LET IDENTIFIER COLON type ASSIGN expr SEMICOLON
        { $$ = new StmtLet($2, $6, $4, $4); }

    | RETURN expr SEMICOLON
        { $$ = new StmtReturn($2); }

    | RETURN SEMICOLON
        { $$ = new StmtReturn(nullptr); }

    | IF expr LBRACE stmt_list RBRACE
        { $$ = new StmtIf($2, $4, new std::vector<Stmt*>()); }    

    | IF expr LBRACE stmt_list RBRACE ELSE LBRACE stmt_list RBRACE
        { $$ = new StmtIf($2, $4, $8); }

    | WHILE expr LBRACE stmt_list RBRACE
        { $$ = new StmtWhile($2, $4); }

    | FOR IDENTIFIER IN expr LBRACE stmt_list RBRACE
        { $$ = new StmtFor($2, $4, $6); }

    | IDENTIFIER ASSIGN expr SEMICOLON
        {
            Expr* assign_expr = new Expr();
            assign_expr->kind = Expr::ASSIGN;
            assign_expr->var_name = $1;
            assign_expr->rhs = $3;
            $$ = new StmtExpr(assign_expr);
        }

    | expr SEMICOLON
        { $$ = new StmtExpr($1); }

    | LBRACE stmt_list RBRACE
        { $$ = new StmtBlock($2); }

;


expr:
      NUMBER 
        { $$ = new Expr(); $$->kind = Expr::INT; $$->int_val = $1; }

    | FLOAT  
        { $$ = new Expr(); $$->kind = Expr::FLOAT; $$->float_val = $1; }

    | TRUE   
        { $$ = new Expr(); $$->kind = Expr::BOOL; $$->bool_val = true; }

    | FALSE  
        { $$ = new Expr(); $$->kind = Expr::BOOL; $$->bool_val = false; }
    
    | CHAR_LITERAL 
        { $$ = new Expr(); $$->kind = Expr::CHAR; $$->char_val = $1[0]; }
    
    | STRING_LITERAL 
        { $$ = new Expr(); $$->kind = Expr::STRING; $$->string_val = $1; }

    | IDENTIFIER 
        { $$ = new Expr(); $$->kind = Expr::VAR; $$->var_name = $1; }

    | IDENTIFIER LPAREN arg_list RPAREN
        { $$ = new Expr(); $$->kind = Expr::CALL; $$->call.callee = $1; $$->call.args = $3; }

    | expr PLUS expr
        { $$ = new Expr(); $$->kind = Expr::BINOP; $$->binop.left = $1; $$->binop.op = "+"; $$->binop.right = $3; }

    | expr MINUS expr
        { $$ = new Expr(); $$->kind = Expr::BINOP; $$->binop.left = $1; $$->binop.op = "-"; $$->binop.right = $3; }

    | expr MULT expr
        { $$ = new Expr(); $$->kind = Expr::BINOP; $$->binop.left = $1; $$->binop.op = "*"; $$->binop.right = $3; }

    | expr DIV expr
        { $$ = new Expr(); $$->kind = Expr::BINOP; $$->binop.left = $1; $$->binop.op = "/"; $$->binop.right = $3; }

    | expr AND expr
        { $$ = new Expr(); $$->kind = Expr::BINOP; $$->binop.left = $1; $$->binop.op = "&&"; $$->binop.right = $3; }

    | expr OR expr
        { $$ = new Expr(); $$->kind = Expr::BINOP; $$->binop.left = $1; $$->binop.op = "||"; $$->binop.right = $3; }

    | expr EQ expr
        { $$ = new Expr(); $$->kind = Expr::BINOP; $$->binop.left = $1; $$->binop.op = "=="; $$->binop.right = $3; }

    | expr NEQ expr
        { $$ = new Expr(); $$->kind = Expr::BINOP; $$->binop.left = $1; $$->binop.op = "!="; $$->binop.right = $3; }

    | expr LT expr
        { $$ = new Expr(); $$->kind = Expr::BINOP; $$->binop.left = $1; $$->binop.op = "<"; $$->binop.right = $3; }

    | expr GT expr
        { $$ = new Expr(); $$->kind = Expr::BINOP; $$->binop.left = $1; $$->binop.op = ">"; $$->binop.right = $3; }

    | expr LEQ expr
        { $$ = new Expr(); $$->kind = Expr::BINOP; $$->binop.left = $1; $$->binop.op = "<="; $$->binop.right = $3; }

    | expr GEQ expr
        { $$ = new Expr(); $$->kind = Expr::BINOP; $$->binop.left = $1; $$->binop.op = ">="; $$->binop.right = $3; }

    | NOT expr
        { $$ = new Expr(); $$->kind = Expr::UNOP; $$->unop.op = "!"; $$->unop.operand = $2; }

    | LPAREN expr RPAREN
        { $$ = $2; }
;





arg_list:
      /* vacío */ 
        { $$ = new std::vector<Expr*>(); }
    | arg_list_nonempty 
        { $$ = $1; }
;

arg_list_nonempty:
      expr
        { $$ = new std::vector<Expr*>(); $$->push_back($1); }
    | arg_list_nonempty COMMA expr
        { $1->push_back($3); $$ = $1; }
;

type:
      I32   { $$ = "i32"; }
    | F64   { $$ = "f64"; }
    | BOOL  { $$ = "bool"; }
    | CHAR  { $$ = "char"; }
    | STR   { $$ = "str"; }
;

%%

void yyerror(const char *s) {
    std::cerr << "Error de sintaxis: " << s << std::endl;
}
