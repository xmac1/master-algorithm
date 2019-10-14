#include <stack>
#include <iostream>

long factorial(long n) {
    long m = 1;
    for (long i = 1; i <= n; i++)
    {
        m = m * i;
    }
    return m;
    
}

long factorial_stack(long n) {
    std::stack<long> stk = std::stack<long>();
    long m = 1;
    while(n > 0) {
        stk.push(n--);
    }
    while(stk.size() > 0) {
        m = m * stk.top();
        stk.pop();
    }
    return m;
}