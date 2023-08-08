#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "siga.h"

// Inprime Informações de um estudante na base de dados 
int main(int argc, char* argv[])
{

    Siga siga;
    siga.SetDatabase("estudantes.bin");
    int idx = siga.PesquisaPorMatricula(123);
    if(idx != -1)
    {
        Estudante est = siga.ObterEstudante(idx);
        if(est.ObterMatricula() != 123)
            return -1;
        return 0;
    }
    return -1;
}
