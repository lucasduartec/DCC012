
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

namespace Compression 
{
    struct code
    {
        int  p;  // 
        char c;
    };

    class LZ78
    {
        public:
            LZ78(){};
            std::vector<code> compress(const std::string& input);
            std::string decompress(std::vector<code>& compressed);
            void print_codes(std::vector<code> &codes);
    };

}


