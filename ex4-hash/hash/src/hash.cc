#include <iostream>
#include <vector>

#include "hash.h"

using namespace std;

Hash::Hash(int size, HashFunction* hash_fn)
{
    this->_hash_fn = hash_fn;
    this->_table_size = size;
    this->_n_collisions = 0;
    this->_hash_table.resize(size);
}

Hash::~Hash()
{
   //TODO: Implementar o destrutor
}

ListNode* Hash::insert(int key)
{
    //TODO: Implementar a inserção

    // Chamar a função _hash_fn para calcular o índice    
    int index = _hash_fn(key, _table_size);

    // Inserir na lista encadeada que está no índice calculado
    ListNode *pointer = _hash_table[index]->insert(key);

    // Atualizar o número de colisões se a lista não estiver vazia
    if(!_hash_table[index]->isEmpty())
        _n_collisions++;

    // Retornar um ponteiro para o valor inserido
    return pointer;
}

ListNode* Hash::lookup(int key)
{
    //TODO: Implementar a busca
    // Chamar a função hash_fn para calcular o índice
    int index = _hash_fn(key, _table_size);

    // Buscar na lista encadeada que está no índice calculado
    ListNode *pointer =  _hash_table[index]->search(key);

    // Retornar um ponteiro para o valor buscado
    return pointer;
}


int Hash::getCollisions()
{
    return this->_n_collisions;
}

