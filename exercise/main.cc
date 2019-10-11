#include <iostream>
#include "linkstack.hpp"

int main() {
    LinkStack<int> s = LinkStack<int>(19);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    int t;
    s.Top(t);
    std::cout << "stack top: " << t << std::endl;
}