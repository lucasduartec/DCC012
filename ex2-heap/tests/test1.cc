
#include <string>
#include <iostream>
using namespace std;


#include "leftist_heap.h"

// Testa a insersão de um nós na Heap Esquerdistas
int main(int argc, char *argv[])
{

    int array[] = {4,3,20,1,52,6,80,8,98,10};
    int size = sizeof(array)/sizeof(array[0]);

    // Cria uma heap esquerdista vazia.
    LeftistHeap<int> heap;

    // Insere os elementos do array na heap.
    for (int i = 0; i < size; i++) {
        cout << "Inserindo " << array[i] <<":\n"<< endl;
        heap.Insert(array[i]);  
        heap.Print(); 
    }

    if(!heap.isLeftistHeap())
        return -1; // indica que o teste falhou
 
    return 0;

}





