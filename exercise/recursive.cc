#include "factorial.hpp"
#include <iostream>

int main() {
    long n = 5;
    long m = factorial(n);
    std::cout << "5! = " << m << std::endl;

    m = factorial_stack(n);
    std::cout << "user stack 5! = " << m << std::endl;
    return 0 ;
}