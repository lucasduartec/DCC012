#include "estudante.h"
#include "siga.h"
#include "tools.h"
using namespace Siga;

void print_menu()
{
    cout << "SIGA - Sistema de Gestão Acadêmica" << endl;
    cout << "-----------------------------------" << endl;
    cout << "1. Inserir estudante" << endl;
    cout << "2. Buscar estudante Por Nome" << endl;
    cout << "3. Buscar estudante Por Matricula" << endl;
    cout << "4. Exportar CSV" << endl;
    cout << "9. Sair" << endl;
    cout << "Digite sua opção: ";
}

Estudante Getting_Estudante()
{
    int matricula;
    std::string nome;
    int curso;
    int ano_ingresso;
    int semestre_ingresso;
    float ira;

    cout << "Digite a matrícula: ";
    cin >> matricula;
    cout << "Digite o nome: ";
    cin >> nome;
    cout << "Digite o curso: ";
    cin >> curso;
    cout << "Digite o ano de ingresso: ";
    cin >> ano_ingresso;
    cout << "Digite o semestre de ingresso: ";
    cin >> semestre_ingresso;
    cout << "Digite o IRA: ";
    cin >> ira;
    return Estudante(matricula, nome.c_str(), ano_ingresso, semestre_ingresso, curso, ira);
}

int main(int argc, const char *argv[])
{

    Siga::Siga siga;
    siga.InitDatabase("estudantes");

    int opcao = 0;
    do
    {
        print_menu();
        cin >> opcao;
        switch (opcao)
        {
        case 1:
        {
            Estudante estudante = Getting_Estudante();
            siga.AdicionaEstudante(estudante);
            break;
        }
        case 2:
        {
            int matricula;
            cout << "Digite a matrícula: ";
            cin >> matricula;
            int idx = siga.PesquisaPorMatricula(matricula);
            if (idx != -1)
            {
                Estudante est = siga.ObterEstudante(idx);
                est.Imprimir();
            }
            else
            {
                cout << "Estudante não encontrado" << endl;
            }
            break;
        }
        case 3:
        {
            string nome;
            cout << "Digite o nome: ";
            cin >> nome;
            int idx = siga.PesquisaPorNome(nome);
            if (idx != -1)
            {
                Estudante est = siga.ObterEstudante(idx);
                est.Imprimir();
            }
            else
            {
                cout << "Estudante não encontrado" << endl;
            }

            break;
        }
        case 4:
        {
            string arquivo_csv;
            cout << "Digite o nome do arquivo CSV: ";
            cin >> arquivo_csv;
            std::vector<Estudante> estudantes;
            siga.ExtraiaEstudantes(estudantes);
            siga.SalvaCSV(arquivo_csv, estudantes);
            break;
        }
        case 9:
            break;
        default:
            cout << "Opção inválida!" << endl;
            break;
        }
    } while (opcao != 9);
    return 0;
}