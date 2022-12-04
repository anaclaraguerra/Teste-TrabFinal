#ifndef USUARIO
#define USUARIO

#include <string>
#include <iostream>
#include <vector>
#include "residuo.h"

class Usuario
{
private:
  std::string nome;
  std::string endereco;
  std::string codigo; // cpf ou cnpj
  int tipoCodigo;     // 0 = cpf, 1 = cnpj
  int tipo;           // 0 = doador, 1 = receptor
  std::vector<Residuo> residuosUsuario;

public:
  Usuario(std::string nome, std::string endereco, std::string codigo, int tipoCodigo, int tipo, std::vector<Residuo> residuosUsuario);
  Usuario();
  std::string getNome();
  void setNome(std::string nome);
  std::string getEndereco();
  void setEndereco(std::string endereco);
  std::string getCodigo();
  void setCodigo(std::string codigo);
  int getTipoCodigo();
  void setTipoCodigo(int tipoCodigo);
  int getTipo();
  void setTipo(int tipo);
  std::vector<Residuo> getResiduosUsuario();
  void setResiduosUsuario(std::vector<Residuo> residuosUsuario);
};

#endif