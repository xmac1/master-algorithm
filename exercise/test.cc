#include <iostream>

using namespace std;

struct node
{
    int data;
    node* next = nullptr;
    node(){}
    ~node(){next = nullptr;}
    node(int d, node* n) : data(d), next(n){}
};


void f(node* & n) {
    n = new node(3, nullptr);
}

void print(node* & n) {
    while (n != nullptr)
    {
        cout << n->data << " ";
        n = n->next;
    
    }
    cout << endl;
}

int main() {
    node* nd = new node(1, nullptr);
    nd->next = new node(2, nullptr);
    print(nd);
    f(nd);
    print(nd);
}