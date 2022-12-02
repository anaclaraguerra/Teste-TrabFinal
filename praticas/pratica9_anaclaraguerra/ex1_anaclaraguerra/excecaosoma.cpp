#include "excecaosoma.h"
#include "excecaoacima.h"

#include <iostream>
#include <string>

ExcecaoSoma::ExcecaoSoma(int x, int n){
    this->_x = x;
    this->_n = n;
}

void ExcecaoSoma::Soma(){
    int i=0;
    while(true){
        std::cout << "Digite um numero\n";
        std::cin >> _numeros;
        if(_numeros > 100)
            throw std::overflow_error("Nao eh valido numeros maiores do que 100");
        if(_numeros <= 0)
            throw std::invalid_argument("Nao eh valido numeros menores ou iguais a 0");

        _soma += _numeros;
        i++;
        std::cout << "A soma foi:" << _soma << "\nA quantidade de numeros foram: " << i << "\nA media foi: " << _soma/i << std::endl;
    }

    if(_soma > _x){
        throw ExcecaoAcimaDeX();
    }
}