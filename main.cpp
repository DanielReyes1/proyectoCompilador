#include <iostream>
#include <vector>
#include "ast.h"
/*
    BISON
    https://www.gnu.org/software/bison/
 */
extern int yyparse();
extern std::vector<Function*>* programa;

int main() {
    std::cout << "-------------------Iniciando parseo-------------------" << std::endl;
    int res = yyparse();

    if (res == 0) {
        if (programa) {
            for (Function* f : *programa) {
                f->to_json();
                std::cout << std::endl;
            }
        }
    } else {
        std::cout << "No se pudo compilar" << std::endl;
    }
    
    return res;
}
