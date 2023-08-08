#include <iostream>
#include <fstream>
#include <string>

#define CHAVE 64

#include "b_tree.h"

using namespace std;

// Implemente aqui testes para busca de arvore B
int main(int argc, char *argv[])
{
       bTree<int> tree(3);

       tree.insert(12);
       tree.insert(70);
       tree.insert(80);
       tree.insert(43);
       tree.insert(41);
       tree.insert(60);
       tree.insert(82);
       tree.insert(90);
       tree.insert(99);
       tree.insert(11);
       tree.insert(64);

       cout << "--> A árvore B é:" << endl;
       tree.print();

       cout << "* Buscando chave " << CHAVE << " *" << endl;

       if (tree.search(CHAVE) == nullptr)
       {
              cout << "Chave " << CHAVE << " não encontrada!" << endl;
              return -1;
       }
       else
       {
              cout << "Chave " << CHAVE << " encontrada!" << endl;
       }
       return 0;
}
