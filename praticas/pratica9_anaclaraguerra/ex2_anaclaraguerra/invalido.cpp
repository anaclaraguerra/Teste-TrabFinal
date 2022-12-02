#include "invalido.h"
#include <iostream>

const char* PosicaoInvalida::what() const noexcept {
    return "Posicao do vector invalida";
}