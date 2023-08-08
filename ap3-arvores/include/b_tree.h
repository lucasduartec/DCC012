#ifndef B_TREE_H
#define B_TREE_H

#include <iostream>

#include "b_node.h"

template <typename T>
class bTree
{

public:
    bTree();
    bTree(int t);

    void setDegree(int t);

    void insert(T data);
    bNode<T> *search(T data);
    void remove(T data);
    void print();
    T GetKey(bNode<T> *node, T searchData);

    int getNSearchComparisons();
    void resetNSearchComparisons();

private:
    bNode<T> *root; // ponteiro para raíz
    int t;          // grau mínimo da árvore

    int nSearchComparisons; // número de comparações de busca
};

template <typename T>
bTree<T>::bTree()
{
}

template <typename T>
bTree<T>::bTree(int t)
{
    root = NULL;
    setDegree(t);
    nSearchComparisons = 0;
}

template <typename T>
void bTree<T>::insert(T data)
{
    if (root == NULL)
    {
        root = new bNode<T>(t, true);
        root->keys[0] = data;
        root->n = 1;
    }
    else
    {
        if (root->n == 2 * t - 1)
        {
            bNode<T> *s = new bNode<T>(t, false);

            s->C[0] = root;

            s->splitChild(0, root);

            int i = 0;
            if (s->keys[0] < data)
                i++;
            s->C[i]->insertNonFull(data);

            root = s;
        }
        else
            root->insertNonFull(data);
    }
}

template <typename T>
bNode<T> *bTree<T>::search(T data)
{

    if (root == NULL)
        return NULL;

    else
        return root->search(data, nSearchComparisons);
}

template <typename T>
void bTree<T>::remove(T data)
{
    if (!root)
    {
        std::cout << "A árvore está vazia." << std::endl;
        return;
    }

    root->remove(data);

    if (root->n == 0)
    {
        bNode<T> *tmp = root;
        if (root->leaf)
            root = NULL;
        else
            root = root->C[0];

        delete tmp;
    }
}

template <typename T>
void bTree<T>::print()
{
    if (root != NULL)
        root->print();
}

template <typename T>
void bTree<T>::setDegree(int t)
{
    this->t = t;
}

template <typename T>
T bTree<T>::GetKey(bNode<T> *node, T searchData)
{
    for (int i = 0; i < node->n; i++)
    {
        if (node->keys[i] == searchData)
        {
            return node->keys[i];
        }
        else if (node->keys[i] > searchData)
        {
            if (!node->leaf)
            {
                return GetKey(node->C[i], searchData);
            }
            else
            {
                break;
            }
        }
    }

    if (!node->leaf)
    {
        return GetKey(node->C[node->n], searchData);
    }

    return T();
}

template <typename T>
int bTree<T>::getNSearchComparisons()
{
    return nSearchComparisons;
}

template <typename T>
void bTree<T>::resetNSearchComparisons()
{
    nSearchComparisons = 0;
}

#endif /* B_TREE_H */