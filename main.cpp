#include <iostream>
#include <vector>
#include "ast.h"

/* BISON */
extern int yyparse();
extern std::vector<Function*>* programa;

// Función para imprimir el árbol completo (Expr dentro de Stmt)
void print_stmt_tree(Stmt* s, int indent = 0) {
    if (!s) return;

    std::string pad(indent, ' '); // Indentación
    // Detectamos StmtBlock para aumentar indentación recursiva
    if (auto block = dynamic_cast<StmtBlock*>(s)) {
        std::cout << pad << "{\n";
        for (auto stmt : *block->stmts)
            print_stmt_tree(stmt, indent + 4);
        std::cout << pad << "}\n";
    } else if (auto ifstmt = dynamic_cast<StmtIf*>(s)) {
        std::cout << pad << "if (";
        ifstmt->cond->print();
        std::cout << ") ";
        print_stmt_tree(new StmtBlock(ifstmt->then_block), indent); // imprime bloque then
        if (ifstmt->else_block && !ifstmt->else_block->empty()) {
            std::cout << pad << "else ";
            print_stmt_tree(new StmtBlock(ifstmt->else_block), indent);
        }
    } else if (auto whilestmt = dynamic_cast<StmtWhile*>(s)) {
        std::cout << pad << "while (";
        whilestmt->cond->print();
        std::cout << ") ";
        print_stmt_tree(new StmtBlock(whilestmt->body), indent);
    } else if (auto forstmt = dynamic_cast<StmtFor*>(s)) {
        std::cout << pad << "for " << forstmt->var << " in ";
        forstmt->iter->print();
        std::cout << " ";
        print_stmt_tree(new StmtBlock(forstmt->body), indent);
    } else if (auto exprstmt = dynamic_cast<StmtExpr*>(s)) {
        std::cout << pad;
        exprstmt->expr->print();
        std::cout << ";\n";
    } else if (auto letstmt = dynamic_cast<StmtLet*>(s)) {
        std::cout << pad << "let " << letstmt->var_name;
        if (!letstmt->type_name.empty())
            std::cout << ": " << letstmt->type_name;
        std::cout << " = ";
        letstmt->value->print();
        std::cout << ";\n";
    } else if (auto retstmt = dynamic_cast<StmtReturn*>(s)) {
        std::cout << pad << "return";
        if (retstmt->value) {
            std::cout << " ";
            retstmt->value->print();
        }
        std::cout << ";\n";
    } else {
        s->print(); // fallback
    }
}

// Imprime la función completa
void print_function_tree(Function* f) {
    if (!f) return;
    std::cout << "fn " << f->name << "(";
    for (size_t i = 0; i < f->params.size(); ++i) {
        std::cout << f->params[i].first << ": " << f->params[i].second;
        if (i + 1 < f->params.size()) std::cout << ", ";
    }
    std::cout << ")";
    if (!f->ret_type.empty()) std::cout << " -> " << f->ret_type;
    std::cout << " {\n";
    for (Stmt* s : f->body)
        print_stmt_tree(s, 4);
    std::cout << "}\n";
}

int main() {
    std::cout << "-------------------Iniciando parseo-------------------" << std::endl;
    int res = yyparse();

    if (res == 0) {
        std::cout << "Archivo sintácticamente correcto ✅" << std::endl;
        if (programa) {
            for (Function* f : *programa)
                print_function_tree(f);
        }
    } else {
        std::cout << "Error de sintaxis ❌" << std::endl;
    }
    
    return res;
}
