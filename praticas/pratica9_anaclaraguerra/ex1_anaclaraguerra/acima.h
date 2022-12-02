#ifndef ACIMA_H
#define ACIMA_H

#include "excecaosoma.h"
#include <iostream>

class ExcecaoAcimaDeX : public std::exception{
    public:
        virtual const char* what() const noexcept override;



};

#endif
