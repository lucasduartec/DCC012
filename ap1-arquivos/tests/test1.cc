
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "siga.h"

// Testa a abertura do arquivo e a leitura de estudantes
int main(int argc, char* argv[])
{
    Siga siga;
    siga.SetDatabase("estudantes.bin");
    siga.LerCSV("estudantes.csv");
    if(siga.ObterNumeroEstudantes() == 3)
    {
        return 0;
    }
    return -1;
}


