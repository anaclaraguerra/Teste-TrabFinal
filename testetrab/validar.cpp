#include "validar.h"
#include <string>
#include <iostream>
#include <stdexcept>

void ValidarAtributos::validarNome(std::string nome){
       for(int i=0; i< nome.size(); i++){
            if(isdigit(nome[i])){
                throw std::invalid_argument("Nome inválido!");
            }
       } 
}


std::string ValidarAtributos::validarData(int dia, int mes, int ano) {
    if((dia >= 1 && dia <= 31) && (mes >= 1 && mes <= 12) && (ano >= 1900 && ano <= 2060)) {    // verifica data ate 2060
            if ((dia == 29 && mes == 2) && ((ano % 4) == 0)) {
                return ano << "/" << mes << "/" << dia << "\n";
            }
            if (dia <= 28 && mes == 2) {
                return ano << "/" << mes << "/" << dia << "\n";
            }
            if ((dia <= 30) && (mes == 4 || mes == 6 || mes == 9 || mes == 11)) {
                return ano << "/" << mes << "/" << dia << "\n";
            }
            if ((dia <=31) && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes ==8 || mes == 10 || mes == 12)) {
                return ano << "/" << mes << "/" << dia << "\n";
            } else {
                throw std::invalid_argument("Data inválida!");
            }
        } else {
            throw std::invalid_argument("Data inválida!");
            }
}

std::string ValidarAtributos::validarCPF(std::string cpf){
    for(int i=0; i< cpf.size(); i++){
        if(!isdigit(cpf[i]) || cpf.size() > 11){
            throw std::invalid_argument("CPF inválido!");
        } else
            return cpf;
    }
}

int ValidarAtributos::validarAvaliacao(int avaliacao){
    if(avaliacao > 10 ){
        throw std::overflow_error("Valor acima de 10!");
    } else if(avaliacao < 0){
        throw std::underflow_error("Valor abaixo de 0!");
    } else {
        return avaliacao;
    }
}

std::string ValidarAtributos::validarCargo(std::string cargo){
    if(cargo == 'G1' || cargo == 'G2'){
        return cargo;
    } else
        throw std::invalid_argument("Cargo invalido.\nDigite G1 para gerente\nDigite G2 para garçom!");

}

std::string ValidarAtributos::validarTelefone(std::string telefone){
    for(int i=0; i< telefone.size(); i++){
        if(!isdigit(telefone[i]) || telefone.size() > 9){
            throw std::invalid_argument("Telefone inválido!");
        } else
            return telefone;
    }
}

std::string ValidarAtributos::validarHorario(std::string hora, std::string minuto){
    for(int i=0; i<hora.size(); i++){
        for(int j=0; j<minuto.size(); j++){
            if(!isdigit(hora[i]) || !isdigit(minuto[j])){
                throw std::invalid_argument("Horario Inválido! Deverá conter apenas numeros");
            }
        }
    }
    int _hora, _minuto;
    _hora = stoi(hora);
    _minuto = stoi(minuto);

    if(_hora >= 24 || _minuto >= 60){
                throw std::overflow_error("Horário maior do que o permitido!");
            }

}



