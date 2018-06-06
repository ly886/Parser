//
//  Header.h
//  语法分析
//
//  Created by 李昱 on 2018/6/4.
//  Copyright © 2018年 李昱. All rights reserved.
//


#ifndef SCANER_H
#define SCANER_H

#include <fstream>
#include <string>
#include "compiler.h"

using std::fstream;
using std::string;

typedef enum {
    START,
    INSLASH,
    INASTERISK1,
    INASTERISK2,
    INID,
    INNUM,
    INSMAL,
    INBIG,
    INEQ,
    INEXCLAM,
    DONE
} STATE;

struct Token {
    string str;
    TokenType type;
};

static Token reservedWords[] = {{"else", ELSE},     {"if", IF},     {"int", INT},
    {"return", RETURN}, {"void", VOID}, {"while", WHILE}};


class Scaner {
public:
    Scaner(fstream &_source) : source(_source) { curt = line.begin(); }
    Scaner(Scaner &) = delete;
    
    Token getToken();
    
private:
    fstream &source;
    string line;
    Token token;
    string::iterator curt;
    
    char getChar();
    void ungetChar();
    TokenType lookupReserved(const Token &t);
};
#endif
