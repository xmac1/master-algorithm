#include "list.hpp"
#include "link.hpp"

#ifndef __LINK_LIST__
#define __LINK_LIST__

template <typename T>
class LinkList : public List<T> {
private: 
    Link<T> * head, *tail;
    Link<T> * setPos(const int p);
public:
    LinkList(int size);
    ~LinkList();

    bool isEmpty();
    bool append(const T value);
    bool clear();
    int length();
    bool insert(const int p, const T value);
    bool Delete(const int p);
    bool getValue(const int p, T& value);
    bool getPos(int &p, const T value);
};

template <typename T>
LinkList<T>::LinkList(int size) {
    head = tail = new Link<T>;
}

template <class T>
LinkList<T>::~LinkList() {
    Link<T> * tmp;
    while (head != nullptr) {
        tmp = head;
        head = head ->next;
        delete = tmp;
    }
}

template <typename T>
Link<T>* LinkList<T>::setPos(const int p) {
    if (p == -1) {
        return head;
    }
    int count = 0;
    Link<T>* p =  new Link<T>(head->next);
    while (p != nullptr && count < i) {
        p = p->next;
        count++;
    }
    return p;
}

#endif // __LINK_LIST__