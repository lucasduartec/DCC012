
#include <string>
#include <iostream>
using namespace std;


#include "leftist_heap.h"

// Testa a função removeMax de uma Heap Esquerdistas 
int main(int argc, char *argv[])
{

    int array1[] = {4,3,20,1,52,6,80,8,98,10};
    int array2[] = {6,4,121,5, 45};
    int size1 = sizeof(array1)/sizeof(array1[0]);
    int size2 = sizeof(array2)/sizeof(array2[0]);

    // Cria uma heap esquerdista vazia.
    LeftistHeap<int> heap;

    // Insere os elementos do array na heap.
    for (int i = 0; i < size1; i++) {
        heap.Insert(array1[i]); 
    }

    cout << "Removendo o maior elemento da heap: " << heap.RemoveMax() << endl;
    if(heap.FindMax() != 80)
        return -1; // indica que o teste falhou
    
    for(int i = 0; i < size2; i++)
    {
        heap.Insert(array2[i]); 
    }
    cout << "Removendo o maior elemento da heap: " << heap.RemoveMax() << endl;
    if(heap.FindMax() != 80)
        return -1; // indica que o teste falhou

    cout << "Removendo o maior elemento da heap: " << heap.RemoveMax() << endl;
    if(heap.FindMax() != 52)
        return -1; // indica que o teste falhou

    if(!heap.isLeftistHeap())
        return -1; // indica que o teste falhou

    return 0; // indica que o teste passou

}
