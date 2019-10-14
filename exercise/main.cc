#include <iostream>
#include "linkstack.hpp"
#include "expr.hpp"
#include <string>

int main() {
    std::string inFix = "33 * ((24 + 25) / (34 * 2))";
    std::string postFix = std::string();
    bool b = inFix2PostFix(inFix, postFix);
    if (b) {
        std::cout << "post fix expression: " << postFix << std::endl;
    } 
    return 0;
}