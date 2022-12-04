#include <string> 
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "residuo.h"
#include "usuario.h"
#include "coleta.h"

Usuario cadastrarUsuario(std::vector<Residuo> &listaResiduos);
Residuo cadastrarResiduo();
int verificarCodigo(std::string codigo);
int verificarCodigoNovo(std::string codigo, int tipoCodigo);
void listarUsuario(std::vector<Usuario> &listaUsuarios, int indice);
void listarResiduo(std::vector<Residuo> &listaResiduos, int indice);
void editarUsuario(std::vector<Usuario> &listaUsuarios, int indice);
void editarResiduo(std::vector<Residuo> &listaResiduos, int indice);
void excluirUsuario(std::vector<Usuario> &listaUsuarios, int indice);
void excluirResiduo(std::vector<Residuo> &listaResiduos, int indice);
int escolherUsuarios(std::vector<Usuario> &listaUsuarios);
int escolherResiduos(std::vector<Residuo> &listaResiduos);
void lerResiduos(std::vector<Residuo> &listaResiduos);
void lerUsuarios(std::vector<Usuario> &listaUsuarios, std::vector<Residuo> &listaResiduos);
Coleta agendarColeta(std::vector<Usuario> &listaUsuarios); 

int main(void)
{
  std::vector<Usuario> listaUsuarios;
  std::vector<Residuo> listaResiduos;
  lerUsuarios(listaUsuarios, listaResiduos);
  lerResiduos(listaResiduos);
  std::cout << std::endl;
  std::cout << "---BEM VINDO---\n";

  int opcao, indice;

  while (true)
  {
    std::cout << std::endl;
    std::cout << "Digite o codigo relacionado a opcao que deseja:\n";
    std::cout << "0 - Cadastrar um Usuario\n";
    std::cout << "1 - Ver dados de um Usuario\n";
    std::cout << "2 - Editar os dados dados de um Usuario\n";
    std::cout << "3 - Excluir um Usuario\n";
    std::cout << "4 - Cadastrar um Residuo\n";
    std::cout << "5 - Ver dados de um Residuo\n";
    std::cout << "6 - Editar os dados dados de um Residuo\n";
    std::cout << "7 - Excluir um Residuo\n";
    std::cout << "8 - Agendar uma coleta\n";
    std::cout << "9 - Sair\n";

    std::cin >> opcao;
    switch (opcao)
    {
    case 0:
      listaUsuarios.push_back(cadastrarUsuario(listaResiduos));
      break;
    case 1:
      std::cout << std::endl;
      std::cout << "Deseja ver as informacoes de qual usuario:\n";
      indice = escolherUsuarios(listaUsuarios);
      listarUsuario(listaUsuarios, indice);
      break;
    case 2:
      std::cout << std::endl;
      std::cout << "Deseja editar as informacoes de qual usuario:\n";
      indice = escolherUsuarios(listaUsuarios);
      editarUsuario(listaUsuarios, indice);
      break;
    case 3:
      std::cout << std::endl;
      std::cout << "Deseja excluir qual usuario:\n";
      indice = escolherUsuarios(listaUsuarios);
      excluirUsuario(listaUsuarios, indice);
      break;
    case 4:
      listaResiduos.push_back(cadastrarResiduo());
    break;
    case 5:
      std::cout << std::endl;
      std::cout << "Deseja ver as informacoes de qual residuo:\n";
      indice = escolherResiduos(listaResiduos);
      listarResiduo(listaResiduos, indice);
      break;
    case 6:
      std::cout << std::endl;
      std::cout << "Deseja editar as informacoes de qual residuo:\n";
      indice = escolherResiduos(listaResiduos);
      editarResiduo(listaResiduos, indice);
      break;
    case 7:
      std::cout << std::endl;
      std::cout << "Deseja excluir qual residuo:\n";
      indice = escolherResiduos(listaResiduos);
      excluirResiduo(listaResiduos, indice);
      break;
    case 8:
      Coleta r = agendarColeta(listaUsuarios);
      break;
    }
  }
}

