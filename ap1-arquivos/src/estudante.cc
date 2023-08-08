
#include <cstring>
#include <iostream>
#include <fstream>

#include "estudante.h"

using namespace std;


Estudante::Estudante(): _nome(""), _matricula(0), _ano_ingresso(0), _ira(0)
{};

Estudante::Estudante(const char* nome, int matricula, int ano_ingresso, float ira)
{    
     strcpy(_nome,nome);
    _matricula    = matricula;
    _ano_ingresso = ano_ingresso;
    _ira          = ira;
}
        
int Estudante::ObterMatricula()
{
    return this->_matricula;
}
        
const char* Estudante::ObterNome()
{
    return this->_nome;

}     
float Estudante::ObterIRA()
{
    return this->_ira;
}

int Estudante::ObterAnoIngresso()
{
    return this->_ano_ingresso;
}

void Estudante::TrocarMatricula(int matricula)
{
    this->_matricula = matricula;
}

void Estudante::TrocarNome(const char* nome)
{
    strcpy(_nome,nome);
}
        
void Estudante::TrocarIRA(float ira)
{
    this->_ira = ira;
}

void Estudante::TrocarAnoIngresso(int ano_ingresso)
{
    this->_ano_ingresso = ano_ingresso;
}

void Estudante::Imprimir()
{
    cout <<"Nome: "      << this->_nome << endl;
    cout <<"Matricula: " << this->_matricula << endl;
    cout <<"IRA: "       << this->_matricula << endl; 
}
