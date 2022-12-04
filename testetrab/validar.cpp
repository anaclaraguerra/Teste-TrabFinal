#include "validar.h"
#include <string>
#include <iostream>
#include <stdexcept>
#include <locale.h>

std::string ValidarAtributos::validarNome(std::string nome){
    setlocale(LC_ALL, "pt_BR.UTF-8");
       for(int i=0; i< nome.size(); i++){
            if(isdigit(nome[i])){
                throw std::invalid_argument("Nome inválido!");
            }
       }

       return nome;
}


std::string ValidarAtributos::validarData(int dia, int mes, int ano) {
    setlocale(LC_ALL, "pt_BR.UTF-8");
      if((dia >= 1 && dia <= 31) && (mes >= 1 && mes <= 12) && (ano >= 1900 && ano <= 2060)) {    // verifica data ate 2060
            if ((dia == 29 && mes == 2) && ((ano % 4) == 0)) {
                // return ano mes dia << "\n";
            }
            if (dia <= 28 && mes == 2) {
                // return ano << "/" << mes << "/" << dia << "\n";
            }
            if ((dia <= 30) && (mes == 4 || mes == 6 || mes == 9 || mes == 11)) {
                // return ano << "/" << mes << "/" << dia << "\n";
            }
            if ((dia <=31) && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes ==8 || mes == 10 || mes == 12)) {
                // return ano << "/" << mes << "/" << dia << "\n";
            } else {
                throw std::invalid_argument("Data inválida!");
            }
        } else {
            throw std::invalid_argument("Data inválida!");
            }
}

std::string ValidarAtributos::validarCPF(std::string cpf){
    setlocale(LC_ALL, "pt_BR.UTF-8");
    for(int i=0; i< cpf.size(); i++){
        if(!isdigit(cpf[i]))
            throw std::invalid_argument("CPF inválido!\nDigite somente números!\n");
        if(cpf.size() > 11)
            throw std::overflow_error("CPF inválido!\n Quantidade digitada está acima de 11 números!\n");
        if(cpf.size() < 11)
            throw std::underflow_error("CPF inválido!\nQuantidade digitada está abaixo de 11 números!\n");
    }
        return cpf;
    
}

int ValidarAtributos::validarAvaliacao(int avaliacao){
    setlocale(LC_ALL, "pt_BR.UTF-8");
    if(avaliacao > 10 ){
        throw std::overflow_error("Valor acima de 10!");
    } else if(avaliacao < 0){
        throw std::underflow_error("Valor abaixo de 0!");
    } else {
        return avaliacao;
    }
}

std::string ValidarAtributos::validarTelefone(std::string telefone){
    setlocale(LC_ALL, "pt_BR.UTF-8");
    for(int i=0; i< telefone.size(); i++){
        if(!isdigit(telefone[i]))
            throw std::invalid_argument("Telefone inválido! Digite somente números!\n");
        if(telefone.size() != 9)
            throw std::overflow_error("Telefone inválido! Digite somente 9 números!\n");
        
        return telefone;
    }
}

std::string ValidarAtributos::validarHorario(std::string hora, std::string minuto){
    setlocale(LC_ALL, "pt_BR.UTF-8");
    for(int i=0; i<hora.size(); i++){
        for(int j=0; j<minuto.size(); j++){
            if(!isdigit(hora[i]) || !isdigit(minuto[j])){
                throw std::invalid_argument("Horario Inválido! Deverá conter apenas numeros\n");
            }
        }
    }
    unsigned int _hora, _minuto;
    _hora = stoi(hora);
    _minuto = stoi(minuto);

    if(_hora >= 24 || _minuto >= 60)
        throw std::overflow_error("Horário maior do que o permitido!\n");
        
    // return std::cout << hora << minuto;

}



