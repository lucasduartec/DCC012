#ifndef RB_TREE_H
#define RB_TREE_H

#include <iostream>

#include "rb_node.h"

template <typename T>
class rbTree
{
public:
    rbTree();
    ~rbTree();

    void insert(T data);
    void remove(T data);
    void clearTree();
    void printTree();
    void printInOrder();
    T minData();
    T maxData();

    rbNode<T> *search(T data);

    int getComparisons();
    void resetComparisons();

    int getRotations();
    void resetRotations();

    int getNSearchComparisons();
    void resetNSearchComparisons();

private:
    rbNode<T> *root;
    rbNode<int> *NIL;

    void cleanNode(rbNode<T> *targetNode);
    void leftRotate(rbNode<T> *targetNode);
    void rightRotate(rbNode<T> *targetNode);
    void insertFixup(rbNode<T> *targetNode);
    void deleteFixup(rbNode<T> *targetNode);
    void transplant(rbNode<T> *nodeA, rbNode<T> *nodeB);

    rbNode<T> *minDataPosition();
    rbNode<T> *maxDataPosition();
    rbNode<T> *treeMinimum(rbNode<T> *targetNode);
    rbNode<T> *treeMaximum(rbNode<T> *targetNode);
    rbNode<T> *findNode(T data);

    void auxPrintTree(rbNode<T> *targetNode, const std::string &prefix, bool isLeft, std::ostream &out);
    void auxPrintInOrder(rbNode<T> *targetNode, std::ostream &out);

    int nComparisons;       // número de comparações
    int nRotations;         // número de rotações
    int nSearchComparisons; // número de comparações de busca
};

template <typename T>
rbTree<T>::rbTree()
{
    this->NIL = new rbNode<T>(0, nullptr);
    this->NIL->setColor(BLACK);
    root = NIL;

    nComparisons = 0;
    nRotations = 0;
    nSearchComparisons = 0;
}

template <typename T>
rbTree<T>::~rbTree()
{
    this->cleanNode(root);
    delete this->NIL;
    root = NIL;
}

template <typename T>
void rbTree<T>::insert(T data)
{

    rbNode<T> *y = NIL;
    rbNode<T> *x = root;

    while (x != NIL)
    {
        y = x;

        if (data < x->data)
        {

            x = x->left;
        }
        else
        {

            x = x->right;
        }

        nComparisons++; // Incrementa o número de comparações
    }

    rbNode<T> *newNode = new rbNode<T>(data, NIL);
    newNode->parent = y;

    if (y == NIL)
    {
        root = newNode;
        newNode->setColor(BLACK);
        return;
    }
    else if (newNode->data < y->data)
    {
        y->left = newNode;
    }
    else
    {
        y->right = newNode;
    }
    newNode->left = NIL;
    newNode->right = NIL;
    newNode->color = RED;
    insertFixup(newNode);
}

template <typename T>
void rbTree<T>::transplant(rbNode<T> *nodeA, rbNode<T> *nodeB)
{
    if (nodeA->parent == this->NIL)
    {
        this->root = nodeB;
    }
    else if (nodeA == nodeA->parent->left)
    {
        nodeA->parent->left = nodeB;
    }
    else
    {
        nodeA->parent->right = nodeB;
    }
    nodeB->parent = nodeA->parent;
}

template <typename T>
void rbTree<T>::deleteFixup(rbNode<T> *targetNode)
{
    rbNode<T> *w;
    while (targetNode != this->root && targetNode->color == BLACK)
    {
        if (targetNode == targetNode->parent->left)
        {
            w = targetNode->parent->right;
            if (w->color == RED)
            {
                w->color = BLACK;
                targetNode->parent->color = RED;
                leftRotate(targetNode->parent);
                w = targetNode->parent->right;
            }
            if (w->left->color == BLACK && w->right->color == BLACK)
            {
                w->color = RED;
                targetNode = targetNode->parent;
            }
            else
            {
                if (w->right->color == BLACK)
                {
                    w->left->color = BLACK;
                    w->color = RED;
                    rightRotate(w);
                    w = targetNode->parent->right;
                }
                w->color = targetNode->parent->color;
                targetNode->parent->color = BLACK;
                w->right->color = BLACK;
                leftRotate(targetNode->parent);
                targetNode = this->root;
            }
        }
        else
        {
            w = targetNode->parent->left;
            if (w->color == RED)
            {
                w->color = BLACK;
                targetNode->parent->color = RED;
                rightRotate(targetNode->parent);
                w = targetNode->parent->left;
            }
            if (w->right->color == BLACK && w->left->color == BLACK)
            {
                w->color = RED;
                targetNode = targetNode->parent;
            }
            else
            {
                if (w->left->color == BLACK)
                {
                    w->right->color = BLACK;
                    w->color = RED;
                    leftRotate(w);
                    w = targetNode->parent->left;
                }
                w->color = targetNode->parent->color;
                targetNode->parent->color = BLACK;
                w->left->color = BLACK;
                rightRotate(targetNode->parent);
                targetNode = this->root;
            }
        }
    }
}

