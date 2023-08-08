
#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace Compression
{
    class LZW
    {
        public:
            LZW();
            std::vector<int> compress(const string& input);
            string decompress(std::vector<int> &codes);
          
    };
    
}