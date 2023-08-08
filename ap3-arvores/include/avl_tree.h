#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <iostream>
#include <stack>

using namespace std;

template <typename T>
class avlNode
{
public:
    T data;
    int height;
    avlNode<T> *left;
    avlNode<T> *right;

    avlNode(T data) : data(data), height(1), left(nullptr), right(nullptr) {}
};

template <typename T>
class avlTree
{
private:
    avlNode<T> *root;

    int getHeight(avlNode<T> *node);
    int getBalanceFactor(avlNode<T> *node);
    void updateHeight(avlNode<T> *node);
    avlNode<T> *rotateLeft(avlNode<T> *node);
    avlNode<T> *rotateRight(avlNode<T> *node);
    avlNode<T> *balance(avlNode<T> *node);
    avlNode<T> *insertNode(avlNode<T> *node, T data);
    avlNode<T> *findMinNode(avlNode<T> *node);
    avlNode<T> *removeNode(avlNode<T> *node, T data);

    avlNode<T> *auxSearch(avlNode<T> *node, T data);

    void print_tree(avlNode<T> *node, const std::string &prefix, bool isLeft, std::ostream &out);


    int nComparisons;       // número de comparações
    int nRotations;         // número de rotações
    int nSearchComparisons; // número de comparações de busca

public:
    avlTree();

    void insert(T data);
    void remove(T data);
    void printTree();
    avlNode<T> *search(T data);

    int getComparisons();
    void resetComparisons();

    int getRotations();
    void resetRotations();

    int getNSearchComparisons();
    void resetNSearchComparisons();
};

template <typename T>
avlTree<T>::avlTree()
{
    this->root = nullptr;
    nComparisons = 0;
    nRotations = 0;
    nSearchComparisons = 0;
}

template <typename T>
int avlTree<T>::getHeight(avlNode<T> *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    return node->height;
}

template <typename T>
int avlTree<T>::getBalanceFactor(avlNode<T> *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

template <typename T>
void avlTree<T>::updateHeight(avlNode<T> *node)
{
    if (node == nullptr)
    {
        return;
    }
    node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
}

template <typename T>
avlNode<T> *avlTree<T>::rotateLeft(avlNode<T> *node)
{
    avlNode<T> *newRoot = node->right;
    avlNode<T> *newRootLeft = newRoot->left;

    newRoot->left = node;
    node->right = newRootLeft;

    updateHeight(node);
    updateHeight(newRoot);

    return newRoot;
}

template <typename T>
avlNode<T> *avlTree<T>::rotateRight(avlNode<T> *node)
{
    avlNode<T> *newRoot = node->left;
    avlNode<T> *newRootRight = newRoot->right;

    newRoot->right = node;
    node->left = newRootRight;

    updateHeight(node);
    updateHeight(newRoot);

    return newRoot;
}

template <typename T>
avlNode<T> *avlTree<T>::balance(avlNode<T> *node)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    updateHeight(node);

    int balanceFactor = getBalanceFactor(node);

    if (balanceFactor > 1)
    {
        // Left Left case
        if (getBalanceFactor(node->left) >= 0)
        {
            nRotations++; // Incrementa o número de rotações
            return rotateRight(node);
        }
        // Left Right case
        else
        {
            node->left = rotateLeft(node->left);
            nRotations += 2; // Incrementa o número de rotações
            return rotateRight(node);
        }
    }
    else if (balanceFactor < -1)
    {
        // Right Right case
        if (getBalanceFactor(node->right) <= 0)
        {
            nRotations++; // Incrementa o número de rotações
            return rotateLeft(node);
        }
        // Right Left case
        else
        {
            node->right = rotateRight(node->right);
            nRotations += 2; // Incrementa o número de rotações
            return rotateLeft(node);
        }
    }

    return node;
}

template <typename T>
avlNode<T> *avlTree<T>::insertNode(avlNode<T> *node, T data)
{
    if (node == nullptr)
    {
        return new avlNode<T>(data);
    }

    nComparisons++; // Incrementa o número de comparações

    if (data < node->data)
    {
        node->left = insertNode(node->left, data);
    }
    else if (data > node->data)
    {
        node->right = insertNode(node->right, data);
    }
    else
    {
        // Duplicate keys are not allowed in AVL tree
        return node;
    }

    return balance(node);
}

template <typename T>
avlNode<T> *avlTree<T>::findMinNode(avlNode<T> *node)
{
    if (node == nullptr || node->left == nullptr)
    {
        return node;
    }
    return findMinNode(node->left);
}

template <typename T>
avlNode<T> *avlTree<T>::removeNode(avlNode<T> *node, T data)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    if (data < node->data)
    {
        node->left = removeNode(node->left, data);
    }
    else if (data > node->data)
    {
        node->right = removeNode(node->right, data);
    }
    else
    {

        if (node->left == nullptr || node->right == nullptr)
        {
            avlNode<T> *temp = node->left ? node->left : node->right;

            if (temp == nullptr)
            {
                temp = node;
                node = nullptr;
            }
            else
            {
                *node = *temp;
            }

            delete temp;
        }
        else
        {
            avlNode<T> *successor = findMinNode(node->right);
            node->data = successor->data;
            node->right = removeNode(node->right, successor->data);
        }
    }

    if (node == nullptr)
    {
        return nullptr;
    }

    return balance(node);
}


template <typename T>
void avlTree<T>::insert(T data)
{
    root = insertNode(root, data);
}

template <typename T>
void avlTree<T>::remove(T data)
{
    root = removeNode(root, data);
}

template <typename T>
void avlTree<T>::printTree()
{
    print_tree(root, "", false, std::cout);
    std::cout << std::endl;
}

template <typename T>
void avlTree<T>::print_tree(avlNode<T> *node, const std::string &prefix, bool isLeft, std::ostream &out)
{

    out << prefix;
    out << (isLeft ? "├──" : "└──");

    // print the value of the node
    if (node == nullptr)
    {
        out << "[null]" << std::endl;
        return;
    }
    out << "[" << node->data << "]" << std::endl;

    print_tree(node->left, prefix + (isLeft ? "│   " : "    "), true, out);
    print_tree(node->right, prefix + (isLeft ? "│   " : "    "), false, out);
}

template <typename T>
avlNode<T> *avlTree<T>::auxSearch(avlNode<T> *node, T data)
{

    nSearchComparisons++;

    if (node == nullptr || node->data == data)
    {
        return node;
    }

    nSearchComparisons++;

    if (data < node->data)
    {
        return auxSearch(node->left, data);
    }
    else
    {
        return auxSearch(node->right, data);
    }
}

template <typename T>
avlNode<T> *avlTree<T>::search(T data)
{
    return auxSearch(root, data);
}

template <typename T>
int avlTree<T>::getComparisons()
{
    return nComparisons;
}

template <typename T>
void avlTree<T>::resetComparisons()
{
    nComparisons = 0;
}

template <typename T>
int avlTree<T>::getRotations()
{
    return nRotations;
}

template <typename T>
void avlTree<T>::resetRotations()
{
    nRotations = 0;
}

template <typename T>
int avlTree<T>::getNSearchComparisons()
{
    return nSearchComparisons;
}

template <typename T>
void avlTree<T>::resetNSearchComparisons()
{
    nSearchComparisons = 0;
}

#endif /* AVL_TREE_H */
