
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "siga.h"


// Testa a abertura do arquivo e a leitura de estudantes
int main(int argc, char* argv[])
{
    Siga::Siga siga;
    siga.InitDatabase("estudantes");
    if(siga.ObterNumeroEstudantes() != 5000)
    {
        return -1;
    }

    if(siga.PesquisaPorMatricula(0) != 0)
        return -1;

    return 0;
}


