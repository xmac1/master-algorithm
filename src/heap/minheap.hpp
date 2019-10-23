#include <iostream>

template <typename T>
class MinHeap {
private: 
    T * heapArray;
    int CurrentSize;
    int MaxSize;
    void swap(int posX, int posY);
    void BuildHeap();
public:
    MinHeap(const int n);
    virtual ~MinHeap{delete [] heapArray;};
    bool isEmpty();
    bool isLeaf(int pos) const;
    int LeftChild(int pos) const;
    int RightChild(int pos) const;
    int Parent(int pos) const;
    bool Remove(int pos, T& node);
    bool Insert(const T& newNode);
    T& RemoveMin();
    void SiftUp(int position);
    void SiftDown(int left);
};

template <typename T>
MinHeap<T>::MinHeap(const int n) {
    if (n <= 0) {
        return;
    }
    CurrentSize = 0;
    MaxSize = n;
    heapArray = new T[MaxSize];
    BuildHeap();
}

template <typename T>
bool MinHeap<T>::isLeaf(int pos) const {
    return (pos >= CurrentSize / 2) && (pos < CurrentSize);
}

template <typename T>
void MinHeap<T>::BuildHeap() {
    for (int i = CurrentSize/2-1; i>=0; i--) {
        SiftDown(i);
    }
}

template <typename T>
int MinHeap<T>::LeftChild(int pos) const {
    return 2 * pos + 1;
}

template <typename T>
int MinHeap<T>::RightChild(int pos) const {
    return 2 * pos + 2;
}

template <typename T>
int MinHeap<T>::Parent(int pos) const {
    return (pos - 1) / 2;
}

template <typename T>
bool MinHeap<T>::Insert(const T& newNode) {
    if (CurrentSize >= MaxSize) {
        return false;
    }
    heapArray[CurrentSize] = newNode;
    SiftUp(CurrentSize);
    CurrentSize++;
    return true;
}

template <typename T>
T& MinHeap<T>::RemoveMin() {
    if (CurrentSize == 0) {
        std::cout << "can not remove" << std::endl;
        return
    }
    swap(0, --CurrentSize);
    if (CurrentSize > 1) {
        SiftDown(0);
    }
    return heapArray[CurrentSize];
}

template <typename T>
bool MinHeap<T>::Remove(int pos, T& node) {
    if (pos < 0 || pos >= CurrentSize) {
        return false;
    }
    node = heapArray[pos];
    heapArray[pos] = heapArray[--CurrentSize];
    if (heapArray[pos] < heapArray[Parent(pos)]) {
        SiftUp(pos);
    } else {
        SiftDown(pos);
    }
    return true;
}

template <typename T>
void MinHeap<T>::SiftUp(int pos) {
    T value = heapArray[pos];
    int idx = pos;
    while (idx > 0 && headArray[Parent(idx)] > value)
    {
        heapArray[idx] = heapArray[Parent(idx)];
        idx = Parent(idx);
    }
    heapArray[idx] = value;
}

template <typename T>
void MinHeap<T>::SiftDown(int pos) {
    int i = pos;
    int child = LeftChild(i);
    T value = heapArray[pos];
    while (child < CurrentSize)
    {
        if ((child < CurrentSize - 1) && (heapArray[child] < heapArray[child + 1])) {
            child = child + 1;
        }
        if (value > heapArray[child]) {
            heapArray[i] = heapArray[child];
            i = child;
            child = LeftChild(child);
        } else {
            break;
        }
    }
    heapArray[i] = value;
}