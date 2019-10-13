#include <iostream>
#include "linkstack.hpp"
#include "expr.hpp"
#include <string>

int main() {
    std::string inFix = "22 + 5 * 63 / (4 * (6 + 2))";
    std::string postFix = std::string();
    bool b = inFix2PostFix(inFix, postFix);
    if (b) {
        std::cout << "post fix expression: " << postFix << std::endl;
    } 
    return 0;
}