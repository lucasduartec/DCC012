#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "lz78.h"

#include "common.h"

// A rotina main abaixo não deve alterada.
int main(int argc, char** argv) {

    Compression::LZ78 lz78;
   
    std::string text = getInputString(argc, argv);
    std::cout << "Input: " << text << std::endl;

    std::cout << "Compressed: ";
    std::vector<Compression::code> output = lz78.compress(text);
    

    std::cout << "Decompressed: ";
    std::string decompressedText = lz78.decompress(output);
    std::cout << decompressedText << std::endl;

    if(decompressedText.find(text)==0) 
        cout << "COMPRESSION OK" << endl;
    else {
        cout << "COMPRESSION FAIL" << endl;
        cout << "Expected: " << text << endl;
        cout << "Got     : " << decompressedText  << endl;
    }

    return 0;
}