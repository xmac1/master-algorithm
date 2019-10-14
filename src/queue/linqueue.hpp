#include <iostream>
#include "queue.hpp"
#include "link.hpp"

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
};

#endif