#include <unordered_map>
using namespace std;

#include "lzw.h"

namespace Compression
{
    LZW::LZW()
    {
    }

    std::vector<int> LZW::compress(const string &input)
    {

        std::vector<int> codes;
        std::unordered_map<std::string, int> dictionary;

        // 0. Inicialize o dicionário com todas os 255 símbolos da fonte
        // 1. index = 256
        // 2. Inicialize string prefixo com a primeira letra do input
        // 3. Enquanto houver caracter c do input para processar
        //   3.1 Se prefixo + c não está no dicionário
        //     3.1.1 Obter código p de prefixo do dicionário
        //     3.1.2 Adcionar p ao vetor de códigos
        //     3.1.3 Adcionar prefixo + c no dicionário com indice index
        //     3.1.5 index = index + 1
        //     3.1.6 Reinicialize prefixo com c
        //   3.2 Caso contrário,
        //     3.2.1 prefixo = prefixo + c
        // 4. Se prefixo não estiver vazio
        //   4.1  Obter código p de prefixo do dicionário
        //   4.2  Adcionar p ao vetor de códigos
        // 5. Retornar o vetor de códigos.

        for (int i = 0; i < 256; i++)
        {
            std::string symbol = std::string(1, static_cast<char>(i));
            dictionary[symbol] = i;
        }

        int index = 256;
        std::string prefix = std::string(1, input[0]);

        for (int i = 1; i < input.length(); i++)
        {
            char c = input[i];

            if (dictionary.find(prefix + c) == dictionary.end())
            {
                int p = dictionary[prefix];
                codes.push_back(p);
                dictionary[prefix + c] = index++;
                prefix = std::string(1, c);
            }
            else
            {
                prefix = prefix + c;
            }
        }

        if (!prefix.empty())
        {
            int p = dictionary[prefix];
            codes.push_back(p);
        }

        return codes;
    }

    string LZW::decompress(std::vector<int> &codes)
    {

        std::unordered_map<int, std::string> dictionary;
        std::string output = "";

        // 0. Inicialize o dicionário com todas os 255 símbolos da fonte
        for (int i = 0; i < 256; i++)
        {
            std::string symbol = std::string(1, static_cast<char>(i));
            dictionary[i] = symbol;
        }

        // 1. Inicialize a string de saída com vazio
        // 2. Inicialize index com 256
        int index = 256;

        // 3. Seja p o primeiro código do vetor
        int p = codes[0];
        // 4. Obter string str do dicionário referente ao código p
        std::string str = dictionary[p];
        // 5. Concatenar str na string de saída
        output += str;

        // 6. Enquanto houver códigos a decodificar
        for (size_t i = 1; i < codes.size(); i++)
        {
            // 6.1 Seja n o próximo código
            int n = codes[i];
            // 6.2 Seja str uma string vazia
            std::string currentString = "";

            // 6.2 Se o código n está no dicionário
            if (dictionary.find(n) != dictionary.end())
            {
                // 6.2.1 str = dictionary[p]
                currentString = dictionary[n];
            }
            else
            {
                // 6.3 Caso contrário
                // 6.3.1 str = dictionary[p] + dictionary[p][0]
                currentString = dictionary[p] + dictionary[p][0];
            }

            // 6.4 Concatenar str na string de saída
            output += currentString;

            // 6.5 Adicionar currentString ao dicionário na posição index
            dictionary[index] = dictionary[p] + currentString[0];

            // 6.6 index = index + 1
            index++;

            // 6.7 p = n
            p = n;
        }

        // 7. Retorna a string de saída
        return output;
    }
}
