#ifndef RB_NODE_H__
#define RB_NODE_H__

#include <iostream>

#define RED true
#define BLACK false

template <typename T>
class rbTree;

template <typename T>
class rbNode
{
    friend class rbTree<T>;

public:
    rbNode(T data, rbNode<T> *sentinel);

    rbNode<T> *getParent();
    void setParent(rbNode<T> *newParent);

    rbNode<T> *getLeft();
    void setLeft(rbNode<T> *newLeft);

    rbNode<T> *getRight();
    void setRight(rbNode<T> *newRight);

    bool getColor();
    void setColor(bool color);

    T getData();
    void recolor();

private:
    T data;         // informação do nó
    rbNode *parent; // ponteiro para o  pai
    rbNode *left;   // ponteiro para o filho esquerdo
    rbNode *right;  // ponteiro para o filho direito
    bool color;     // cor do nó
};

template <typename T>
rbNode<T>::rbNode(T data, rbNode<T> *sentinel)
{
    this->data = data;
    this->color = RED;
    this->left = sentinel;
    this->right = sentinel;
    this->parent = sentinel;
}

template <typename T>
T rbNode<T>::getData()
{
    return data;
}

template <typename T>
rbNode<T> *rbNode<T>::getLeft()
{
    return left;
}

template <typename T>
rbNode<T> *rbNode<T>::getRight()
{
    return right;
}

template <typename T>
rbNode<T> *rbNode<T>::getParent()
{
    return parent;
}

template <typename T>
bool rbNode<T>::getColor()
{
    return color;
}

template <typename T>
void rbNode<T>::setColor(bool newColor)
{
    this->color = newColor;
}

template <typename T>
void rbNode<T>::recolor()
{
    this->color = !color;
}

template <typename T>
void rbNode<T>::setLeft(rbNode<T> *newLeft)
{
    this->left = left;
}

template <typename T>
void rbNode<T>::setRight(rbNode<T> *newRight)
{
    this->right = right;
}

template <typename T>
void rbNode<T>::setParent(rbNode<T> *newParent)
{
    this->parent = newParent;
}

#endif /* RB_NODE_H__ */