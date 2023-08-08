#include <iostream>
using namespace std;

#include "list.h"


// Implentação da classe ListNode;
ListNode::ListNode(int value)
{
    this->value = value;
    this->next = nullptr;
}

ListNode* ListNode::getNext()
{
    return this->next;
}

int ListNode::getValue()
{
    return this->value;
}

void ListNode::setNext(ListNode *next)
{
    this->next = next;
}

void ListNode::setValue(int value)
{
    this->value = value;
}

ListNode::~ListNode()
{
    // do nothing
}


// Implementação da classe List
List::List()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

List::~List()
{
    ListNode *node = this->head;
    while (node != nullptr)
    {
        ListNode *aux = node->getNext();
        delete node;
        node = aux;
    }
}

ListNode* List::insert(int value)
{
    // Se value ja estive rna lista, retorna o nó
    ListNode *tmp = this->search(value);
    if(tmp != nullptr)
        return tmp;

    // caso contrário, insere no final da lista
    //  e retorna o nó inserido
    ListNode *node = new ListNode(value);
    if (this->head == nullptr)
    {
        this->head = node;
        this->tail = node;
    }
    else
    {
        this->tail->setNext(node);
        this->tail = node;
    }
    this->size++;

    
    return node;
}

void List::remove(int value)
{
    ListNode *node = this->head;
    ListNode *prev = nullptr;
    while (node != nullptr)
    {
        if (node->getValue() == value)
        {
            // se o nó a ser removido é o primeiro da lista
            if (prev == nullptr)
            {
                
                this->head = node->getNext();
            }
            else
            {
                prev->setNext(node->getNext());
            }
            if (node == this->tail)
            {
                this->tail = prev;
            }
            delete node;
            this->size--;
            return;
        }
        prev = node;
        node = node->getNext();
    }
}

ListNode* List::search(int value)
{
    ListNode *node = this->head;
    while (node != nullptr)
    {
        if (node->getValue() == value)
        {
            return node;
        }
        node = node->getNext();
    }
    return nullptr;
}

void List::print()
{
    ListNode *node = this->head;
    while (node != nullptr)
    {
        cout << node->getValue() << " ";
        node = node->getNext();
    }
    cout << endl;
}

bool List::isEmpty()
{
    return this->size == 0;
}

int List::getSize()
{
    return this->size;
}


