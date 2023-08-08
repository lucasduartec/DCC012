#ifndef B_NODE_H__
#define B_NODE_H__

#include <iostream>

template <typename T>
class bTree;

template <typename T>
class bNode
{
    friend class bTree<T>;

public:
    bNode(int temp, bool bool_leaf);

    void insertNonFull(T data);
    void splitChild(int i, bNode<T> *y);
    void print();

    bNode<T> *search(T data, int &nSearchComparisons);

    void remove(T data);

private:
    int t;        // grau mínimo da árvore
    int n;        // quantidade de chaves armazenadas no nó
    T *keys;      // array de chaves
    bNode<T> **C; // ponteiro para array de ponteiros
    bool leaf;    // flag para indicar se o nó é folha

    void removeFromLeaf(int idx);
    void removeFromNonLeaf(int idx);
    int getPred(int idx);
    int getSucc(int idx);
    void fill(int idx);
    void borrowFromPrev(int idx);
    void borrowFromNext(int idx);
    void merge(int idx);
};

template <typename T>
bNode<T>::bNode(int t, bool leaf)
{
    this->t = t;
    this->n = 0;
    this->keys = new T[2 * t - 1];
    this->C = new bNode<T> *[2 * t];
    this->leaf = leaf;
}

template <typename T>
void bNode<T>::remove(T data)
{
    int idx = 0;
    while (idx < n && keys[idx] < data)
        idx++;

    if (idx < n && keys[idx] == data)
    {
        if (leaf)
            removeFromLeaf(idx);
        else
            removeFromNonLeaf(idx);
    }
    else
    {
        if (leaf)
        {
            std::cout << "Chave " << data << " não encontrada na árvore." << std::endl;
            return;
        }

        bool flag = ((idx == n) ? true : false);

        if (C[idx]->n < t)
            fill(idx);

        if (flag && idx > n)
            C[idx - 1]->remove(data);
        else
            C[idx]->remove(data);
    }
}

template <typename T>
void bNode<T>::removeFromLeaf(int idx)
{
    for (int i = idx + 1; i < n; i++)
        keys[i - 1] = keys[i];

    n--;
}

template <typename T>
void bNode<T>::removeFromNonLeaf(int idx)
{
    int data = keys[idx];

    if (C[idx]->n >= t)
    {
        int pred = getPred(idx);
        keys[idx] = pred;
        C[idx]->remove(pred);
    }
    else if (C[idx + 1]->n >= t)
    {
        int succ = getSucc(idx);
        keys[idx] = succ;
        C[idx + 1]->remove(succ);
    }
    else
    {
        merge(idx);
        C[idx]->remove(data);
    }
}

template <typename T>
int bNode<T>::getPred(int idx)
{
    bNode<T> *current = C[idx];
    while (!current->leaf)
        current = current->C[current->n];

    return current->keys[current->n - 1];
}

template <typename T>
int bNode<T>::getSucc(int idx)
{
    bNode<T> *current = C[idx + 1];
    while (!current->leaf)
        current = current->C[0];

    return current->keys[0];
}

template <typename T>
void bNode<T>::fill(int idx)
{
    if (idx != 0 && C[idx - 1]->n >= t)
        borrowFromPrev(idx);
    else if (idx != n && C[idx + 1]->n >= t)
        borrowFromNext(idx);
    else
    {
        if (idx != n)
            merge(idx);
        else
            merge(idx - 1);
    }
}

template <typename T>
void bNode<T>::borrowFromPrev(int idx)
{
    bNode<T> *child = C[idx];
    bNode<T> *sibling = C[idx - 1];

    for (int i = child->n - 1; i >= 0; i--)
        child->keys[i + 1] = child->keys[i];

    if (!child->leaf)
    {
        for (int i = child->n; i >= 0; i--)
            child->C[i + 1] = child->C[i];
    }

    child->keys[0] = keys[idx - 1];

    if (!child->leaf)
        child->C[0] = sibling->C[sibling->n];

    keys[idx - 1] = sibling->keys[sibling->n - 1];

    child->n++;
    sibling->n--;
}

template <typename T>
void bNode<T>::borrowFromNext(int idx)
{
    bNode<T> *child = C[idx];
    bNode<T> *sibling = C[idx + 1];

    child->keys[child->n] = keys[idx];

    if (!child->leaf)
        child->C[child->n + 1] = sibling->C[0];

    keys[idx] = sibling->keys[0];

    for (int i = 1; i < sibling->n; i++)
        sibling->keys[i - 1] = sibling->keys[i];

    if (!sibling->leaf)
    {
        for (int i = 1; i <= sibling->n; i++)
            sibling->C[i - 1] = sibling->C[i];
    }

    child->n++;
    sibling->n--;
}

template <typename T>
void bNode<T>::merge(int idx)
{
    bNode<T> *child = C[idx];
    bNode<T> *sibling = C[idx + 1];

    child->keys[t - 1] = keys[idx];

    for (int i = 0; i < sibling->n; i++)
        child->keys[i + t] = sibling->keys[i];

    if (!child->leaf)
    {
        for (int i = 0; i <= sibling->n; i++)
            child->C[i + t] = sibling->C[i];
    }

    for (int i = idx + 1; i < n; i++)
        keys[i - 1] = keys[i];

    for (int i = idx + 2; i <= n; i++)
        C[i - 1] = C[i];

    child->n += sibling->n + 1;
    n--;
    delete sibling;
}

template <typename T>
void bNode<T>::print()
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (leaf == false)
            C[i]->print();
        std::cout << keys[i] << " ";
    }

    if (leaf == false)
        C[i]->print();
}

template <typename T>
bNode<T> *bNode<T>::search(T data, int &nSearchComparisons)
{
    int i = 0;
    while (i < n && data > keys[i]){
        i++;
        nSearchComparisons++;
    }

    if (keys[i] == data)
        return this;

    if (leaf == true)
        return NULL;

    return C[i]->search(data, nSearchComparisons);
}

template <typename T>
void bNode<T>::insertNonFull(T data)
{
    int i = n - 1;

    if (leaf == true)
    {
        while (i >= 0 && keys[i] > data)
        {
            keys[i + 1] = keys[i];
            i--;
        }

        keys[i + 1] = data;
        n = n + 1;
    }
    else
    {
        while (i >= 0 && keys[i] > data)
            i--;

        if (C[i + 1]->n == 2 * t - 1)
        {
            splitChild(i + 1, C[i + 1]);

            if (keys[i + 1] < data)
                i++;
        }
        C[i + 1]->insertNonFull(data);
    }
}

template <typename T>
void bNode<T>::splitChild(int i, bNode<T> *y)
{
    bNode<T> *z = new bNode<T>(y->t, y->leaf);
    z->n = t - 1;

    for (int j = 0; j < t - 1; j++)
        z->keys[j] = y->keys[j + t];

    if (y->leaf == false)
    {
        for (int j = 0; j < t; j++)
            z->C[j] = y->C[j + t];
    }

    y->n = t - 1;
    for (int j = n; j >= i + 1; j--)
        C[j + 1] = C[j];

    C[i + 1] = z;

    for (int j = n - 1; j >= i; j--)
        keys[j + 1] = keys[j];

    keys[i] = y->keys[t - 1];
    n = n + 1;
}

#endif /* B_NODE_H__ */
