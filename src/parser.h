//
//  Parser.h
//  语法分析
//
//  Created by 李昱 on 2018/6/4.
//  Copyright © 2018年 李昱. All rights reserved.
//

#ifndef PARSER_H
#define PARSER_H

#include <fstream>
#include <iostream>
#include <string>
#include "compiler.h"
#include "scaner.h"

using std::fstream;
using std::string;

class Parser {
public:
    Parser(fstream& _source) : scaner(_source){};
    Parser(Parser&) = delete;
    
    void parse();
    void print(shared_ptr<Node> root, int indent = 0);
    
    shared_ptr<Node> root;
    
private:
    Scaner scaner;
    Token curtToken;
    bool hasError;
    
    void checkAndGet() { curtToken = scaner.getToken(); }
    void checkAndGet(TokenType type) {
        if (curtToken.type != type)
            syntaxError("syntax error");
        else
            curtToken = scaner.getToken();
    }
    
    Node* declaration_list();
    Node* declaration();
    Node* params();
    Node* param_list(Node* node);
    Node* param(Node* node);
    Node* compound_stmt();
    Node* local_declaration();
    Node* statement_list();
    Node* statement();
    Node* expression_stmt();
    Node* selection_stmt();
    Node* iteration_stmt();
    Node* return_stmt();
    Node* expression();
    Node* simple_expression(Node* node);
    Node* additive_expression(Node* node);
    Node* term(Node* node);
    Node* factor(Node* node);
    Node* var();
    Node* call(Node* node);
    Node* args();
    Node* arg_list();
    
    void syntaxError(string msg) {
        std::cout << msg << std::endl;
        hasError = true;
    }
};

#endif
