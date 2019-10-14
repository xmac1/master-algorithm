#include <iostream>
#include "queue.hpp"
#include "link.hpp"
#include <exception>

#ifndef __LINK_QUEUE__
#define __LINK_QUEUE__

#pragma once

template <typename T>
class LinkQueue : public Queue<T> {
private:
    int size;
    Link<T> * front;
    Link<T> * rear;

public:
    LinkQueue(int): size(0), front(nullptr), rear(nullptr){}
    void clear() {
        while (front != rear) {
            Link<T> * tmp = front;
            front = front->next;
            delete tmp;
        }
    }

    bool enQueue(const T item) {
        if (front == nullptr) {
            front = rear = new Link<T>(item);
        } else {
            rear->next = new Link<T>(item);
            rear = rear->next;
        }
        size++;
        return true;
    }

    bool deQueue() {
        if (rear == nullptr) {
            std::cout << "empty queue" << std::endl;
            throw std::logic_error("empty queue");
        }
        Link<T> * tmp = front;
        front = front->next;
        delete tmp;
        if (front == nullptr) {
            rear = nullptr;
        }
        size--;
        return true;
    }

    T & getFront() {
        if (front == nullptr) {
            throw std::logic_error("empty queue");
        }
        return front->data;
    }

    bool isEmpty() {
        return size == 0;
    }
};

#endif