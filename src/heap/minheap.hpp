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