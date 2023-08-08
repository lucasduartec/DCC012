#include "siga.h"
#include "sort.h"
#include "tools.h"
#include "perf.h"
#include "estudante.h"
#include <algorithm>

#define ORDEM_B 16

// TODO:
//      Implementar medição  de performance considerando inserção de chaves inteiras aleatórias
//      e chaves ordenados.
//      Use base de dados com 100, 1000, 10000, 100000, 1000000 elementos.
//       - Para árvores AVL e Vermelho-Preto, compare o número de total rotações no processo de
//         inserção.
//       - Para arvore B, teste para diferentes ordem: 2, 4, 8, 16;
//       - Verifique o número de comparações na busca tanto na arvore AVL, vermelho-preto e na arvore B
//      Indique os resultados obtidos no arquivo REPORT.md

void runPerformanceTest(int option, int operation)
{
    avlTree<int> avlPerfTree;
    rbTree<int> rbPerfTree;
    bTree<int> bPerfTree(ORDEM_B);

    int numElements[5] = {100, 1000, 10000, 100000, 1000000};

    for (int j = 0; j < 5; j++)
    {
        std::vector<int> v;

        if (option == 1)
        {
            v = Siga::Tools::get_random_int_vector(numElements[j], 1000000);
        }
        else if (option == 2)
        {
            v = Siga::Tools::get_sorted_int_vector(numElements[j], 1000000);
        }

        for (int i = 0; i < v.size(); i++)
        {
            avlPerfTree.insert(v[i]);
            rbPerfTree.insert(v[i]);
            bPerfTree.insert(v[i]);
        }

        switch (operation)
        {
        case 1:


            cout << "\nÁrvore AVL - Inserção de " << numElements[j] << " elementos" << endl;
            cout << "Número de rotações: " << avlPerfTree.getRotations() << endl;

            cout << "\nÁrvore vermelha e preta - Inserção de " << numElements[j] << " elementos" << endl;
            cout << "Número de rotações: " << rbPerfTree.getRotations() << endl;

            cout << "\n============================================\n";


            avlPerfTree.resetRotations();
            rbPerfTree.resetRotations();

            break;
        case 2:
            int chave = Siga::Tools::get_random_int_number(1, 1000000);


            cout << "\nÁrvore AVL - Busca da chave " << chave << " entre " << numElements[j] << " elementos " << endl;

            if (avlPerfTree.search(chave) == nullptr)
            {
                cout << "Chave " << chave << " não encontrada!" << endl;
            }
            else
            {
                cout << "Chave " << chave << " encontrada!" << endl;
            }

            cout << "Número de comparações: " << avlPerfTree.getNSearchComparisons() << endl;

            cout << "\nÁrvore vermelha e preta - Busca da chave " << chave << " entre " << numElements[j] << " elementos " << endl;

            if (rbPerfTree.search(chave) == nullptr)
            {
                cout << "Chave " << chave << " não encontrada!" << endl;
            }
            else
            {
                cout << "Chave " << chave << " encontrada!" << endl;
            }

            cout << "Número de comparações: " << rbPerfTree.getNSearchComparisons() << endl;

            cout << "\nÁrvore B - Busca da chave " << chave << " entre " << numElements[j] << " elementos " << endl;

            if (bPerfTree.search(chave) == nullptr)
            {
                cout << "Chave " << chave << " não encontrada!" << endl;
            }
            else
            {
                cout << "Chave " << chave << " encontrada!" << endl;
            }

            cout << "Número de comparações: " << bPerfTree.getNSearchComparisons() << endl;

            cout << "\n============================================\n";


            avlPerfTree.resetNSearchComparisons();
            rbPerfTree.resetNSearchComparisons();
            bPerfTree.resetNSearchComparisons();

            break;
        }
    }
}

int main(int argc, const char *argv[])
{

    int option;
    cout << " Teste de performance em árvores.\n Selecione a configuração de entrada:\n (1) Chaves aleatórias\n (2) Chaves ordenadas\n";
    cin >> option;

    int operation;
    cout << " Selecione o tipo de operação:\n (1) Inserção\n (2) Busca\n";
    cin >> operation;

    runPerformanceTest(option, operation);

    return 0;
}
