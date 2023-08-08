#include <iostream>
#include <fstream>
#include <string>

#define CHAVE 64

#include "avl_tree.h"

using namespace std;

// Implemente aqui testes para inserção de arvore AVL
int main(int argc, char *argv[])
{
    avlTree<int> tree;

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

    cout << "--> A árvore AVL é: ";
    tree.printTree();

    cout << "* Inserindo chave " << CHAVE << " *" << endl;
    tree.insert(CHAVE);

    if (tree.search(CHAVE) == nullptr)
    {
        cout << "Chave " << CHAVE << " não inserida!" << endl;
        return -1;
    }
    else if (tree.search(CHAVE)->data == CHAVE)
    {
        cout << "Chave " << CHAVE << " inserida com sucesso!" << endl;
        cout << "--> Árvore depois da inserção: ";
        tree.printTree();
    }

    return 0;
}
