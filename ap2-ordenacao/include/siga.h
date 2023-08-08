#ifndef SIGA_H
#define SIGA_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "config.h"
#include "estudante.h"

using namespace std;

namespace Siga
{

    class Siga
    {
    public:
        Siga();
        void InitDatabase(string database_name);                                     // define o arquivo binario que sera usado como base de dados
        void LerCSV(string arquivo_csv);                                             // adiciona dados de um arquivo CSV para base de dados
        void AdicionaEstudante(Estudante est);                                       // adiciona um estudante na base da dados
        int PesquisaPorMatricula(int matricula);                                     // pesquisa um estudante por matricula na base da dados
        Estudante ObterEstudante(int idx);                                           // Obtem estudante localizado na posicao idx do arquivo binário
        void AlteraCadastroEstudante(int idx, Estudante est);                        // Altera cadastro do estudante localizado na posicao idx do arquivo binário
        void SalvaCSV(string arquivo_txt, std::vector<Estudante> &estudante);        // salvar a lista de estudantes em um arquivo texto formatado CSV
        int ObterNumeroEstudantes();                                                 // retorna o numero de estudantes na base de dados
        void ExtraiaEstudantes(std::vector<int> idxs, std::vector<Estudante> &list); // extrai estudantes com endereços idx da base de dados para um vetor de estudantes
        ~Siga();

    private:
        // atributos
        string arquivo_nome;
        fstream file_stream;
        int n_estudantes;

        // funções auxiliares
        void LeiaEstudante(int idx, Estudante &est);
        void EscrevaEstudante(int idx, Estudante est);
    };

} // namespace Siga

#endif /* SIGA_H */