template <typename T>
void rbTree<T>::remove(T data)
{

    rbNode<T> *x;
    rbNode<T> *y;
    rbNode<T> *targetNode;
    targetNode = findNode(data);
    y = targetNode;
    bool yOriginalColor = y->color;
    if (targetNode->left == this->NIL)
    {
        x = targetNode->right;
        transplant(targetNode, targetNode->right);
    }
    else if (targetNode->right == this->NIL)
    {
        x = targetNode->left;
        transplant(targetNode, targetNode->left);
    }
    else
    {
        y = treeMinimum(targetNode->right);
        yOriginalColor = y->color;
        x = y->right;
        if (y->parent == targetNode)
        {
            x->parent = y;
        }
        else
        {
            transplant(y, y->right);
            y->right = targetNode->right;
            y->right->parent = y;
        }
        transplant(targetNode, y);
        y->left = targetNode->left;
        y->left->parent = y;
        y->color = targetNode->color;
    }
    if (yOriginalColor == BLACK)
    {
        deleteFixup(x);
    }
}

template <typename T>
void rbTree<T>::clearTree()
{
    this->cleanNode(root);
    root = NIL;
}

template <typename T>
void rbTree<T>::printTree()
{
    auxPrintTree(root, "", false, std::cout);
    std::cout << std::endl;
}

template <typename T>
void rbTree<T>::printInOrder()
{
    auxPrintInOrder(root, std::cout);
    std::cout << std::endl;
}

template <typename T>
rbNode<T> *rbTree<T>::search(T data)
{
    rbNode<T> *foundNode = findNode(data);
    if (foundNode == NIL)
    {
        return NULL;
    }
    else
    {
        return foundNode;
    }
}

template <typename T>
T rbTree<T>::minData()
{
    if (root == NIL)
    {
        return NULL;
    }
    return this->minDataPosition()->data;
}

template <typename T>
T rbTree<T>::maxData()
{
    if (root == NIL)
    {
        return NULL;
    }
    return this->maxDataPosition()->data;
}

template <typename T>
void rbTree<T>::cleanNode(rbNode<T> *node)
{
    if (node == NIL)
    {
        return;
    }
    cleanNode(node->left);
    cleanNode(node->right);
    delete node;
}

template <typename T>
void rbTree<T>::leftRotate(rbNode<T> *targetNode)
{
    nRotations++; // Incrementa o número de rotações

    rbNode<T> *targetRChild = targetNode->right;
    targetNode->right = targetRChild->left;
    if (targetRChild->left != this->NIL)
    {
        targetRChild->left->parent = targetNode;
    }
    targetRChild->parent = targetNode->parent;
    if (targetNode->parent == this->NIL)
    {
        this->root = targetRChild;
    }
    else if (targetNode == targetNode->parent->left)
    {
        targetNode->parent->left = targetRChild;
    }
    else
    {
        targetNode->parent->right = targetRChild;
    }
    targetRChild->left = targetNode;
    targetNode->parent = targetRChild;
}

template <typename T>
void rbTree<T>::rightRotate(rbNode<T> *targetNode)
{
    nRotations++; // Incrementa o número de rotações

    rbNode<T> *targetLChild = targetNode->left;
    targetNode->left = targetLChild->right;
    if (targetLChild->right != this->NIL)
    {
        targetLChild->right->parent = targetNode;
    }
    targetLChild->parent = targetNode->parent;
    if (targetNode->parent == this->NIL)
    {
        this->root = targetLChild;
    }
    else if (targetNode == targetNode->parent->right)
    {
        targetNode->parent->right = targetLChild;
    }
    else
    {
        targetNode->parent->left = targetLChild;
    }
    targetLChild->right = targetNode;
    targetNode->parent = targetLChild;
}

