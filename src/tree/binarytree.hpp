#include <stack>
#include <iostream>

template <typename T>
class BinaryTreeNode {
    friend class BinaryTree;
private:
    T info;
public:
    BinaryTreeNode();
    BinaryTreeNode(const T & elem);
    BinaryTreeNode(const T & ele, BinaryTreeNode<T> * l, BinaryTreeNode<T> * r);

    T value() const;
    BinaryTreeNode<T> & leftChild() const;
    BinaryTreeNode<T> & rightChild() const;

    void setLeftChild(BinaryTreeNode<T> *);
    void setRightChild(BinaryTreeNode<T> *);
    void setValue(const T& val);
    bool isLeaf() const;
    BinaryTreeNode<T> & operator=(const BinaryTreeNode<T> & node);
};

template <typename T>
class BinaryTree {
private:
    BinaryTree<T> * root;
public:
    BinaryTree(){root = null;};
    ~BinaryTree(){DeleteBianryTree(root);}
    bool isEmpty();
    BinaryTreeNode<T> * Root() {return root};
    BinaryTreeNode<T> * Parent(BinaryTreeNode<T> * current);
    BinaryTreeNode<T> * LeftSibling(BinaryTreeNode<T> * current);
    BinaryTreeNode<T> * RightSiblling(BinaryTreeNode<T> * current);

    void CreateTree(const T& info, BinaryTree<T> & leftTree, BinaryTree<T> & rightTree);
    void PreOrder(BinaryTreeNode<T> * root);
    void InOrder(BinaryTreeNode<T> * root);
    void PostOrder(BinaryTreeNode<T> * root);
    void LevelOrder(BinaryTreeNode<T> * root);
    void DeleteBianryTree(BinaryTreeNode<T> * root);
    
    void PreOrderWithoutRecursion(BinaryTreeNode<T> * root);
    void InOrderWithoutRecursion(BinaryTreeNode<T> * root);

};

template <typename T>
void BinaryTree<T>::PreOrder(BinaryTreeNode<T>* root) {
    if (root != nullptr) {
        std::cout << root->value << " ";
        PreOrder(root->leftChild());
        PreOrder(root->rightChild());       
    }
}

template <typename T>
void BinaryTree<T>::InOrder(BinaryTreeNode<T>* root) {

    
}

template <typename T>
void BinaryTree<T>::PostOrder(BinaryTreeNode<T>* root) {
    
}

template <typename T>
void BinaryTree<T>::PreOrderWithoutRecursion(BinaryTreeNode<T> * root) {
    using namespace std;
    stack<BinaryTreeNode<T>*> nodeStack = stack<BinaryTreeNode<T>>();
    nodeStack.push(root);
    while(nodeStack.size() > 0) {
        BinaryTreeNode<T> * tmp = nodeStack->top();
        nodeStack->pop();
        cout << tmp->value << endl;
        if (tmp->rightChild() != nullptr) {
            nodeStack.push(tmp->leftChild());
        }
        if (tmp->leftChild() != nullptr) {
            nodeStack.push(tmp->rightChild());
        }
    }
}


template <typename T>
void InOrderWithoutRecursion(BinaryTreeNode<T> * root) {
    using namespace std;
    stack<BinaryTreeNode<T>*> nodeStack = stack<BinaryTreeNode<T>>();
    BinaryTreeNode<T> * pointer = root;
    
    while (nodeStack.size() > 0 || pointer)
    {
        if (pointer) {    
            nodeStack.push(pointer);
            pointer = pointer->leftChild();          
        } else {
            pointer = nodeStack->top(); 
            nodeStack.pop();
            cout << pointer->value << endl;
            pointer = pointer->rightChild();
        }
    }
}

enum Tags {
    Left,
    Right
};

template <typename T>
class StackElemment {
public:
    Tags tag;
    BinaryTreeNode<T> * pointer;
};

template <typename T>
void PostOrderWithoutRecursion(BinaryTreeNode<T> * root) {
    using namespace std;
    stack<StackElemment<T>> nodeStack = stack<StackElemment<T>>();
    BinaryTreeNode<T> * pointer = root;
    StackElemment<T> element;
    while(nodeStack.size() > 0 || pointer) {
        while (pointer)
        {
            element.pointer = pointer;
            element.tag = Left;
            nodeStack.push(element);
            pointer = pointer->leftChild();
        }
        element = nodeStack.top();
        pointer = element.pointer;
        nodeStack.pop();
        if (element.tag == Left) {
            element.tag = Right;
            nodeStack.push(element);
            pointer = pointer->rightChild();
        } else {
            cout << pointer->value << endl;
            pointer = nullptr;
        }
        
    }
}