#ifndef LIST_H
#define LIST_H

/*
    Implementação de uma lista simplesmente encadeada
*/

class ListNode
{
    public:
        ListNode(int value);           // Construtor
        ~ListNode();                   // Destrutor
        void setNext(ListNode *next);  // Define o próximo nó
        ListNode *getNext();           // Retorna o próximo nó
        int getValue();                // Retorna o valor do nó
        void setValue(int value);      // Define o valor do nó

    private:
        ListNode *next;
        int value;
};


class List  
{
    public:
        List();
        ~List();
        ListNode* insert(int value);
        void remove(int value);
        ListNode* search(int value);
        bool isEmpty();
        void print();
        int getSize();

    private:
        ListNode *head;
        ListNode *tail;
        int size;
};

#endif

