#include <iostream>
#include <fstream>
#include <string>

#define CHAVE 43

#include "rb_tree.h"

using namespace std;

// Implemente aqui testes para busca de arvore vermelho-preto
int main(int argc, char *argv[])
{
    rbTree<int> tree;

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

    cout << "--> A árvore vermelha e preta é:" << endl;
    tree.printTree();

    cout << "* Buscando chave " << CHAVE << " *" << endl;

    if (tree.search(CHAVE) == nullptr)
    {
        cout << "Chave " << CHAVE << " não encontrada!" << endl;
        return -1;
    }
    else if (tree.search(CHAVE)->getData() == CHAVE)
    {
        cout << "Chave " << CHAVE << " encontrada!" << endl;
    }
    return 0;
}
