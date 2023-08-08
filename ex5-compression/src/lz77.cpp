
#include "lz77.h"

namespace Compression
{


    // Construtor para o compressor LZ77
    LZ77::LZ77()
    {
        this->buffer_size = 6;
        this->dictionary_size = 6;
    }

    LZ77::LZ77(int buffer_size, int dictionary_size)
    {
        this->buffer_size = buffer_size;
        this->dictionary_size = dictionary_size;
    }

    LZ77::~LZ77()
    {
    }


    std::vector<code> LZ77::compress(const string &input)
    {
        // numero de caracters do texto de entrada
        int n   = input.length();

        // string de saida
        string compressed;
        std::vector<code> output;
      
        int search_pos, match_pos, match_len;
        
        int pos   = 0;
        while(pos < n)
        {
            char c = input[pos];

            // determina o tamanho da busca no dicionario
            int search_length = pos < this->buffer_size ? pos : this->buffer_size;

            // cria a janela de busca
            // extraio os substring de tamanha search_len imediatamente antes do caracter
            // indicado por pos
            string search_buffer = input.substr(pos - search_length, search_length);

            // inicializa o melhor match com o primeiro caractere
            // isso significa que não há nenhuma substring no buffer
            // que casa com alguma substring da janela de busca.
            code best_match = {0, 0, c};

            // laço na janela de busca
            for (search_pos = 0; search_pos < search_length; ++search_pos) {

                // verica se o caractere atual é igual ao caractere na janela de busca
                match_len = 0;
                while (input[pos + match_len] == search_buffer[search_pos + match_len] &&
                    pos + match_len < input.length() && match_len < this->buffer_size) {
                    ++match_len;
                }

                // atualiza o melhor match
                if (match_len > best_match.length) {
                    best_match.offset = search_length - search_pos;
                    best_match.length = match_len;
                    if (pos + match_len < input.length()) {
                        best_match.next = input[pos + match_len];
                    }
                    if(pos + match_len == input.length())
                    {
                        best_match.next = '\0';
                    }
                }
            }

            // adiciona o melhor match na string comprimida
            output.push_back(best_match);

            //compressed+= "<"+to_string(best_match.offset)+","+to_string(best_match.length)+","+best_match.next+">";

            // atualiza o cursor
            pos += best_match.length + 1;

        }

        return output;

    }

    string LZ77::decompress(std::vector<code>& compressed)
    {
        string decompressed = "";
        int pos = 0;
        int offset, length;
        char next;

        while(pos < compressed.size())
        {
            // Extrai os dados do código
            offset = compressed[pos].offset;
            length = compressed[pos].length;
            next   = compressed[pos].next;

            // adiciona o match na string descomprimida
            int start = decompressed.length() - offset;
            for(int i = 0; i < length; i++)
            {
                decompressed+= decompressed[start+i];
            }
            decompressed+= next;

            // atualiza o cursor para o caractere <
            pos++;
            
        }
        return decompressed;
    }


    void LZ77::print_codes(std::vector<code> &codes)
    {
        for(int i = 0; i < codes.size(); i++)
            cout << "<"+to_string(codes[i].offset)+","+to_string(codes[i].length)+","+codes[i].next+">";
        cout << endl;
    }

}

