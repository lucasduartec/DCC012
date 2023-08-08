#include <iostream>
#include <string>
#include <vector>
using namespace std;


#include "common.h"

#include "lz77.h"

// A rotina main abaixo não deve alterada.
int main(int argc, char** argv) {

    Compression::LZ77 lz77;

    std::string text = getInputString(argc, argv);
    std::cout << "Input: " << text << std::endl;

    std::cout << "Compressed: ";
    std::vector<Compression::code> output = lz77.compress(text);
    lz77.print_codes(output);

    std::cout << "Decompressed: ";
    std::string decompressedText = lz77.decompress(output);
    std::cout << decompressedText << std::endl;

    if(decompressedText.find(text)==0) 
        cout << "COMPRESSION OK" << endl;
    else {
        cout << "COMPRESSION FAIL" << endl;
        cout << "Expected: " << text << " " << text.length() << endl;
        cout << "Got     : " << decompressedText << " " << decompressedText.length() << endl;
    }

    return 0;
}