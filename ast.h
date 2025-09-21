#ifndef AST_H
#define AST_H

#include <string>
#include <vector>
#include <utility>

//EXPR
struct Expr {
    enum Kind { INT, FLOAT, BOOL, CHAR, STRING, VAR, CALL, BINOP } kind;
    
    int int_val;
    double float_val;
    bool bool_val;
    char char_val;
    char* string_val;
    char* var_name;

    struct BinOp {
        Expr* left;
        std::string op;
        Expr* right;
        BinOp() : left(nullptr), op(""), right(nullptr) {}
    } binop;

    struct Call {
        char* callee;
        std::vector<Expr*>* args; 
        Call() : callee(nullptr), args(new std::vector<Expr*>()) {}
        ~Call() { 
            delete args; 
        }
    } call;

    Expr() : kind(INT), int_val(0), float_val(0.0), bool_val(false),
             char_val(0), string_val(nullptr), var_name(nullptr) {}
};

//STMT
struct Stmt {
    char* var_name;
    Expr* value;

    Stmt() : var_name(nullptr), value(nullptr) {}
    Stmt(char* n, Expr* v) : var_name(n), value(v) {}
};

//FUNCTION
struct Function {
    std::string name; 
    std::vector<std::pair<std::string, std::string>> params; 
    std::string ret_type; 
    std::vector<Stmt*> body; 

    Function() : name(""), ret_type("") {}
};

#endif
