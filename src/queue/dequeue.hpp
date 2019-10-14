#include "link.h"
#include <exception>


#ifndef __DE_QUEUE__
#define __DE_QUEUE__

template <typename T>
class DeQueue {
private:
    Link<T> * front, *rear;
    int size;
public:
    void clear() {
        while (front != nullptr) {
            Link<T> * tmp = front;
            front = front->next;
            delete tmp;
        }
        size = 0;
        front = rear = nullptr;
    }

    T & getFront();
    T & getrear();
    bool rpush(const T& item);
    bool lpush(const T& item);
    bool rpop();
    bool lpop();
};


#endif