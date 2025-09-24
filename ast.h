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
    
    void to_json(int indent = 0) {
        std::string pad(indent, ' ');
        switch(kind) {
            case STRING:
                std::cout << pad << "{\"type\":\"string\",\"value\":\"" << string_val << "\"}";
                break;
            case CHAR:
                std::cout << pad << "{\"type\":\"char\",\"value\":\"" << char_val << "\"}";
                break;
            case INT:
                std::cout << pad << "{\"type\":\"int\",\"value\":" << int_val << "}";
                break;
            case VAR:
                std::cout << pad << "{\"type\":\"var\",\"name\":\"" << var_name << "\"}";
                break;
            case FLOAT:
                std::cout << pad << "{\"type\":\"float\",\"value\":" << float_val << "}";
                break;
            case BOOL:
                std::cout << pad << "{\"type\":\"bool\",\"value\":" << bool_val << "}";
                break;
            case ASSIGN:
                std::cout << pad << "{\n"
                        << pad << "  \"type\": \"Assign\",\n"
                        << pad << "  \"var\": \"" << var_name << "\",\n"
                        << pad << "  \"value\": ";
                if(rhs) rhs->to_json(indent + 4);
                else std::cout << "null";
                std::cout << "\n" << pad << "}";
                break;
            case BINOP:
                std::cout << pad << "{\n"
                        << pad << "  \"type\":\"BinOp\",\n"
                        << pad << "  \"op\":\"" << binop.op << "\",\n"
                        << pad << "  \"left\":";
                binop.left->to_json(indent + 4);
                std::cout << ",\n" << pad << "  \"right\":";
                binop.right->to_json(indent + 4);
                std::cout << "\n" << pad << "}";
                break;
            case CALL:
                std::cout << pad << "{\n"
                        << pad << "  \"type\":\"Call\",\n"
                        << pad << "  \"name\":\"" << call.callee << "\",\n"
                        << pad << "  \"args\":[\n";
                for (size_t i = 0; i < call.args->size(); i++) {
                    (*call.args)[i]->to_json(indent + 4);
                    if (i + 1 < call.args->size()) std::cout << ", \n";
                }
                std::cout << "\n" << pad << "   ]";
                std::cout << "\n" << pad << "}";
                break;
            default:
                std::cout << pad << "{\"type\":\"Unknown\"}";
        }
    }


};

//STMT
struct Stmt {
    char* var_name;
    Expr* value;

    virtual ~Stmt() {}         
    virtual void to_json(int indent = 0) = 0;  
    Stmt() : var_name(nullptr), value(nullptr) {}
    Stmt(char* n, Expr* v) : var_name(n), value(v) {}
};

struct StmtIf : public Stmt {
    Expr* cond;                        
    std::vector<Stmt*>* then_block;   
    std::vector<Stmt*>* else_block;   

    StmtIf(Expr* c, std::vector<Stmt*>* t, std::vector<Stmt*>* e)
        : cond(c), then_block(t), else_block(e) {}

    void to_json(int indent = 0) override {
        std::string pad(indent, ' ');
        std::cout << pad << "{\n"
                << pad << "  \"type\": \"if\",\n"
                << pad << "  \"cond\": ";
        cond->to_json(indent + 4);
        std::cout << ",\n" << pad << "  \"then\": [\n";
        for (size_t i = 0; i < then_block->size(); i++) {
            (*then_block)[i]->to_json(indent + 4);
            if (i + 1 < then_block->size()) std::cout << ",";
            std::cout << "\n";
        }
        std::cout << pad << "  ]";
        if (else_block && !else_block->empty()) {
            std::cout << ",\n" << pad << "  \"else\": [\n";
            for (size_t i = 0; i < else_block->size(); i++) {
                (*else_block)[i]->to_json(indent + 4);
                if (i + 1 < else_block->size()) std::cout << ",";
                std::cout << "\n";
            }
            std::cout << pad << "  ]";
        }
        std::cout << "\n" << pad << "}";
    }
};

struct StmtWhile : Stmt {
    Expr* cond;
    std::vector<Stmt*>* body;

    StmtWhile(Expr* c, std::vector<Stmt*>* b) : cond(c), body(b) {}

    void to_json(int indent = 0) override {
        std::string pad(indent, ' ');
        std::cout << pad << "{\n"
                << pad << "  \"type\": \"while\",\n"
                << pad << "  \"cond\": ";
        cond->to_json(indent + 4);
        std::cout << ",\n" << pad << "  \"body\": [\n";
        for (size_t i = 0; i < body->size(); i++) {
            (*body)[i]->to_json(indent + 4);
            if (i + 1 < body->size()) std::cout << ",";
            std::cout << "\n";
        }
        std::cout << pad << "  ]\n" << pad << "}";
    }
};



