
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
    siga.SalvaCSV("new_estudantes.csv");

    return 0;
}
