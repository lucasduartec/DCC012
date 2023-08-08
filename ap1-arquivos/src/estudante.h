#ifndef ESTUDANTE_H__
#define ESTUDANTE_H__

#include <fstream>

using namespace std;

#define STR_MAX_SIZE 128
#define ESTUDANTE_SIZE (sizeof(char)*STR_MAX_SIZE + 2*sizeof(int) + sizeof(float))

class Estudante
{
    public:
        Estudante();
        Estudante(const char* nome, int matricula, int ano_ingresso, float ira);

        int         ObterMatricula();
        int         ObterAnoIngresso();
        const char* ObterNome();
        float       ObterIRA();

        void TrocarMatricula(int matricula);
        void TrocarNome(const char* nome);
        void TrocarIRA(float ira);
        void TrocarAnoIngresso(int ano_ingresso);

        void Imprimir();

    private:
        char   _nome[STR_MAX_SIZE];
        int    _matricula;
        int    _ano_ingresso;
        float  _ira;
};


#endif /* ESTUDENT_H__ */
