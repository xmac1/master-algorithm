#include "list.hpp"
#include <iostream>

int main() {
    ArrList<int> myList = ArrList<int>(1);
    if (!myList.insert(0,1)) {
        std::cout << __FILE__ << ":" << __LINE__ << ": " <<  "insert fail" << std::endl;
        return 0;
    }
    if (!myList.insert(1, 2)) {
        std::cout << __FILE__ << ":" << __LINE__ << ": " <<  "insert fail" << std::endl;
        return 0;
    }
    int p;
    myList.getPos(p, 2);
    std::cout << "position of 2: " << p << std::endl;
}