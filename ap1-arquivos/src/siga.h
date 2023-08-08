#ifndef SIGA_H
#define SIGA_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "config.h"
#include "estudante.h"

class Siga
{
    public:
        Siga();
        void      SetDatabase(string arquivo_binary);       // define o arquivo binario que sera usado como base de dados
        void      LerCSV(string arquivo_csv);               // adiciona dados de um arquivo CSV para base de dados
        void      AdicionaEstudante(Estudante est);         // adiciona um estudante na base da dados
        int       PesquisaPorMatricula(int matricula);      // pesquisa um estudante por matricula na base da dados
        Estudante ObterEstudante(int idx);                  // Obtem estudante localizado na posicao idx do arquivo binário
        void AlteraCadastroEstudante(int idx, Estudante est); // Altera cadastro do estudante localizado na posicao idx do arquivo binário
        void SalvaCSV(string arquivo_txt);                  // salvar a lista de estudantes em um arquivo texto formatado CSV
        int  ObterNumeroEstudantes();                       // retorna o numero de estudantes na base de dados
        ~Siga();
    private:
        // atributos
        string   arquivo_nome;
        fstream  file_stream;
        int      n_estudantes;

        // funções auxiliares
        void      LeiaEstudante(int idx, Estudante &est);
        void      EscrevaEstudante(int idx, Estudante est);
};

#endif /* SIGA_H */
