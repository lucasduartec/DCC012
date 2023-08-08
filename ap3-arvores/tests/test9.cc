#include <iostream>
#include <fstream>
#include <string>

#define CHAVE 82

#include "avl_tree.h"

using namespace std;

// Implemente aqui testes para remoção de arvore AVL
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
    tree.insert(64);

    cout << "--> A árvore AVL é: ";
    tree.printTree();

    cout << "* Removendo chave " << CHAVE << " *" << endl;
    tree.remove(CHAVE);

    if (tree.search(CHAVE) == nullptr)
    {
        cout << "Chave " << CHAVE << " removida com sucesso!" << endl;
        cout << "--> Árvore depois da inserção: ";
        tree.printTree();
        return 0;
    }
    else if (tree.search(CHAVE)->data == CHAVE)
    {
        cout << "Chave " << CHAVE << " não removida!" << endl;
    }

    return -1;
}
