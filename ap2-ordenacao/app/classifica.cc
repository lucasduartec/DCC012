#include "siga.h"
#include "tools.h"
#include "sort.h"
#include "siga.h"
#include "estudante.h"
#include <string.h>
#include <fstream>
#include <iostream>

struct
{
    bool operator()(Siga::Estudante &a, Siga::Estudante &b) const
    {
        return strcmp(a.ObterNome(), b.ObterNome()) < 0;
    }
} cmpNome;

struct
{
    bool operator()(Siga::Estudante &a, Siga::Estudante &b) const
    {

        return a.ObterCurso() < b.ObterCurso();
    }
} cmpCurso;

int main(int argc, const char *argv[])
{
    // TODO: Classifique os estudantes por nome e em seguida por curso.
    // Use os métodos mais eficientes observados no teste de performance.
    // Escreva o resultado em um arquivo CSV chamado "classificacao.csv"

    Perf::Performance perf;
    Perf::PerformanceCounter &counter = perf.get_counter();

    std::vector<Siga::Estudante> estudantes;

    Siga::Siga siga;
    siga.InitDatabase("estudantes");

    std::vector<int> idxs(5001);

    for (int i = 0; i < 5001; i++)
    {
        idxs[i] = i + 1;
    }

    siga.ExtraiaEstudantes(idxs, estudantes);

    Sort::MergeSort(estudantes, cmpNome, counter);
    Sort::MergeSort(estudantes, cmpCurso, counter);

    // Abra o arquivo CSV para escrita
    std::ofstream arquivoCSV("classificacao.csv");

    // Verifique se o arquivo foi aberto corretamente
    if (!arquivoCSV.is_open())
    {
        std::cout << "Erro ao abrir o arquivo CSV" << std::endl;
        return 1;
    }

    arquivoCSV << "nome,curso" << std::endl;

    // Escreva os estudantes classificados no arquivo CSV
    for (int i = 0; i < 5001; i++)
    {
        arquivoCSV << estudantes[i].ObterNome() << ", " << estudantes[i].ObterCurso() << std::endl;
    }

    // Feche o arquivo CSV
    arquivoCSV.close();

    std::cout << "Resultado foi escrito em classificacao.csv" << std::endl;

    return 0;
}
