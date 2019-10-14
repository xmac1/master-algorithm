#include "linkqueue.hpp"
#include <iostream>

using namespace std;

int main() {
    LinkQueue<int> qu = LinkQueue<int>(10);

    qu.enQueue(1);
    qu.enQueue(2);
    qu.enQueue(3);
    qu.enQueue(4);
    qu.enQueue(5);

    while (!qu.isEmpty())
    {
        cout << qu.getFront() << " ";
        qu.deQueue();
    }
    cout << endl;
    try
    {
        cout << qu.getFront() << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "catch exception: " << e.what() << '\n';
    }
    
    
    return 0;
}