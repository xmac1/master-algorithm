#include "binarytree.hpp"

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
    
}