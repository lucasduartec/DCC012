#include <unordered_map>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;
using namespace std;


namespace Compression
{
    class HuffmanNode
    {
        public:
            HuffmanNode(char c, int freq);
            HuffmanNode(HuffmanNode *left, HuffmanNode *right);
            ~HuffmanNode();
            int getFrequency();
            char getChar();
            HuffmanNode *getLeft();
            HuffmanNode *getRight();
            bool isLeaf();
        private:
            char c;
            int freq;
            HuffmanNode *left;
            HuffmanNode *right;
            
    };
    
    class Huffman
    {
        public:
            Huffman();
            std::string compress(const std::string& input);
            std::string decompress(const std::string& input);
            void print_codes();
            ~Huffman();
        private:
            HuffmanNode                        *root;
            unordered_map<char, string>        codes;
            void BuildTree(const std::string& input);
            void BuildCodesTable(HuffmanNode *root);
            void GetCodes(HuffmanNode *root, const string& currentCode);
            void Clean(HuffmanNode *root);
    };

    double compressionRate(string original, string compressed);

}


