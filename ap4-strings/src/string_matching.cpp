
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

#include "string_matching.h"

using namespace std;

int validateInput(int optionRange)
{
    int input;
    std::cin >> input;

    while (input < 1 || input > optionRange)
    {
        cout << "Opção inválida. Digite novamente: ";
        std::cin >> input;
    }

    return input;
}

string lerArquivo(const string &nomeArquivo)
{
    std::ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open())
    {
        std::cerr << "Erro ao abrir o arquivo " << nomeArquivo << std::endl;
        return "";
    }

    std::string conteudo;
    std::string linha;
    while (getline(arquivo, linha))
    {
        if (!linha.empty() && linha.back() == '\n')
        {
            linha.pop_back();
        }
        conteudo += linha;
    }

    arquivo.close();

    return conteudo;
}

std::vector<int> StringMatching(std::string text, std::string pattern, int metodo)
{

    switch (metodo)
    {
    case 1:
        std::cout << "- Testando algoritmo de força bruta -" << endl;
        return NaiveStringMatcher(text, pattern);

    case 2:
        std::cout << "- Testando algoritmo de Knuth-Morris-Pratt -" << endl;
        return KMPStrMatcher(text, pattern);

    case 3:
        std::cout << "- Testando algoritmo de Boyer-Moore -" << endl;
        return BoyerMooreStrMatcher(text, pattern);

    case 4:
        std::cout << "- Testando algoritmo de Rabin-Karp -" << endl;
        return RabinKarpStrMatcher(text, pattern);

    default:
        return std::vector<int>();
    }
}

void StringMatching(int metodo)
{
    string text = lerArquivo("../files/StringMatchingOrig.txt");
    string pattern = lerArquivo("../files/pattern.txt");

    std::vector<int> idx = StringMatching(text, pattern, metodo);
    int cont = 0;
    std::ofstream outputFile("../StringMatchingOutput.txt");
    if (outputFile.is_open())
    {
        for (int i = 0; i < idx.size(); i++)
        {
            outputFile << idx[i] << " ";
            cont++;
        }
        if (cont == 0)
        {
            outputFile << std::endl
                       << "O padrão não foi encontrado no texto" << std::endl;
        }
        else if (cont == 1)
        {
            outputFile << std::endl
                       << "O padrão ocorre uma vez no texto" << std::endl;
        }
        else
        {
            outputFile << std::endl
                       << "Foram encontradas " << cont << " ocorrências do padrão no texto." << std::endl;
        }
        outputFile.close();
        std::cout << "Os inteiros foram escritos no arquivo com sucesso. " << std::endl;
    }
    else
    {
        std::cout << "Não foi possível abrir o arquivo." << std::endl;
    }
}

std::vector<int> NaiveStringMatcher(string text, string pattern)
{

    vector<int> idx;

    int t_size = text.size();
    int p_size = pattern.size();

    int j;
    for (int i = 0; i <= t_size - p_size; i++)
    {
        for (j = 0; j < p_size; j++)
        {
            if (pattern[j] != text[i + j])
                break;
        }

        if (j == p_size)
        {
            idx.push_back(i);
            i += p_size - 1;
        }
    }

    return idx;
}

void MakeBadOffset(std::string pattern, std::vector<int> &badOffSet)
{
    int d = 256;
    int m = pattern.size();

    for (int i = 0; i < d; i++)
    {
        badOffSet[i] = -1;
    }
    for (int i = 0; i < m; i++)
    {
        badOffSet[pattern[i]] = i;
    }
}

std::vector<int> BoyerMooreStrMatcher(std::string text, std::string pattern)
{
    int d = 256, offSet = 0, j = 0;
    int n = text.size(), m = pattern.size();
    std::vector<int> badOffSet(d);
    vector<int> idx;

    MakeBadOffset(pattern, badOffSet);
    while (offSet <= (n - m))
    {
        j = m - 1;
        while (j >= 0 && pattern[j] == text[offSet + j])
        {
            j--;
        }
        if (j < 0)
        {
            idx.push_back(offSet);
            if ((offSet + m) >= n)
            {
                offSet += 1;
            }
            else
            {
                offSet += m - badOffSet[text[offSet + m]];
            }
        }
        else
        {
            offSet += std::max(1, j - badOffSet[text[offSet + j]]);
        }
    }

    return idx;
}

std::vector<int> RabinKarpStrMatcher(std::string text, std::string pattern)
{
    int n = text.size(), m = pattern.size();
    int d = 256, q = 101;
    int h = pow(d, m - 1);
    h = h % q;
    int hashP = 0, hashT = 0;
    bool found = false;
    vector<int> idx;

    for (int i = 0; i < m; i++)
    {
        hashP = (d * hashP + pattern[i]) % q;
        hashT = (d * hashT + text[i]) % q;
    }

    for (int i = 0, j = 0; i <= n - m; i++)
    {
        if (hashP == hashT)
        {
            found = true;
            for (j = 0; j < m; j++)
            {
                if (text[i + j] != pattern[j])
                {
                    found = true;
                    break;
                }
            }
            if (j == m)
                idx.push_back(i);
            // cout << "Padrão encontrado no(s) índice(s) " << i << endl;
        }

        if (i < n - m)
        {
            hashT = (d * (hashT - text[i] * h) + text[i + m]) % q;
            if (hashT < 0)
                hashT = hashT + q;
        }
    }
    return idx;
}

std::vector<int> ComputePiArray(std::string pattern, std::vector<int> &pi)
{
    int m = pattern.size(), len = 0;
    pi[0] = 0;

    for (int i = 1; i < m; i++)
    {
        while (len > 0 && pattern[len] != pattern[i])
        {
            len = pi[len - 1];
        }
        if (pattern[len] == pattern[i])
        {
            len++;
        }
        pi[i] = len;
    }
    return pi;
}

std::vector<int> KMPStrMatcher(std::string text, std::string pattern)
{
    int n = text.size(), m = pattern.size();
    int k = 0;
    vector<int> pi(m);
    vector<int> idx;

    ComputePiArray(pattern, pi);

    for (int i = 0; i < n; i++)
    {
        while (k > 0 && pattern[k] != text[i])
        {
            k = pi[k - 1];
        }
        if (pattern[k] == text[i])
        {
            k++;
        }
        if (k == m)
        {
            idx.push_back(i - m + 1);
            k = pi[k - 1];
        }
    }
    return idx;
}