#include <iostream>
#include <fstream>
#include <vector>

#include "string_matching.h"

using namespace std;

void imprimePosicoes(std::vector<int> idx)
{
    if (idx.size() == 0)
    {
        cout << "Padrão nao encontrado";
    }
    else if (idx.size() == 1)
    {
        cout << "Padrão encontrado na posiçao: ";
        for (int i = 0; i < idx.size(); i++)
        {
            cout << idx[i];
        }
    }
    else
    {
        cout << "Padrão encontrado nas posições: ";
        for (int i = 0; i < idx.size(); i++)
        {
            if (idx[i] != idx[idx.size() - 1])
            {
                cout << idx[i] << ", ";
            }
            else
            {
                cout << idx[i];
            }
        }
    }

    cout << endl;
}

int main()
{
    // TODO: implemente o programa principal

    std::cout << "=============================" << endl;
    std::cout << "||   Casamento de padrão   ||" << endl;
    std::cout << "=============================" << endl;

    std::cout << endl
              << "Escolha o método a ser aplicado:" << endl;

    std::cout << "[1] Força Bruta" << endl;
    std::cout << "[2] Knuth-Morris-Pratt" << endl;
    std::cout << "[3] Boyer-Moore" << endl;
    std::cout << "[4] Rabin-Karp" << endl;

    int metodo = validateInput(4);

    std::cout << endl
              << "Escolha a entrada de dados:" << endl;

    std::cout << "[1] Teclado" << endl;
    std::cout << "[2] Leitura via arquivo" << endl;

    int data = validateInput(2);

    string text;
    string pattern;
    std::vector<int> idx;

    switch (data)
    {
    case 1:
    {

        std::cout << "\nDigite o texto: ";
        std::getline(std::cin >> std::ws, text);
        std::cout << "Digite o padrão: ";
        std::getline(std::cin, pattern);

        std::cout << "\nTexto: " << text << " | Padrão: " << pattern << endl
                  << endl;

        idx = StringMatching(text, pattern, metodo);
    }
    break;

    case 2:
    {
        text = lerArquivo("../files/StringMatchingOrig.txt");
        pattern = lerArquivo("../files/pattern.txt");

        StringMatching(metodo);
    }

    default:
        break;
    }

    if (data == 1)
    {
        imprimePosicoes(idx);
    }

    return 0;
}