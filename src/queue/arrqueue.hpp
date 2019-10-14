#include "queue.hpp"
#include <iostream>

#ifndef __ARR_QUEUE__
#define __ARR_QUEUE__

#pragma once

template <typename T>
class ArrQueue : public Queue<T> {
private:
    int mSize;
    int front;
    int rear;
    T *data;
public:
    ArrQueue(int maxSize) : mSize(maxSize),
                             data(new T<maxSize>),
                              front(0), rear(0){}
    ~ArrQueue() {delete [] data};

    void clear() { front = rear;}

    bool enQueue(const T item) {
        if ((rear+1)%mSize == front){
            std::cout << "queue full" << std::endl;
            return false;
        }
        data[rear] = item;
        rear = (rear + 1) % mSize;
        return true;
    }

    bool deQueue() {
        if (front == rear) {
            std::cout << "empty queue" << std::endl;
            return false;
        }
        front = (front + 1) % mSize;
    }

    T& getFront() {
        if (front == rear) {
            std::cout << "empty queue" << std::endl;
            return nullptr;
        }
        return data[front];
    }

    T & getBack() {
        if (front == rear) {
            std::cout << "empty queue" << std::endl;
            return;
        }
        return data[(rear-1)%mSize];
    }

    bool isEmpty() {
        return front == rear; 
    }
};

#endif