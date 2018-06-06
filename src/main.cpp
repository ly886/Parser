//
//  main.cpp
//  语法分析
//
//  Created by 李昱 on 2018/6/5.
//  Copyright © 2018年 李昱. All rights reserved.
//


#include <fstream>
#include <iostream>
#include <string>
#include "compiler.h"
#include "parser.h"
#include "scaner.h"

using std::cout;
using std::endl;
using std::fstream;

int main(int argc, char** argv) {
    fstream source;
    
    if (argc != 2) {
     cout << "usage : parser <filename>" << endl;
     return 0;
     } else {
     source.open(argv[1], std::ios::in);
     if (!source.is_open())
     return 0;
     }
    
    //******warning********
    //如果出现错误情况，极有可能是mac和windows换行符不同的问题
    //请打开终端，cd到测试用例文件目录下，按下列命令修改一下换行符的格式
    //1.vim <filename>
    //2.:%s/\r/\r/g
    
    //source.open("/Users/liyu/Desktop/gcd.cmm",std::ios::in);
    
    Parser parser(source);
    parser.parse();
    parser.print(parser.root);
    return 0;
}
