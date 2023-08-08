#ifndef HASH_H__
#define HASH_H__

#include <cstring>
#include <vector>

#include "list.h"

typedef int HashFunction(int,int) ;

/**
 * @brief Classe que implementa o algoritmo de hash
 *        com tratamento de colisões por encadeamento separado
 * */

class Hash
{
    public:
        Hash(int size, HashFunction* hash_fn);
        ListNode* insert(int key);
        ListNode* lookup(int ley);
        ~Hash();
        int getCollisions();
    private:
        HashFunction*       _hash_fn;
        std::vector<List*> _hash_table;
        int _table_size;
        int _n_collisions;
};

#endif /* HASH_H__ */
