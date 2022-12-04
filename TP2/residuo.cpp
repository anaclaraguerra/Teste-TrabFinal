#include "residuo.h"

Residuo::Residuo(std::string nome, std::string formaArmazenamento){
    this-> nome = nome;
    this->formaArmazenamento = formaArmazenamento;
}

Residuo::Residuo(){}

std::string Residuo::getNome(){
    return nome;
}

void Residuo::setNome(std::string nome){
    this->nome = nome;
}

std::string Residuo::getForma(){
    return formaArmazenamento;
}

void Residuo::setForma(std::string formaArmazenamento){
    this->formaArmazenamento = formaArmazenamento;
}