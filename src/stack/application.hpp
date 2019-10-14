#include <stack>
#include <vector>
#include <initializer_list>
#include <iterator>
#include <queue>
#include <iostream>

template <typename Iterator>
void choose(std::stack<typename std::iterator_traits<Iterator>::value_type>, std::queue<typename std::iterator_traits<Iterator>::value_type>, Iterator, Iterator);

template <typename T>
int order_count(std::vector<T> arr) {
    if (arr.size() <= 1) {
        return arr.size();
    }

    std::stack<T> s = std::stack<T>();
    
    choose(s, std::queue<T>(), arr.cbegin(), arr.cend());
    return 0;
}

template <typename Iterator>
void choose(std::stack<typename std::iterator_traits<Iterator>::value_type> s, 
            std::queue<typename std::iterator_traits<Iterator>::value_type> out, 
            Iterator begin, 
            Iterator end)
{
    if (begin == end) {
        while(out.size() > 0) {
            std::cout << out.front() << " ";
            out.pop();
        }
        while(s.size() > 0) {
            std::cout << s.top() << " ";
            s.pop();
        }
        std::cout << std::endl;
        return;
    }

    s.push(*begin);
    choose(s, out, begin+1, end);
    s.pop();

    while(s.size() > 0) {
        out.push(s.top());
        s.pop();
        s.push(*begin);
        choose(s, out, begin+1, end);
        s.pop();
    }
}