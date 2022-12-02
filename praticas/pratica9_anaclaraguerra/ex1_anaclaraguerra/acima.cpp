#include "excecaoacima.h"
#include <iostream>

const char* ExcecaoAcimaDeX::what() const noexcept {
    return "Soma ultrapassou o valor permitido!";
}