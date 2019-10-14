template <typename T>
class Queue {
public:
    void clear();
    bool enQueue(const T item);
    bool deQueue();
    T & getFront();
    T & getBack();
    bool isEmpty();
    bool isFull();
    int size();
};