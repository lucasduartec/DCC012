#include<iostream>
#include<unordered_map>
#include<sstream>
#include<string>
using namespace std;

#include "lzw.h"

#include "common.h"

void print_codes(std::vector<int>& codes)
{
    for(int i = 0; i < codes.size(); i++)
    {
        cout <<"<"<<codes[i]<<">";
    }
    cout << endl;
}

// A rotina main abaixo não deve alterada.
int main(int argc, char** argv) 
{
    Compression::LZW lzw;
    std::vector<int> codes;
    string text = getInputString(argc, argv);
    codes = lzw.compress(text);
    string decompressedText = lzw.decompress(codes);

    cout << "Texto original: " << text << endl;
    cout << "Códigos: ";
    print_codes(codes);
    cout << "Texto descomprimido: " << decompressedText << endl;

    if(decompressedText.find(text)==0) 
        cout << "COMPRESSION OK" << endl;
    else {
        cout << "COMPRESSION FAIL" << endl;
        cout << "Expected: " << text    << endl;
        cout << "Got     : " << decompressedText  << endl;
    }

    return 0;
}