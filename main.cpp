#include <iostream>
/*
    BISON
    https://www.gnu.org/software/bison/
 */
extern int yyparse();

int main() {
    std::cout << "==== Iniciando parser ====" << std::endl;
    int res = yyparse();
    if(res == 0) {
        std::cout << "Archivo sintácticamente correcto ✅" << std::endl;
    } else {
        std::cout << "Errores de sintaxis ❌" << std::endl;
    }
    std::cout << "==== Fin del parseo ====" << std::endl;
    return res;
}
