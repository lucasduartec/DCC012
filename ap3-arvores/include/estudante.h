#ifndef ESTUDANTE_H__
#define ESTUDANTE_H__

#include <fstream>

using namespace std;

#define STR_MAX_SIZE 128

namespace Siga 
{
class Estudante
{
    public:
        Estudante();
        Estudante(int matricula, const char* nome, int ano_ingresso, int semestre_ingresso, int curso, float ira);
        Estudante(const Estudante& estudante);

        int         ObterMatricula();
        const char* ObterNome();
        int         ObterAnoIngresso();
        int         ObterSemestreIngresso();
        int         ObterCurso();
        float       ObterIRA();

        void TrocarMatricula(int matricula);
        void TrocarNome(const char* nome);
        void TrocarAnoIngresso(int ano_ingresso);
        void TrocarSemestreIngresso(int semestre_ingresso);
        void TrocarCurso(int curso);
        void TrocarIRA(float ira);

        void Imprimir();

        friend ostream& operator<<(ostream& os, const Estudante& est);

    private:
        int    _matricula;
        char   _nome[STR_MAX_SIZE];
        int    _ano_ingresso;
        int    _semestre_ingresso;
        int    _curso;
        float  _ira;
};


} // namespace Siga

#endif /* ESTUDENT_H__ */
