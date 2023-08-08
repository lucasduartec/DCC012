

#include "lz78.h"

namespace Compression
{

    // TODO: Implementar a compressão do método LZ78 seguindo os passos abaixo.
    std::vector<code> LZ78::compress(const std::string &input)
    {
        // Use a unordered_map abaixo como dicionário
        std::unordered_map<std::string, int> dictionary;
        std::vector<code> output;

        // 1. Define uma string prefixo vazia
        // 2. index = 0
        // 3. Para cada caracter da string input faça
        // 3.1 Se prefixo + c não está no dicionário
        // 3.1.1  p = dictionary[prefixo]
        // 3.1.2  adicione <p,c> no output
        // 3.1.3  index                = index + 1
        // 3.1.4  dictinary[prefixo+c] = index
        // 3.1.5  prefix = ""
        // 3.2 Caso contrário
        // 3.2.1  prefixo = prefixo + c
        // 4. Se prefixo não estiver vazio
        // 4.1  p = dictinary[prefixo]
        // 4.2. adicione <p,'\0'> no output

        std::string prefix = "";
        int index = 0;

        for (char c : input)
        {
            if (dictionary.find(prefix + c) == dictionary.end())
            {
                int p = dictionary[prefix];
                output.push_back({p, c});
                index++;
                dictionary[prefix + c] = index;
                prefix = "";
            }
            else
            {
                prefix = prefix + c;
            }
        }

        if (!prefix.empty())
        {
            int p = dictionary[prefix];
            output.push_back({p, '\0'});
        }

        return output;
    }

    std::string LZ78::decompress(std::vector<code> &compressed)
    {
        // Para a descompressão usamos um dicionário inverso.
        std::unordered_map<int, string> dictionary;
        std::string decompressed = "";
        int index = 0;
        int pos = 0;

        // cada iteração dessa laço, process um código com
        // a seguinte formatação <int,char>
        while (pos < compressed.size())
        {
            // recupera codigo e caracter
            int p = compressed[pos].p;
            char c = compressed[pos].c;

            std::string prefix = "";

            // Recupera o prefixo no dicionário
            if (p != 0)
            {
                prefix += dictionary[p];
            }

            prefix += c;

            // escreve prefix + c na saida
            decompressed += prefix;

            // incrementa indice
            index = index + 1;

            // adiciona prefix + c no dicionáriona posição index
            dictionary[index] = prefix;

            pos++;
        }

        return decompressed;
    }

    void LZ78::print_codes(std::vector<code> &codes)
    {
        for (int i = 0; i < codes.size(); i++)
            cout << "<" << to_string(codes[i].p) << "," << codes[i].c << ">";
        cout << endl;
    }

}