void lerUsuarios(std::vector<Usuario> &listaUsuario, std::vector<Residuo> &listaResiduos){
  std::vector<Residuo> residuosUsuario;
  std::ifstream fin("usuarios.txt");
  fin = std::ifstream("usuarios.txt");
  std::string nome, endereco, codigo;
  int tipoCodigo, tipo;
  while (fin.peek() != EOF)
    {
      fin.ignore();
      getline(fin, nome);
      getline(fin, endereco);
      fin >> codigo;
      if(codigo.length() == 11){
        tipoCodigo = 0;
      }else if(codigo.length() == 14){
        tipoCodigo = 1;
      }
      fin >> tipo;
      // residuosUsuario.push_back(listaResiduos[1]); isso nao executa entao deixei sem itens
      Usuario u(nome, endereco, codigo, tipoCodigo, tipo, residuosUsuario);
      listaUsuario.push_back(u);
    }
    fin.close();
}

void lerResiduos(std::vector<Residuo> &listaResiduos){
  std::ifstream fin("residuos.txt");
  fin = std::ifstream("residuos.txt");
  std::string nomeResiduo, formaArmazenamento;
  while (fin.peek() != EOF)
    {
      fin.ignore();
      getline(fin, nomeResiduo);
      getline(fin, formaArmazenamento);
      Residuo r(nomeResiduo, formaArmazenamento);
      listaResiduos.push_back(r);
    }
    fin.close();
}

Usuario cadastrarUsuario(std::vector<Residuo> &listaResiduos)
{
  std::string nome, endereco, codigo;
  int tipoCodigo, tipo, itens;
  std::vector<Residuo> residuosUsuario;
  std::vector<int> itensSelecionados;
  std::cout << std::endl;
  std::cout << "Nome: \n";
  std::cin.ignore();
  getline(std::cin, nome);
  std::cout << std::endl;
  std::cout << "Endereco: \n";
  getline(std::cin, endereco);
  std::cout << std::endl;
  std::cout << "CPF ou CNPJ: \n";
  std::cin >> codigo;
  tipoCodigo = verificarCodigo(codigo);
  if (tipoCodigo == 2)
  {
    while (true)
    {
      std::cout << std::endl;
      std::cout << "Por favor digite um CPF ou CNPJ valido: \n";
      std::cin >> codigo;
      tipoCodigo = verificarCodigo(codigo);
      if (tipoCodigo != 2)
      {
        break;
      }
    }
  }
  std::cout << std::endl;
  std::cout << "0 - Doador\n1 - Recptor\n";
  std::cin >> tipo;
  std::cout << std::endl;
  if(tipo == 0){
    std::cout << "Quais residuos ira doar? (digite -1 para encerrar)\n";
  }else{
    std::cout << "Quais residuos ira receber? (digite -1 para encerrar)\n";
  }
  bool itemDisponivel, certeza;
  while(true){
    for(int i = 0; i < listaResiduos.size(); i++){
      itemDisponivel = true;
      for(int j = 0; j < itensSelecionados.size(); j++){
        if(itensSelecionados[j] == i){
          itemDisponivel = false;
        }
      }
      if(itemDisponivel){
        std::cout << i << " - " << listaResiduos[i].getNome() << std::endl;
      }
    }
    std::cin >> itens;
    std::cout << std::endl;
    if(itens == -1){
      break;
    }else{
      std::cout << "Modo de armazenar esse tipo de residuo:\n" << listaResiduos[itens].getForma() << "\nTem certeza que quer adicionar o residuo a sua lista?\n0 - Nao\n1 - Sim\n";
      std::cin >> certeza;
      if(certeza){
        residuosUsuario.push_back(listaResiduos[itens]);
        itensSelecionados.push_back(itens);
      }
    }
    if(listaResiduos.size() == itensSelecionados.size()){
      std::cout << "Todos os itens ja foram slecionados!" << std::endl;
      break;
    }
  }
  Usuario usuario(nome, endereco, codigo, tipoCodigo, tipo, residuosUsuario);
  return usuario;
}

Residuo cadastrarResiduo(){
  std::string nome, formaArmazenamento;
  std::cout << std::endl;
  std::cout << "Nome: \n";
  std::cin.ignore();
  getline(std::cin, nome);
  std::cout << std::endl;
  std::cout << "Forma de Armazenamento: \n";
  getline(std::cin, formaArmazenamento);
  Residuo r(nome, formaArmazenamento);
  return r;
}

int verificarCodigo(std::string codigo)
{
  if (codigo.length() == 11)
  {
    return 0;
  }
  else if (codigo.length() == 14)
  {
    return 1;
  }
  else
  {
    return 2;
  }
}

