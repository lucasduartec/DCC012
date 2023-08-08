
#include "common.h"
#include "huffman.h"

#include <iomanip>

// A rotina main abaixo não deve alterada.
int main(int argc, char** argv) {

    // Cria um compressor de huffma
    Compression::Huffman comp;
    
    // Obtem uma cadeia de caracteres por comando de linha ou arquivo.
    string text = getInputString(argc, argv);

    //  Comprime usando Huffman
    string compressedText = comp.compress(text);

    cout << "Texto original: \n"   << text << endl;
    cout << "Texto comprimido: \n" << compressedText << endl;

    // Imprime a tabela de códigos
    comp.print_codes();

    string decompressedText = comp.decompress(compressedText);
    cout << "Texto descomprimido: " << decompressedText << endl;


    if(text.find(decompressedText)==0) 
        cout << "COMPRESSION OK" << endl;
    else
        cout << "COMPRESSION FAIL" << endl;

    cout << std::fixed << std::setprecision(1);
    //imprime a taxa de compressão com duas casas decimais

    cout << "TAXA DE COMPRESSAO: " << Compression::compressionRate(text, compressedText) << endl;

    return 0;
}
