#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

namespace Compression 
{
    struct code {
            int offset;
            int length;
            char next;
    };

    class LZ77
    {

        
        public:
            LZ77();
            LZ77(int buffer_size, int dictionary_size);
            std::vector<code> compress(const string& input);
            void print_codes(std::vector<code>& compressed);
            string decompress(std::vector<code>& compressed);    
            ~LZ77();
        private:
            //char *dictionary
            int   dictionary_size;
            int   buffer_size;
    };

}