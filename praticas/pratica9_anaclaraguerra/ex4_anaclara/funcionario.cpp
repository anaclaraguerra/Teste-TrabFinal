#include "funcionario.h"

Funcionario::Funcionario(){}

Funcionario::~Funcionario(){
}

Funcionario::Funcionario(std::string nome, double gastoViagem){
    this->gastoViagem = gastoViagem;
    this->nome = nome;
}

double Funcionario::getGastoViagem(){
    return this->gastoViagem;
}

