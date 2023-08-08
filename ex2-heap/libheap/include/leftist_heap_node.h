#ifndef LEFTIST_HEAP_NODE_H__
#define LEFTIST_HEAP_NODE_H__


#include <iostream>



template<typename T>
class LeftistHeap;

/*
 * 
 *  Classe template que representa um nó de uma arvore esquerdista.
 */

template <typename T>
class LeftistHeapNode {
    // Classe amiga: LeftistHeap
    // A classe LeftistHeap pode acessar os membros privados de LeftistHeapNode
    // sem a necessidade de getters e setters.
    friend class LeftistHeap<T>;

    public:

    // Construtor padrão
    LeftistHeapNode(const T&);

    // construtor de copia
    LeftistHeapNode(const T&, LeftistHeapNode<T>*, LeftistHeapNode<T>*);

    // retorna filho esquerdo
    LeftistHeapNode<T>* getLeftChild();

    // retorna filho direito
    LeftistHeapNode<T>* getRightChild();

    // modifica filho esquerdo
    void setLeftChild(LeftistHeapNode<T>*);

    // modifica filho direito
    void setRightChild(LeftistHeapNode<T>*);
    
    // obtem o objeto armazenado no nó
    T& getData();

    // obtem o caminho mais curto para folha
    int  GetDist();

    // modifica o valor do caminho mais curto para folha
    void SetDist(int);
    
    ~LeftistHeapNode();
    
    private:
        T data;
        LeftistHeapNode<T>* left;
        LeftistHeapNode<T>* right;
        int dist; // null path length
         
};

template <typename T>
LeftistHeapNode<T>::LeftistHeapNode(const T& d) : data(d), left(nullptr), right(nullptr), dist(0) {
}

template <typename T>
LeftistHeapNode<T>::LeftistHeapNode(const T& d, LeftistHeapNode<T>* l, LeftistHeapNode<T>* r) : data(d), left(l), right(r), dist(0) {
}

template <typename T>
LeftistHeapNode<T>* LeftistHeapNode<T>::getLeftChild() {
    return left;
}

template <typename T>
LeftistHeapNode<T>* LeftistHeapNode<T>::getRightChild() {
    return right;
}

template<typename T>
void LeftistHeapNode<T>::setLeftChild(LeftistHeapNode<T>* l) {
    left = l;
}

template<typename T>
void LeftistHeapNode<T>::setRightChild(LeftistHeapNode<T>* r) {
    right = r;
}

template <typename T>
T& LeftistHeapNode<T>::getData() {
    return data;
}

template <typename T>
int LeftistHeapNode<T>::GetDist() {
    return dist;
}

template<typename T>
void LeftistHeapNode<T>::SetDist(int n) {
    dist = n;
}

template<typename T>
LeftistHeapNode<T>::~LeftistHeapNode() {

}


#endif /* LEFTIST_HEAP_NODE_H__ */
