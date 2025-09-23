#ifndef AST_H
#define AST_H

#include <string>
#include <vector>
#include <utility>
#include <iostream>

//EXPR
struct Expr {
    enum Kind { INT, FLOAT, BOOL, CHAR, STRING, VAR, CALL, BINOP, UNOP, ASSIGN } kind;
    
    int int_val;
    double float_val;
    bool bool_val;
    char char_val;
    char* string_val;
    char* var_name;
    Expr* rhs;
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

    struct UnOp {               
        std::string op;
        Expr* operand;
        UnOp() : op(""), operand(nullptr) {}
    } unop;

    Expr() : kind(INT), int_val(0), float_val(0.0), bool_val(false),
             char_val(0), string_val(nullptr), var_name(nullptr) {}
    void print() {
        switch(kind) {
            case INT: std::cout << int_val; break;
            case FLOAT: std::cout << float_val; break;
            case VAR: std::cout << var_name; break;
            case BOOL: std::cout << (bool_val ? "true" : "false"); break;
            case ASSIGN:
                std::cout << var_name << " = ";
                if(rhs) rhs->print();
                break;
            case BINOP:
                binop.left->print();
                std::cout << " " << binop.op << " ";
                binop.right->print();
                break;
            case UNOP:
                std::cout << unop.op;
                unop.operand->print();
                break;
            case CALL:
                std::cout << call.callee << "(";
                for (size_t i = 0; i < call.args->size(); i++) {
                    (*call.args)[i]->print();
                    if (i + 1 < call.args->size()) std::cout << ", ";
                }
                std::cout << ")";
                break;
            default: std::cout << "?"; break;
        }
}

};

//STMT
struct Stmt {
    char* var_name;
    Expr* value;

    virtual ~Stmt() {}         
    virtual void print() = 0;   
    Stmt() : var_name(nullptr), value(nullptr) {}
    Stmt(char* n, Expr* v) : var_name(n), value(v) {}
};

struct StmtIf : public Stmt {
    Expr* cond;                        
    std::vector<Stmt*>* then_block;   
    std::vector<Stmt*>* else_block;   

    StmtIf(Expr* c, std::vector<Stmt*>* t, std::vector<Stmt*>* e)
        : cond(c), then_block(t), else_block(e) {}
    void print() override {
        std::cout << "if ";
        cond->print();              
        std::cout << " {\n";

        for (auto stmt : *then_block) 
            stmt->print();

        std::cout << "}";

        if (else_block) {
            std::cout << " else {\n";
            for (auto stmt : *else_block)
                stmt->print();
            std::cout << "}";
        }

        std::cout << "\n";
    }
};

struct StmtWhile : Stmt {
    Expr* cond;
    std::vector<Stmt*>* body;

    // Constructor por valor
    StmtWhile(Expr* c, std::vector<Stmt*>* b) : cond(c), body(b) {}

    void print() override {
        std::cout << "while ";
        cond->print();
        std::cout << " {\n";
        for(auto s : *body) s->print();
        std::cout << "}\n";
    }
};



struct StmtFor : public Stmt {
    std::string var;
    Expr* iter;
    std::vector<Stmt*>* body;

    StmtFor(const char* v, Expr* i, std::vector<Stmt*>* b)
        : var(v), iter(i), body(b) {}

    void print() override {
        std::cout << "for " << var << " in ";
        iter->print();
        std::cout << " {\n";
        for (auto stmt : *body) stmt->print();
        std::cout << "}\n";
    }
};

struct StmtExpr : public Stmt {
    Expr* expr;
    StmtExpr(Expr* e) : expr(e) {}

    void print() override {
        expr->print();
        std::cout << ";\n";
    }
};


struct StmtEmpty : public Stmt {
    void print() override {
    }
};

struct StmtBlock : public Stmt {
    std::vector<Stmt*>* stmts;
    StmtBlock(std::vector<Stmt*>* s) : stmts(s) {}
    void print() override {
        std::cout << "{\n";
        for (auto stmt : *stmts) {
            stmt->print();
        }
        std::cout << "}\n";
    }
};

struct StmtLet : Stmt {
    const char* type;  
    std::string type_name;
    StmtLet(char* n, Expr* v, const char* t = nullptr, std::string tn = "") {
        var_name = n;
        value = v;
        type = t;
        type_name = tn;
    }
    void print() override {
        std::cout << "let " << var_name;
        if (type) std::cout << ": " << type;
        std::cout << " = ";
        if (value) value->print();
        std::cout << ";\n";
    }
};


struct StmtReturn : Stmt {
    StmtReturn(Expr* v) { value = v; }
    void print() override {
        std::cout << "return";
        if (value) { std::cout << " "; value->print(); }
        std::cout << ";\n";
    }
};


//FUNCTION
struct Function {
    std::string name; 
    std::vector<std::pair<std::string, std::string>> params; 
    std::string ret_type; 
    std::vector<Stmt*> body; 

    void print() {
        std::cout << "fn " << name << "(";
        for (size_t i = 0; i < params.size(); ++i) {
            std::cout << params[i].first << ": " << params[i].second;
            if (i + 1 < params.size()) std::cout << ", ";
        }
        std::cout << ")";
        if (!ret_type.empty())
            std::cout << " -> " << ret_type;
        std::cout << " {\n";

        for (auto stmt : body)
            stmt->print();   

        std::cout << "}\n";
    }
};


#endif
