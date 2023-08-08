#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>
using namespace std;

#include "hash.h"
#include "hash_function.h"


#define table_size 5

int main()
{

    // Usando a função de hash por divisão
    Hash h1(table_size, hash_multiply);

    h1.insert(1);
    h1.insert(2);
    h1.insert(3);
    h1.insert(3);
    if(h1.getCollisions() != 1)
        return -1;
        
    ListNode *n = h1.lookup(1);
    if(n == nullptr)
        return -1;

    ListNode *n2 = h1.lookup(4);
    if(n2 == nullptr)
        return -1;
    return 0;
}