
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "siga.h"

// Insere um estudante no gerencia_siga e imprime
// o numero de estudantes armazenados
int main(int argc, char* argv[])
{
    Siga siga;
    siga.SetDatabase("estudantes.bin");
    siga.AdicionaEstudante(Estudante("Felipe", 677, 2018, 7.5));
    int n = siga.ObterNumeroEstudantes();
    cout << "Numero de estudantes armazenados: " << n << endl;
    if(n != 4)
    {
        cout << "Erro: Numero de estudantes incorreto" << endl;
        return -1;
    }
    return 0;
}
