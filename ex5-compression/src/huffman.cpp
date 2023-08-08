
#include "huffman.h"

#include <iomanip>
#include <queue>

namespace Compression
{
    // TODO: Implemente a função para calcular a taxa de compressão
    double compressionRate(string original, string compressed)
    {
        double originalSize = original.size();
        double compressedSize = compressed.size();
        double ASCIISize = (double)compressedSize / (double)8;

        return (originalSize - ASCIISize) / originalSize * 100;
    }

    // Contrutor de Nó de Huffman
    // Usado principalmente para criar nó folhas
    HuffmanNode::HuffmanNode(char c, int freq) : c(c), freq(freq), left(nullptr), right(nullptr)
    {
    }

    // Contrutor de Nó de Huffman
    // Usado principalmente para criar nó interno
    HuffmanNode::HuffmanNode(HuffmanNode *left, HuffmanNode *right) : c('\0'), freq(left->freq + right->freq), left(left), right(right)
    {
    }

    HuffmanNode::~HuffmanNode()
    {
    }

    int HuffmanNode::getFrequency()
    {
        return freq;
    }

    char HuffmanNode::getChar()
    {
        return c;
    }

    HuffmanNode *HuffmanNode::getLeft()
    {
        return left;
    }

    HuffmanNode *HuffmanNode::getRight()
    {
        return right;
    }

    bool HuffmanNode::isLeaf()
    {
        return left == nullptr && right == nullptr;
    }

    Huffman::Huffman() : root(nullptr)
    {
    }

    // Função de comparação para a fila de prioridade
    struct Compare
    {
        bool operator()(HuffmanNode *left, HuffmanNode *right)
        {
            return left->getFrequency() > right->getFrequency();
        }
    };

    void Huffman::BuildTree(const std::string &input)
    {
        // Cria uma tabela para contar a frequência de cada caractere
        // Para tanto, usamos um unordered_map, que é uma tabela de hash
        // que mapeia um caractere para um inteiro
        unordered_map<char, int> freqMap;
        for (char c : input)
        {
            freqMap[c]++;
        }

        // Cria uma fila de prioridade para armazenar os nós da árvore de Huffman
        // Note do uso da biblioteca padrão c++ priority_queue
        // https://cplusplus.com/reference/queue/priority_queue/
        priority_queue<HuffmanNode *, vector<HuffmanNode *>, Compare> pq;

        // Cria um nó de huffman para cada caractere e adiciona na fila de prioridade
        for (auto it = freqMap.begin(); it != freqMap.end(); it++)
        {
            pq.push(new HuffmanNode(it->first, it->second));
        }

        // Repete os passos abaixo até que haja apenas um nó na fila de prioridade
        while (pq.size() != 1)
        {
            // Remove os dois nós de menor frequência da fila de prioridade
            HuffmanNode *left = pq.top();
            pq.pop();
            HuffmanNode *right = pq.top();
            pq.pop();

            // Cria um novo nó interno com frequência igual à soma das frequências dos dois nós removidos
            // Observe o construtor. Ele criar um nó com simbolo '\0' e apontando para as subarvores left e right
            pq.push(new HuffmanNode(left, right));
        }

        // O último nó restante na fila de prioridade é a raiz da árvore de Huffman
        root = pq.top();
    }

    void Huffman::BuildCodesTable(HuffmanNode *root)
    {
        if (root == nullptr)
            return;
        GetCodes(root, "");
    }

    // Gera os códigos para cada caracters
    void Huffman::GetCodes(HuffmanNode *root, const string &currentCode)
    {
        if (root == nullptr)
            return;

        // Se root é folha
        // Armazena codigo do caracter na tabela
        if (root->getChar() != '\0')
        {
            codes[root->getChar()] = currentCode;
        }

        // Caso contrario, percorre as subarvores a esquerda e direita
        GetCodes(root->getLeft(), currentCode + "0");
        GetCodes(root->getRight(), currentCode + "1");
    }

    string Huffman::compress(const string &input)
    {
        // Constrói a árvore de Huffman
        BuildTree(input);

        // Constrói a tabela de códigos
        BuildCodesTable(root);

        // Codifica a string de entrada
        string output = "";
        for (char c : input)
        {
            output += codes[c];
        }

        return output;
    }

    string Huffman::decompress(const string &input)
    {
        // Decodifica a string de entrada
        string output = "";
        HuffmanNode *current = root;
        for (char c : input)
        {
            if (c == '0')
            {
                current = current->getLeft();
            }
            else
            {
                current = current->getRight();
            }

            if (current->isLeaf())
            {
                output += current->getChar();
                current = root;
            }
        }

        return output;
    }

    void Huffman::Clean(HuffmanNode *root)
    {
        if (root == nullptr)
            return;
        Clean(root->getLeft());
        Clean(root->getRight());
        delete root;
    }

    Huffman::~Huffman()
    {
        Clean(root);
    }

    void Huffman::print_codes()
    {
        cout << "Tabela de códigos:" << endl;
        for (auto it = codes.begin(); it != codes.end(); it++)
        {
            cout << it->first << " (" << int(it->first) << ") " << it->second << endl;
        }
    }

}