#include <stack>
#include <string>
#include <iostream>
#include <vector>

#ifndef __EXPR__
#define __EXPR__

#pragma once

class token {
public:
    enum type {
        constant,
        symbol
    };
    std::string  value;
    type t;
    token(std::string v, type t) :value(v), t(t) {}
    token(char c, type t) : value(1,c), t(t) {}
    token(std::string v) :value(v), t(type::constant){}
    token(std::string v, int holder) : value(v), t(type::symbol){}
    token(char c): value(1,c), t(type::constant){}
    token(char c, int holder) : value(1,c), t(type::symbol){}
};

static std::vector<token> parseString2Token(const std::string inFixstring) {
    std::vector<token> exprVec = std::vector<token>();
    std::string elem = std::string();

    for (std::string::const_iterator it = inFixstring.cbegin(); it != inFixstring.cend(); it++) {
        switch (*it){
        case '0' ... '9':
            elem.push_back(*it);
            break;
        case '+':
        case '-':
        case '/':
        case '*':
        case '(':
        case ')': 
            if (elem.length() > 0) {
                exprVec.push_back(elem);
                elem.clear();
            }

            exprVec.push_back(token(*it, token::type::symbol));
        
            break;
        case ' ':
            if (elem.length() > 0) {
                exprVec.push_back(elem);
                elem.clear();
            }
        default:
            break;
        }
    }
    if (elem.length() > 0) {
        exprVec.push_back(elem);
        elem.clear();
    }
    return exprVec;
}

bool inFix2PostFix(const std::string inFixstring, std::string & postFixstring) {
    if (inFixstring.size() == 0) {
        return true;
    }

    std::vector<token> tokenVec = parseString2Token(inFixstring);
    std::vector<std::string> out = std::vector<std::string>();
    std::stack<std::string> stk = std::stack<std::string>();
    for (auto & tk : tokenVec) {
        switch (tk.t)
        {
        case token::type::symbol:
            if (tk.value == "(") {
                stk.push(tk.value);
            } else if (tk.value == ")") {
                while(stk.size() > 0 && stk.top() != "(") {
                    out.push_back(stk.top());
                    stk.pop();
                }
                if (stk.top() == "(") {
                    stk.pop();
                } else {
                    std::cout << "expected ( in the stack" << std::endl;
                    return false;
                }
            } else {
                while (stk.size() > 0 && stk.top() != "(" && 
                (stk.top() == "*" || stk.top()=="/" || tk.value == "+" || tk.value == "-"))
                {
                    out.push_back(stk.top());
                    stk.pop();
                }
                stk.push(tk.value);
            }
            break;
        case token::type::constant:
            out.push_back(tk.value);
            break;
        default:
            break;
        }
    }

    for(; stk.size() > 0;  stk.pop()) {
        if (stk.top() == "(") {
            std::cout << "unexpected (" << std::endl;
            return false;
        }
    out.push_back(stk.top());
    }

    for (auto & s : out) {
        postFixstring.append(s);
        postFixstring.append(" ");
    }
    return true;
}


// 2 + 5 * 6 / (4 * (6 + 2)) => 2 5 6 * 4 6 * 2 + / +

#endif