int verificarCodigoNovo(std::string codigo, int tipoCodigo)
{
  if (tipoCodigo == 0)
  {
    if (codigo.length() == 11)
    {
      return 0;
    }
    else
    {
      return 2;
    }
  }
  else
  {
    if (codigo.length() == 14)
    {
      return 1;
    }
    else
    {
      return 2;
    }
  }
}

void listarUsuario(std::vector<Usuario> &listaUsuarios, int indice)
{
  std::vector<Residuo> residuosUsuario;
  std::cout << std::endl;
  std::cout << "Dados do " << listaUsuarios[indice].getNome() << std::endl;
  std::cout << "Endereco: " << listaUsuarios[indice].getEndereco() << std::endl;
  if (listaUsuarios[indice].getTipoCodigo() == 0)
  {
    std::cout << "CPF: " << listaUsuarios[indice].getCodigo() << std::endl;
  }
  else if (listaUsuarios[indice].getTipoCodigo() == 1)
  {
    std::cout << "CNPJ: " << listaUsuarios[indice].getCodigo() << std::endl;
  }
  if (listaUsuarios[indice].getTipo() == 0)
  {
    std::cout << "Tipo: Doador\n";
  }
  else if (listaUsuarios[indice].getTipo() == 1)
  {
    std::cout << "Tipo: Receptor\n";
  }
  residuosUsuario = listaUsuarios[indice].getResiduosUsuario();
  if(residuosUsuario.size() > 0){
    if(listaUsuarios[indice].getTipo() == 0){
      std::cout << "Itens possiveis para doar:\n";
    }else{
      std::cout << "Itens possiveis para receber:\n";
    }
    for(int i = 0; i < residuosUsuario.size(); i++){
    std::cout << " - " << residuosUsuario[i].getNome() << std::endl;
  }
  }
}

void listarResiduo(std::vector<Residuo> &listarResiduo, int indice)
{
  std::vector<Residuo> residuosUsuario;
  std::cout << std::endl;
  std::cout << "Residuo: " << listarResiduo[indice].getNome() << std::endl;
  std::cout << "Forma de armazenamento: " << listarResiduo[indice].getForma() << std::endl;
}

void editarUsuario(std::vector<Usuario> &listaUsuarios, int indice)
{
  listarUsuario(listaUsuarios, indice);
  std::cout << "\nQual dado gostaria de editar?\n";
  std::cout << "0 - Nome\n";
  std::cout << "1 - Endereco\n";
  if (listaUsuarios[indice].getTipoCodigo() == 0)
  {
    std::cout << "2 - CPF\n";
  }
  else if (listaUsuarios[indice].getTipoCodigo() == 1)
  {
    std::cout << "2 - CNPJ\n";
  }
  std::cout << "3 - Tipo\n";
  int opcao;
  std::cin >> opcao;
  std::cout << std::endl;
  std::string novoNome, novoEndereco, novoCodigo;
  int novoTipo, novoTipoCodigo;
  switch (opcao)
  {
  case 0:
    std::cout << "Digite o novo nome:\n";
    std::cin.ignore();
    getline(std::cin, novoNome);
    listaUsuarios[indice].setNome(novoNome);
    break;
  case 1:
    std::cout << "Digite o novo endereco:\n";
    std::cin.ignore();
    getline(std::cin, novoEndereco);
    listaUsuarios[indice].setEndereco(novoEndereco);
    break;
  case 2:
    if (listaUsuarios[indice].getTipoCodigo() == 0)
    {
      std::cout << "Digite o novo CPF:\n";
    }
    else if (listaUsuarios[indice].getTipoCodigo() == 1)
    {
      std::cout << "Digite o novo CNPJ:\n";
    }
    std::cin >> novoCodigo;
    novoTipoCodigo = verificarCodigoNovo(novoCodigo, listaUsuarios[indice].getTipoCodigo());
    if (novoTipoCodigo == 2)
    {
      while (true)
      {
        std::cout << std::endl;
        if (listaUsuarios[indice].getTipoCodigo() == 0)
        {
          std::cout << "Por favor digite um CPF valido: \n";
        }
        else if (listaUsuarios[indice].getTipoCodigo() == 1)
        {
          std::cout << "Por favor digite um CNPJ valido: \n";
        }
        std::cin >> novoCodigo;
        novoTipoCodigo = verificarCodigoNovo(novoCodigo, listaUsuarios[indice].getTipoCodigo());
        if (novoTipoCodigo != 2)
        {
          break;
        }
      }
    }
    listaUsuarios[indice].setCodigo(novoCodigo);
    break;
  case 3:
    std::cout << std::endl;
    std::cout << "0 - Doador\n1 - Recptor\n";
    std::cin >> novoTipo;
    listaUsuarios[indice].setTipo(novoTipo);
    break;
  }
}

