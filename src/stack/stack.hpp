template <typename T>
class Stack {
    void clear();
    bool push(const T item);
    bool pop(T& item);
    bool top(T& item);
    bool isEmpty();
    bool isFull();  
};