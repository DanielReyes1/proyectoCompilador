#include <iostream>
#include <vector>
#include "ast.h" 
/*
    BISON
    https://www.gnu.org/software/bison/
 */
extern int yyparse();
extern std::vector<Function*>* programa;

void print_expr(Expr* e) {
    if(!e) return;
    switch(e->kind) {
        case Expr::INT:   std::cout << e->int_val; break;
        case Expr::FLOAT: std::cout << e->float_val; break;
        case Expr::VAR:   std::cout << e->var_name; break;
        case Expr::CALL:
            std::cout << e->call.callee << "(";
            for(size_t i = 0; i < e->call.args->size(); ++i) {
                print_expr((*e->call.args)[i]);
                if(i+1 < e->call.args->size()) std::cout << ", ";
            }
            std::cout << ")";
            break;
        default: break;
    }
}

void print_stmt(Stmt* s) {
    if(!s) return;
    if(s->var_name) std::cout << "let " << s->var_name << " = ";
    print_expr(s->value);
    std::cout << ";" << std::endl;
}

void print_function(Function* f) {
    if(!f) return;
    std::cout << "fn " << f->name << "(";
    for(size_t i = 0; i < f->params.size(); ++i) {
        std::cout << f->params[i].first << ": " << f->params[i].second;
        if(i+1 < f->params.size()) std::cout << ", ";
    }
    std::cout << ")";
    if(!f->ret_type.empty()) std::cout << " -> " << f->ret_type;
    std::cout << " {" << std::endl;
    for(Stmt* s : f->body) print_stmt(s);
    std::cout << "}" << std::endl;
}

int main() {
    std::cout << "==== Iniciando parser ====" << std::endl;
    int res = yyparse();
    if(res == 0) {
        std::cout << "Archivo sintácticamente correcto ✅" << std::endl;
        if(programa) {
            for(Function* f : *programa) print_function(f);
        }
    } else {
        std::cout << "Errores de sintaxis ❌" << std::endl;
    }
    std::cout << "==== Fin del parseo ====" << std::endl;
    return res;
}
