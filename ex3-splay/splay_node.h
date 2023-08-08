#ifndef SPLAY_NODE_H__
#define SPLAY_NODE_H__


#include <iostream>
#include <string>
using namespace std;

template <typename T>
class SplayTree;

// Implementa as estruturas de dados necessarias para o splay tree

template <typename T>
class SplayNode
{
    friend class SplayTree<T>;
    public:
        SplayNode(T key);
        SplayNode(T key, SplayNode<T> *left, SplayNode<T> *right);
        SplayNode<T>* getLeft();
        SplayNode<T>* getRight();
        SplayNode<T>* getParent();
        T        getKey();
        void setLeft(SplayNode<T> *left);
        void setRight(SplayNode<T> *right);
        void setKey(T key);
        void setParent(SplayNode<T> *parent);
        
  private:
    T          key;
    SplayNode *left;
    SplayNode *right;
    SplayNode *parent;
};

template <typename T>
SplayNode<T>::SplayNode(T key): key(key), left(nullptr), right(nullptr), parent(nullptr)
{ }

template <typename T>
SplayNode<T>::SplayNode(T key, SplayNode<T> *left, SplayNode<T> *right): key(key), left(left), right(right), parent(nullptr)
{ }

template <typename T>
T SplayNode<T>::getKey()
{
    return key;
}

template <typename T>
SplayNode<T>* SplayNode<T>::getLeft()
{
    return left;
}

template <typename T>
SplayNode<T>* SplayNode<T>::getRight()
{
    return right;
}

template <typename T>
SplayNode<T>* SplayNode<T>::getParent()
{
    return parent;
}

template <typename T>
void SplayNode<T>::setLeft(SplayNode<T> *left)
{
    this->left = left;
}
template <typename T>
void SplayNode<T>::setRight(SplayNode<T> *right)
{
    this->right = right;
}

template <typename T>
void SplayNode<T>::setParent(SplayNode<T> *parent)
{
    this->parent = parent;
}

template <typename T>
void SplayNode<T>::setKey(T key)
{
    this->key = key;
}

#endif /* SPLAY_NODE_H__ */
