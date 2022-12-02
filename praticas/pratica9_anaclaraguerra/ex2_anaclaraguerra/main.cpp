#include "posicao.h"
#include <iostream>

int main(){
    int y = 0;

    std::cout << "digite o tamanho do vetor\n";
    std::cin >> y;

    PosicoesVector vec(y);

    vec.PreencherValores();

    return 0;
}