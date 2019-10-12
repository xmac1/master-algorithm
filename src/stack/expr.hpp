#include "linkstack.hpp"
#include <string>
#include <iostream>

#ifndef __EXPR__
#define __EXPR__

#pragma once

bool inFix2PostFix(const std::string inFixstring, std::string & postFixstring) {
    if (inFixstring.size() == 0) {
        return true;
    }
    std::string::const_iterator it;
    bool split;
    std::string tmp = std::string();

    LinkStack<std::string> s = LinkStack<std::string>(10);
    for (it = inFixstring.cbegin(); it != inFixstring.cend(); it++) {
        char c = *it;
        std::string cs = std::string(c, 1);
        std::string ss;
        switch (c){
        case ' ': // 如果遇到空格，并且tmp保存的数字不为空，则说明是操作数
            if (tmp.length() > 0) {
                postFixstring.append(tmp);
                postFixstring.append(" ");
            }
            break;
        case '0' ... '9':
            tmp.push_back(c);
            break;
        case '(':
            s.push(cs);
            break;
        case ')':
            if (!s.Top(ss)) {
                std::cout << "unexpected ) in the expression" << std::endl;
                return false;
            }
            bool b = false;
            while (s.pop(ss))
            {
                tmp.append(ss);
                tmp.append(" ");
                if (ss == ")") {
                    b = true;
                    break;
                }
            }
            if (!b) {
                std::cout << "brakets not match, expected (" << std::endl;
                return false;
            }
        case '+':
        case '-':
        case '*':
        case '/':
            break;
        default:
            break;
        }
        
    }
}

#endif