struct StmtFor : public Stmt {
    std::string var;
    Expr* iter;
    std::vector<Stmt*>* body;

    StmtFor(const char* v, Expr* i, std::vector<Stmt*>* b)
        : var(v), iter(i), body(b) {}

    void to_json(int indent = 0) override {
        std::string pad(indent, ' ');
        std::cout << pad << "{\n"
                << pad << "  \"type\": \"for\",\n"
                << pad << "  \"var\": \"" << var << "\",\n"
                << pad << "  \"iter\": ";
        iter->to_json(indent + 4);
        std::cout << ",\n" << pad << "  \"body\": [\n";
        for (size_t i = 0; i < body->size(); i++) {
            (*body)[i]->to_json(indent + 4);
            if (i + 1 < body->size()) std::cout << ",";
            std::cout << "\n";
        }
        std::cout << pad << "  ]\n" << pad << "}";
    }
};

struct StmtExpr : public Stmt {
    Expr* expr;
    StmtExpr(Expr* e) : expr(e) {}

    void to_json(int indent = 0) override {
        std::string pad(indent, ' ');
        std::cout << pad << "{\n "
                << pad << " \"type\": \"Expr\",\n"
                << pad << "  \"expr\": ";
        expr->to_json(indent + 2);
        std::cout << "\n" << pad << "}";
    }
};


struct StmtEmpty : public Stmt {
    void to_json(int indent = 0) override {
        std::string pad(indent, ' ');
        std::cout << pad << "{ \"type\": \"Empty\" }";
    }
};

struct StmtBlock : public Stmt {
    std::vector<Stmt*>* stmts;
    StmtBlock(std::vector<Stmt*>* s) : stmts(s) {}
    void to_json(int indent = 0) override {
        std::string pad(indent, ' ');
        std::cout << pad << "{\n"
                << pad << "  \"type\": \"Block\",\n"
                << pad << "  \"stmts\": [\n";
        for (size_t i = 0; i < stmts->size(); i++) {
            (*stmts)[i]->to_json(indent + 4);
            if (i + 1 < stmts->size()) std::cout << ",";
            std::cout << "\n";
        }
        std::cout << pad << "  ]\n" << pad << "}";
    }
};

struct StmtLet : Stmt {
    const char* type;  
    std::string type_name;
    bool is_mutable;
    StmtLet(char* n, Expr* v, const char* t = nullptr, std::string tn = "", bool mutable_flag = false) {
        var_name = n;
        value = v;
        type = t;
        type_name = tn;
        is_mutable = mutable_flag; 
    }
    void to_json(int indent = 0) override {
        std::string pad(indent, ' ');
        std::cout << pad << "{\n"
                << pad << "  \"type\": \"let\",\n"
                << pad << "  \"name\": \"" << var_name << "\"";

        if (is_mutable) {
            std::cout << ",\n" << pad << "  \"mutable\": true";
        }
        if (!type_name.empty()) {
            std::cout << ",\n" << pad << "  \"declared_type\": \"" << type_name << "\"";
        }
        std::cout << ",\n" << pad << "  \"value\": ";
        if (value) value->to_json(indent + 4);
        else std::cout << "null";
        std::cout << "\n" << pad << "}";
    }
};


struct StmtReturn : Stmt {
    StmtReturn(Expr* v) { value = v; }
    void to_json(int indent = 0) override {
        std::string pad(indent, ' ');
        std::cout << pad << "{\n"
                  << pad << "  \"type\": \"return\",\n"
                  << pad << "  \"value\": ";
        if (value) value->to_json(indent + 2);
        else std::cout << "null";
        std::cout << "\n" << pad << "}";
    }
};


//FUNCTION
struct Function {
    std::string name; 
    std::vector<std::pair<std::string, std::string>> params; 
    std::string ret_type; 
    std::vector<Stmt*> body; 

    void to_json(int indent = 0) {
        std::string pad(indent, ' ');
        std::cout << pad << "{\n"
                << pad << "  \"type\":\"function\",\n"
                << pad << "  \"name\":\"" << name << "\",\n"
                << pad << "  \"params\":[";
        for (size_t i = 0; i < params.size(); i++) {
            std::cout << "{\"name\":\"" << params[i].first 
                    << "\",\"type\":\"" << params[i].second << "\"}";
            if (i + 1 < params.size()) std::cout << ",";
        }
        std::cout << "],\n" << pad << "  \"body\":[\n";
        for (size_t i = 0; i < body.size(); i++) {
            body[i]->to_json(indent + 4);
            if (i + 1 < body.size()) std::cout << ",";
            std::cout << "\n";
        }
        std::cout << pad << "  ]\n" << pad << "}";
    }
};


#endif
