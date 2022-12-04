#include "usuario.h"

Usuario::Usuario(std::string nome, std::string endereco, std::string codigo, int tipoCodigo, int tipo, std::vector<Residuo> residuosUsuario){
  this->nome = nome;
  this->endereco = endereco;
  this->codigo = codigo;
  this->tipoCodigo = tipoCodigo;
  this->tipo = tipo;
  for(int i = 0; i < residuosUsuario.size(); i++){
    this->residuosUsuario.push_back(residuosUsuario[i]);
  }
}

Usuario::Usuario(){}

std::string Usuario::getNome(){
  return nome;
}

void Usuario::setNome(std::string nome){
  this->nome = nome;
}

std::string Usuario::getEndereco(){
  return endereco;
}

void Usuario::setEndereco(std::string endereco){
  this->endereco = endereco;
}

std::string Usuario::getCodigo(){
  return codigo;
}

void Usuario::setCodigo(std::string codigo){
  this->codigo = codigo;
}

int Usuario::getTipoCodigo(){
  return tipoCodigo;
}

void Usuario::setTipoCodigo(int tipoCodigo){
  this->tipoCodigo = tipoCodigo;
}

int Usuario::getTipo(){
  return tipo;
}

void Usuario::setTipo(int tipo){
  this->tipo = tipo;
}

std::vector<Residuo> Usuario::getResiduosUsuario(){
  return residuosUsuario;
}

void Usuario::setResiduosUsuario(std::vector<Residuo> residuosUsuario){
  for(int i = 0; i < residuosUsuario.size(); i++){
    this->residuosUsuario.push_back(residuosUsuario[i]);
  }
}
