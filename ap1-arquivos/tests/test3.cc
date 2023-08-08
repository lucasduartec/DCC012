#include <fstream>
#include <string>
using namespace std;

#include "siga.h"

//  Pesquisa estudante na base de dados
int main(int argc, char *argv[])
{
    Siga siga;
    siga.SetDatabase("estudantes.bin");
    int idx = siga.PesquisaPorMatricula(677);
    cout << "Estudante encontrado na posicao " << idx << endl;
    if (idx == 3)
        return 0;

    return -1;
}
