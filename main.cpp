#include <iostream>
#include <vector>
#include "ast.h"

/* BISON */
extern int yyparse();
extern std::vector<Function*>* programa;

// Expande print_expr para todos los tipos
void print_expr(Expr* e) {
    if (!e) return;

    switch(e->kind) {
        case Expr::INT:
            std::cout << e->int_val;
            break;
        case Expr::FLOAT:
            std::cout << e->float_val;
            break;
        case Expr::VAR:
            std::cout << e->var_name;
            break;
        case Expr::CALL:
            std::cout << e->call.callee << "(";
            for (size_t i = 0; i < e->call.args->size(); ++i) {
                print_expr((*e->call.args)[i]);
                if (i + 1 < e->call.args->size()) std::cout << ", ";
            }
            std::cout << ")";
            break;
        case Expr::BINOP:
            std::cout << "(";
            print_expr(e->binop.left);
            std::cout << " " << e->binop.op << " ";
            print_expr(e->binop.right);
            std::cout << ")";
            break;
        case Expr::UNOP:
            std::cout << "(" << e->unop.op;
            print_expr(e->unop.operand);
            std::cout << ")";
            break;
        case Expr::BOOL:
            std::cout << (e->bool_val ? "true" : "false");
            break;
        case Expr::CHAR:
            std::cout << "'" << e->char_val << "'";
            break;
        case Expr::STRING:
            std::cout << "\"" << e->string_val << "\"";
            break;
        default:
            break;
    }
}

// Ahora print_stmt solo llama al método virtual
void print_stmt(Stmt* s) {
    if (!s) return;
    s->print();
}

// Función para imprimir funciones completas
void print_function(Function* f) {
    if (!f) return;
    std::cout << "fn " << f->name << "(";
    for (size_t i = 0; i < f->params.size(); ++i) {
        std::cout << f->params[i].first << ": " << f->params[i].second;
        if (i + 1 < f->params.size()) std::cout << ", ";
    }
    std::cout << ")";
    if (!f->ret_type.empty()) std::cout << " -> " << f->ret_type;
    std::cout << " {\n";
    for (Stmt* s : f->body) print_stmt(s);
    std::cout << "}\n";
}

int main() {
    std::cout << "==== Iniciando parser ====" << std::endl;
    int res = yyparse();

    if (res == 0) {
        std::cout << "Archivo sintácticamente correcto ✅" << std::endl;
        if (programa) {
            for (Function* f : *programa)
                print_function(f);
        }
    } else {
        std::cout << "Errores de sintaxis ❌" << std::endl;
    }

    std::cout << "==== Fin del parseo ====" << std::endl;
    return res;
}