void editarResiduo(std::vector<Residuo> &listaResiduos, int indice)
{
  listarResiduo(listaResiduos, indice);
  std::cout << "\nQual dado gostaria de editar?\n";
  std::cout << "0 - Nome\n";
  std::cout << "1 - Forma de armazenamento\n";
  std::string novoNome, novaForma;
  int opcao;
  std::cin >> opcao;
  switch (opcao)
  {
  case 0:
    std::cout << "Digite o novo nome:\n";
    std::cin.ignore();
    getline(std::cin, novoNome);
    listaResiduos[indice].setNome(novoNome);
    break;
  case 1:
    std::cout << "Digite a nova forma de armazenamento:\n";
    std::cin.ignore();
    getline(std::cin, novaForma);
    listaResiduos[indice].setForma(novaForma);
    break;
  }
}

void excluirUsuario(std::vector<Usuario> &listaUsuarios, int indice)
{
  listaUsuarios.erase(listaUsuarios.begin() + indice);
}

void excluirResiduo(std::vector<Residuo> &listaResiduos, int indice)
{
  listaResiduos.erase(listaResiduos.begin() + indice);
}

int escolherUsuarios(std::vector<Usuario> &listaUsuarios)
{
  for (int i = 0; i < listaUsuarios.size(); i++)
  {
    std::cout << i << " - " << listaUsuarios[i].getNome() << std::endl;
  }
  int opcao;
  std::cin >> opcao;
  return opcao;
}

int escolherResiduos(std::vector<Residuo> &listaResiduos)
{
  for (int i = 0; i < listaResiduos.size(); i++)
  {
    std::cout << i << " - " << listaResiduos[i].getNome() << std::endl;
  }
  int opcao;
  std::cin >> opcao;
  return opcao;
}

Coleta agendarColeta(std::vector<Usuario> &listaUsuarios){ 
  int opcaoDoador, opcaoReceptor, opcaoResiduo;
  std::cout << "Quem sera o doador?\n";
  for(int i = 0; i < listaUsuarios.size(); i++){
    if(listaUsuarios[i].getTipo() == 0){
      std::cout << i << " - " << listaUsuarios[i].getNome() << std::endl;
    }
  }
  std::cin >> opcaoDoador;
  std::cout << "Quem sera o receptor?\n";
  for(int i = 0; i < listaUsuarios.size(); i++){
    if(listaUsuarios[i].getTipo() == 1){
      std::cout << i << " - " << listaUsuarios[i].getNome() << std::endl;
    }
  }
  std::cin >> opcaoReceptor;
  std::cout << "Qual residuo sera doado?\n";
  for(int i = 0; i < listaUsuarios[opcaoDoador].getResiduosUsuario().size(); i++){
    std::cout << i << " - " << listaUsuarios[opcaoDoador].getResiduosUsuario()[i].getNome() << std::endl;
  }
  std::cin >> opcaoResiduo;
  bool possivel;
  while(true){
    possivel = false;
    for(int i = 0; i < listaUsuarios[opcaoReceptor].getResiduosUsuario().size(); i++){
      if(listaUsuarios[opcaoDoador].getResiduosUsuario()[i].getNome() == listaUsuarios[opcaoReceptor].getResiduosUsuario()[i].getNome()){
        possivel = true;
      }
    }
    if(possivel){
      break;
    }else{
      std::cout << "O receptor selecionado nao pode receber o residuo selecionado, favor selecionar outro:\n";
      for(int i = 0; i < listaUsuarios[opcaoDoador].getResiduosUsuario().size(); i++){
        std::cout << i << " - " << listaUsuarios[opcaoDoador].getResiduosUsuario()[i].getNome() << std::endl;
      }
      std::cin >> opcaoResiduo;
    }
  }
  Coleta r(listaUsuarios[opcaoDoador], listaUsuarios[opcaoReceptor], listaUsuarios[opcaoDoador].getResiduosUsuario()[opcaoResiduo]);
  return r;
}