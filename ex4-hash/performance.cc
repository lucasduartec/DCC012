#include <vector>
#include <iostream>
#include <cstdlib>
using namespace std;

#include "hash.h"
#include "hash_function.h"

// Create a randon integer between 0 and 999999
int randomInt() {
  return rand() % 1000000;
}

void test_hash_divide(std::vector<int> keys) {

    std::cout << "Testando a função de hash de divisão" << std::endl;
    
    Hash hashTable(1000, hash_divide);

    // Insert 1000 random integers into the hash table
    for (int i = 0; i < 1000; i++) {
        hashTable.insert(keys[i]);
    }

    // Search for 1000 random integers in the hash table
    for (int i = 0; i < 1000; i++) {
        hashTable.lookup(randomInt());
    }

    // Imprime o número de colisões
    cout << "Número de colisões: " << hashTable.getCollisions() << endl;
}

void test_hash_multiply(std::vector<int> keys) {

    std::cout << "Testando a função de hash multiplicação" << std::endl;

    Hash hashTable(1000, hash_multiply);

    // Insert 1000 random integers into the hash table
    for (int i = 0; i < 1000; i++) {
        hashTable.insert(keys[i]);
    }

    // Search for 1000 random integers in the hash table
    for (int i = 0; i < 1000; i++) {
        hashTable.lookup(randomInt());
    }

    // Imprime o número de colisões
    cout << "Número de colisões: " << hashTable.getCollisions() << endl;
}

void test_hash_my_func(std::vector<int> keys) {

    std::cout << "Testando minha função de hash" << std::endl;

    Hash hashTable(1000, hash_my_func);

    // Insert 1000 random integers into the hash table
    for (int i = 0; i < 1000; i++) {
        hashTable.insert(keys[i]);
    }

    // Search for 1000 random integers in the hash table
    for (int i = 0; i < 1000; i++) {
        hashTable.lookup(randomInt());
    }

    // Imprime o número de colisões
    cout << "Número de colisões: " << hashTable.getCollisions() << endl;
}

int main() {

    srand(time(NULL));
    std::vector<int> keys(1000);

    for(int i = 0; i < 1000; i++) {
        keys[i] = randomInt();
    }

    test_hash_divide(keys); 
    test_hash_multiply(keys);


    return 0;
}