template <typename T>
void rbTree<T>::insertFixup(rbNode<T> *targetNode)
{
    rbNode<T> *uncle;
    while (targetNode->parent->color == RED)
    {
        if (targetNode->parent == targetNode->parent->parent->left)
        {
            uncle = targetNode->parent->parent->right;
            if (uncle->color == RED)
            {
                targetNode->parent->color = BLACK;
                uncle->color = BLACK;
                targetNode->parent->parent->color = RED;
                targetNode = targetNode->parent->parent;
            }
            else
            {
                if (targetNode == targetNode->parent->right)
                {
                    targetNode = targetNode->parent;
                    leftRotate(targetNode);
                }
                targetNode->parent->color = BLACK;
                targetNode->parent->parent->color = RED;
                rightRotate(targetNode->parent->parent);
            }
        }
        else
        {
            uncle = targetNode->parent->parent->left;
            if (uncle->color == RED)
            {
                targetNode->parent->color = BLACK;
                uncle->color = BLACK;
                targetNode->parent->parent->color = RED;
                targetNode = targetNode->parent->parent;
            }
            else
            {
                if (targetNode == targetNode->parent->left)
                {
                    targetNode = targetNode->parent;
                    rightRotate(targetNode);
                }
                targetNode->parent->color = BLACK;
                targetNode->parent->parent->color = RED;
                leftRotate(targetNode->parent->parent);
            }
        }
    }
    this->root->color = BLACK;
}

template <typename T>
rbNode<T> *rbTree<T>::minDataPosition()
{
    rbNode<T> *aux = root;
    while (aux->left != NIL)
    {
        aux = aux->left;
    }
    return aux;
}

template <typename T>
rbNode<T> *rbTree<T>::maxDataPosition()
{
    rbNode<T> *aux = root;
    while (aux->right != NIL)
    {
        aux = aux->right;
    }
    return aux;
}

template <typename T>
rbNode<T> *rbTree<T>::treeMinimum(rbNode<T> *targetNode)
{
    while (targetNode->left != this->NIL)
    {
        targetNode = targetNode->left;
    }
    return targetNode;
}

template <typename T>
rbNode<T> *rbTree<T>::treeMaximum(rbNode<T> *targetNode)
{
    while (targetNode->right != this->NIL)
    {
        targetNode = targetNode->right;
    }
    return targetNode;
}

template <typename T>
rbNode<T> *rbTree<T>::findNode(T data)
{
    rbNode<T> *aux = root;
    while (aux != NIL)
    {
        nSearchComparisons++;
        if (aux->data == data)
        {
            return aux;
        }

        nSearchComparisons++;
        if (data < aux->data)
        {
            aux = aux->left;
        }
        else
        {
            aux = aux->right;
        }
    }
    return aux;
}

template <typename T>
void rbTree<T>::auxPrintTree(rbNode<T> *node, const std::string &prefix, bool isLeft, std::ostream &out)
{

    out << prefix;
    out << (isLeft ? "├──" : "└──");

    if (node == NIL)
    {
        out << "(P.null)" << std::endl;
        return;
    }
    out << (node->color ? "(" : "(") << node->getData() << (node->color ? "-R)" : "-B)") << std::endl;

    auxPrintTree(node->getLeft(), prefix + (isLeft ? "│   " : "    "), true, out);
    auxPrintTree(node->getRight(), prefix + (isLeft ? "│   " : "    "), false, out);
}

template <typename T>
void rbTree<T>::auxPrintInOrder(rbNode<T> *node, std::ostream &out)
{
    if (node == NIL)
    {
        return;
    }
    auxPrintInOrder(node->left, out);
    out << node->data << " ";
    auxPrintInOrder(node->right, out);
}

template <typename T>
int rbTree<T>::getComparisons()
{
    return nComparisons;
}

template <typename T>
void rbTree<T>::resetComparisons()
{
    nComparisons = 0;
}

template <typename T>
int rbTree<T>::getRotations()
{
    return nRotations;
}

template <typename T>
void rbTree<T>::resetRotations()
{
    nRotations = 0;
}

template <typename T>
int rbTree<T>::getNSearchComparisons()
{
    return nSearchComparisons;
}

template <typename T>
void rbTree<T>::resetNSearchComparisons()
{
    nSearchComparisons = 0;
}

#endif /* RB_TREE_H */