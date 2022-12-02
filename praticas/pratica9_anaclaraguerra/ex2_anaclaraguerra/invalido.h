#ifndef INAVLID_H
#define INVALID_H

#include <iostream>

class PosicaoInvalida: public std::exception(){
    virtual const char* what() const noexcept override;
};

#endif
