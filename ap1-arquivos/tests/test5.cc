
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "siga.h"

// Cadastra um novo estudante na base de dados e imprima
// o numero de estudantes armazenados
int main(int argc, char* argv[])
{
    Siga siga;
    siga.SetDatabase("estudantes.bin");
    int idx = siga.PesquisaPorMatricula(456);
    if(idx != -1)
    {
        siga.AlteraCadastroEstudante(idx, Estudante("Maria", 456, 2018, 9.0));
        Estudante est = siga.ObterEstudante(idx);
        if(est.ObterMatricula() != 456)
            return -1;

        if(est.ObterIRA() != 9.0)
            return -1;
        
        return 0;
    }
        
    return -1;
}
