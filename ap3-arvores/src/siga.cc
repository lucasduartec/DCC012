#include <cassert>
#include <sstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <iomanip>

using namespace std;

#include "avl_tree.h"
#include "rb_tree.h"
#include "b_tree.h"

#include <config.h>
#include <siga.h>
#include <sort.h>

namespace Siga
{

    struct
    {
        bool operator()(Estudante a, Estudante b) const
        {
            return std::strcmp(a.ObterNome(), b.ObterNome()) < 0;
        }
    } CompareName;

    struct
    {
        bool operator()(Estudante a, Estudante b) const
        {
            return a.ObterCurso() < b.ObterCurso();
        }
    } CompareCurso;

    struct
    {
        bool operator()(Estudante a, Estudante b) const
        {
            return a.ObterAnoIngresso() < b.ObterAnoIngresso();
        }
    } CompareAno;

    Siga::Siga()
    {
        this->arquivo_nome = "";
        this->n_estudantes = 0;
    }

    void Siga::InitDatabase(string database_name)
    {

        this->arquivo_nome = INPUT_DATA_DIR + database_name + ".bin";

        // Obter numero de estudantes no arquivo
        // Se o arquivo não existir, o numero de estudantes é zero
        // Se o arquivo existir, o numero de estudantes é o numero de registros no arquivo
        //  o numero de estudantes é armazenado no atributo n_estudantes

        this->file_stream = fstream(this->arquivo_nome, ios::in | ios::out | ios::binary);
        cout << "SIGA: Inicializado com sucesso" << endl;

        // arquivo nao existe ainda
        if (!this->file_stream.is_open())
        {

            // cria um arquivo vazio
            ofstream out(arquivo_nome, ios::binary);
            out.close();
            // reabre para leitura e escrita
            this->file_stream = fstream(this->arquivo_nome, ios::in | ios::out | ios::binary);
            if (!this->file_stream.is_open())
            {
                cout << "SIGA: Erro ao criar arquivo de dados de estudante" << endl;
                return;
            }
        }

        cout << "SIGA: Opened file " << this->arquivo_nome << endl;
        cout << "SIGA: Arquivo de dados de estudante aberto com sucesso" << endl;
        this->file_stream.seekg(0, this->file_stream.end);
        int length = this->file_stream.tellg();
        this->file_stream.seekg(0, this->file_stream.beg);
        this->n_estudantes = length / sizeof(Estudante);
        cout << this->n_estudantes << " registros de estudantes" << endl;

        if (this->n_estudantes == 0)
        {
            // Abre o arquivo csv para inicializar o arquivo binario
            cout << "SIGA: importando dados de " << database_name << ".csv" << endl;
            this->LerCSV(database_name);
            cout << "SIGA: " << this->n_estudantes << " estudantes importados" << endl;
        }

        bIndexer.setDegree(50);

        for (int i = 0; i < this->n_estudantes; i++)
        {
            indexer.matricula = ObterEstudante(i).ObterMatricula();
            indexer.idx = i;

            avlIndexer.insert(indexer);
            // rbIndexer.insert(indexer);
            bIndexer.insert(indexer);
        }

        // TODO: criar a indexação do arquivo binário por matricula e nome:
        //   Use os pares <matricula, idx> e <nome, idx> para indexar o arquivo binário, onde
        //   idx é o endereço do registro do estudante no arquivo binário
    }

    void Siga::LerCSV(string arquivo_csv)
    {

        string arquivo_csv_path = INPUT_DATA_DIR + arquivo_csv + ".csv";
        ifstream csv_file;
        csv_file.open(arquivo_csv_path);
        if (!csv_file.is_open())
        {
            cout << "Erro ao abrir arquivo CSV" << endl;
            return;
        }
        // Ler cabeçalho
        string line;

        this->n_estudantes = 0;

        // header line
        // matricula,nome,ano_ingresso,semestre_ingresso,curso,ira
        getline(csv_file, line);

        while (getline(csv_file, line))
        {
            // Ler um estudante do arquivo CSV
            Estudante est;
            stringstream ss(line);
            string token;
            getline(ss, token, ','); // le matricula
            est.TrocarMatricula(stoi(token));
            getline(ss, token, ','); // le nome
            est.TrocarNome(token.c_str());
            getline(ss, token, ','); // ano_ingresso
            est.TrocarAnoIngresso(stoi(token));
            getline(ss, token, ','); // semestre_ingresso
            est.TrocarSemestreIngresso(stoi(token));
            getline(ss, token, ','); // curso
            est.TrocarCurso(stoi(token));
            getline(ss, token); // ira
            est.TrocarIRA(stof(token));

            this->EscrevaEstudante(this->n_estudantes, est);
            this->n_estudantes++;
        }
        // Fim-Para
        // Fechar arquivo CSV
        csv_file.close();
    }

    int Siga::PesquisaPorMatricula(int matricula)
    {

        // TODO: modificar para usar a indexação por matricula
        file_stream.seekg(0, file_stream.beg);
        for (int i = 0; i < n_estudantes; i++)
        {
            Estudante est = ObterEstudante(i);
            if (est.ObterMatricula() == matricula)
            {
                return i;
            }
        }

        return -1;
    }

