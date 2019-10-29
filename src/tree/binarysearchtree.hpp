#include "binarytree.hpp"

template <typename T>
class BinarySearchTree : public BinaryTree<T> {
public:
    void InsertNode(BinaryTreeNode<T>* root, BinaryTreeNode<T>* newpointer);
    void DeleteNodeEx(BinaryTreeNode<T> * pointer);
    void Initialize(BinaryTreeNode<T>* pointer);
};

template <typename T>
void BinarySearchTree<T>::InsertNode(BinaryTreeNode<T>* root, BinaryTreeNode<T>* newpointer) {
    if (root == nullptr) {
        Initialize(newpointer);
        return
    }

    BinaryTreeNode<T>* pointer = root;
    while(pointer != nullptr) {
        if (newpointer->value() == pointer->value()){
            return;
        }

        if (newpointer->value() < pointer->value()) {
            if (pointer->leftChild() == nullptr) {
                pointer->left = newpointer;
                return
            } else {
                pointer = pointer->leftChild();
            }
        } else {
            if (pointer->rightChild() == nullptr) {
                pointer->right = pointer;
                return
            } else {
                pointer = pointer->rightChild();
            }
        }
    }
}

template <typename T>
void BinarySearchTree<T>::DeleteNodeEx(BinaryTreeNode<T> * pointer) {
    
}