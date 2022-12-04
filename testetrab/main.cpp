#include "validar.h"
#include <iostream>
#include <cstring>
#include <exception>

int main(){
    ValidarAtributos v1;

    try{
    v1.validarNome("Julia 12");
    } catch (std::invalid_argument &e){
        std::cout << e.what() << "\n"; 
    }

    try{
    std::string nome = v1.validarNome("Julia Milk");
    std::cout << "Nome valido: " << nome << "\n";
    } catch (std::invalid_argument &e){
        std::cout << e.what();
    }

    try{
        std::string cpf = v1.validarCPF("52533866881");
        std::cout << "CPF valido: " << cpf << "\n";
    } catch (std::invalid_argument &e) {
        std::cout << e.what() << "\n";
    }

    try{
        std::string cpf = v1.validarCPF("873465463346375");
        std::cout << "CPF valido: " << cpf << "\n";
    } catch (std::invalid_argument &e) {
        std::cout << e.what() << "\n";
    }


    try{
        int avaliacao = v1.validarAvaliacao(-480);
        std::cout << "Avaliacao: " << avaliacao << "\n";
    } catch (std::invalid_argument &e){
        std::cout << e.what() << "\n";
    }

    try{
        std::string data = v1.validarData(81,12,2020);
        std::cout << "Data: " << data << "\n";
    } catch (std::invalid_argument &e){
        std::cout << e.what() << "\n";
    }


    return 0;
}