    int Siga::PesquisaPorMatriculaAVLTree(int matricula)
    {
        indexerMat indexedStudent;
        indexedStudent.matricula = matricula;

        avlNode<indexerMat> *node = avlIndexer.search(indexedStudent);
        if (node != nullptr)
            return node->data.idx;
        else
            return -1;
    }

    // int Siga::PesquisaPorMatriculaRBTree(int matricula)
    // {
    //     indexerMat indexedStudent;
    //     indexedStudent.matricula = matricula;

    //     rbNode<indexerMat> *node = rbIndexer.search(indexedStudent);
    //     if (node != nullptr)
    //         return node->getData().idx;
    //     else
    //         return -1;
    // }

    int Siga::PesquisaPorMatriculaBTree(int matricula)
    {
        indexerMat indexedStudent;
        indexedStudent.matricula = matricula;

        bNode<indexerMat> *node = bIndexer.search(indexedStudent);
        if (node != nullptr)
            return bIndexer.GetKey(node, indexedStudent).idx;
        else
            return -1;
    }

    int Siga::PesquisaPorNome(string nome)
    {

        // TODO: modificar para usar a indexação por nome
        file_stream.seekg(0, file_stream.beg);
        for (int i = 0; i < n_estudantes; i++)
        {
            Estudante est = ObterEstudante(i);
            if (std::strcmp(est.ObterNome(), nome.c_str()) == 0)
            {
                return i;
            }
        }

        return -1;
    }

    void Siga::AdicionaEstudante(Estudante est)
    {

        if (PesquisaPorMatricula(est.ObterMatricula()) != -1)
        {
            cout << "Estudante já existe" << endl;
            return;
        }

        indexerMat auxInd;

        auxInd.matricula = est.ObterMatricula();
        auxInd.idx = this->n_estudantes;

        avlIndexer.insert(auxInd);
        // rbIndexer.insert(auxInd);
        bIndexer.insert(auxInd);

        this->EscrevaEstudante(this->n_estudantes, est);
        this->n_estudantes++;
    }

    Estudante Siga::ObterEstudante(int idx)
    {

        Estudante est;
        this->LeiaEstudante(idx, est);
        return est;
    }

    void Siga::SalvaCSV(string arquivo_csv, std::vector<Estudante> &estudantes)
    {
        string arquivo_csv_path = arquivo_csv;

        ofstream csv_file;
        csv_file.open(arquivo_csv_path);
        if (!csv_file.is_open())
        {
            cout << "Erro ao abrir arquivo CSV" << endl;
            return;
        }

        Sort::MergeSort(estudantes, CompareName);
        Sort::BasicSort(estudantes, CompareAno);
        Sort::BasicSort(estudantes, CompareCurso);

        csv_file << "matricula,nome,ano_ingresso,semestre_ingresso,curso,ira" << endl;
        for (int i = 0; i < estudantes.size(); i++)
        {
            csv_file << setw(10) << left << estudantes[i].ObterMatricula() << ","
                     << setw(20) << left << estudantes[i].ObterNome() << ","
                     << setw(5) << left << estudantes[i].ObterAnoIngresso() << ","
                     << setw(5) << left << estudantes[i].ObterSemestreIngresso() << ","
                     << setw(5) << left << estudantes[i].ObterCurso() << ","
                     << setw(10) << left << setprecision(2) << fixed << estudantes[i].ObterIRA() << endl;
        }

        csv_file.close();
    }

    void Siga::AlteraCadastroEstudante(int idx, Estudante est)
    {
        this->EscrevaEstudante(idx, est);
    }

    Siga::~Siga()
    {
        this->file_stream.close();
    }

    int Siga::ObterNumeroEstudantes()
    {
        return this->n_estudantes;
    }

    // Le um objeto estudante no arquivo binario
    void Siga::LeiaEstudante(int idx, Estudante &est)
    {
        this->file_stream.seekg(idx * sizeof(Estudante), this->file_stream.beg);
        this->file_stream.read((char *)&est, sizeof(Estudante));
    }

    // Escreve um objeto estudante no arquivo binario
    void Siga::EscrevaEstudante(int idx, Estudante est)
    {
        this->file_stream.seekp(idx * sizeof(Estudante), this->file_stream.beg);
        this->file_stream.write((char *)&est, sizeof(Estudante));
    }

    // Retorna uma vetor de estudantes
    void Siga::ExtraiaEstudantes(std::vector<int> idxs, std::vector<Estudante> &list)
    {
        list.resize(idxs.size());
        for (int i = 0; i < idxs.size(); i++)
        {
            this->LeiaEstudante(idxs[i], list[i]);
        }
    }

    void Siga::ExtraiaEstudantes(std::vector<Estudante> &list)
    {
        list.resize(this->n_estudantes);
        for (int i = 0; i < this->n_estudantes; i++)
        {
            this->LeiaEstudante(i, list[i]);
        }
    }

}