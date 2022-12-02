#include "posicao.h"
#include "invalido.h"
#include <iostream>

PosicoesVector::PosicoesVector(int y){
    this-> _tamanho = y;
}

void PosicoesVector::PreencherValores(){
    int i = 0;
    while(true){
        std::cout << "Digite um valor para a posicao " << i+1 << std::endl;
        cin >> _nome[i];
        i++;
    }

    if(i == _tamanho)
        throw PosicaoInvalida();
}