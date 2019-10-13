#include "stack.hpp"
#include "link.hpp"

#ifndef __LINK_STACK__
#define __LINK_STACK__

#pragma once

template <typename T>
class LinkStack : public Stack<T> {
private:
    Link<T> * top;
    int size;
public:
    LinkStack(int maxSize) {
        top = nullptr;
        size = 0;
    }
    ~LinkStack() {
        clear();
    }
    void clear() {
        while (top != nullptr) {
            Link<T> * tmp = top;
            top = top->getNext();
            delete top;
        }
    }

    bool push(const T value) {
        Link<T> * tmp = new Link<T>(value, top);
        top = tmp;
        size++;
        return true;
    }

    bool pop(T& item) {
        Link<T> * tmp;
        if (size == 0) {
            return false;
        }
        tmp = top->next;
        item = top->data;
        delete top;
        top = tmp;
        size--;
        return true;
    }

    bool Top(T& item) {
        if (size == 0) {
            return false;
        }
        item = top->getData();
        return true;
    }
};

#endif // __LINK_STACK__