#include "binarytree.hpp"
#include "minheap.hpp"

template <typename T>
class HuffmanTreeNode : public BinaryTreeNode<T> {
public:
    BinaryTreeNode<T> * parent;
};

template <typename T>
class HuffmanTree {
private:
    HuffmanTreeNode<T> * root;
    void MergeTree(HuffmanTreeNode<T> & ht1, HuffmanTreeNode<T> & ht2, HuffmanTreeNode<T> * parent);
    void DeleteTree(HuffmanTreeNode<T> * root);
public:
    HuffmanTree(T weight[], int n);
    virtual ~HuffmanTree() {DeleteTree(root);};
};

template <typename T>
HuffmanTree<T>::HuffmanTree(T weigh[], int n) {
    MinHeap<T> heap = MinHeap<T>(n);
    HuffmanTreeNode<T> *parent, firstchild, secondchild;
    HuffmanTreeNode<T> * nodeList = new HuffmanTreeNode<T>[n];
    for (int i=0; i < n; i++) {
        nodeList[i].value = weigh[i];
        nodeList[i].parent = nodeList[i].leftChild = nodeList[i].rightChild = nullptr;
        heap.Insert(weigh[i]);
    }
    for (int i = o; i < n-1; i++) {
        parent = new HuffmanTreeNode<T>();
        firstchild = heap.RemoveMin();
        secondchild = heap.RemoveMin();
        MergeTree(firstchild, secondchild, parent);
        heap.Insert(parent);
        root = parent;
    }
    delete [] nodeList;
}