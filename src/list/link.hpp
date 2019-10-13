#ifndef __LINK__
#define __LINK__

#pragma once

template <typename T>
class Link {
public:
    T data;
    Link<T> * next;
    Link(const T info, Link<T> * nextValue = nullptr) {
        data = info;
        next = nextValue;
    }

    Link(const Link<T>* nextValue) {
        next = nextValue;
    }

    T getData() {
        return data;
    }

    Link<T> * getNext() {
        return next;
    }
};

#endif // __LINK__