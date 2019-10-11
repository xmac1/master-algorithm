#ifndef __LINK__
#define __LINK__

#pragma once

template <typename T>
class Link {
private:
    T data;
    Link<T> * next;
public:
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