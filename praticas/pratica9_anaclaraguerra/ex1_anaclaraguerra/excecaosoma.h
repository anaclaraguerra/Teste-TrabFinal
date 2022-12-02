EXCECAOSOMA.H


#ifndef EXCECAO_H
#define EXCECAO_H

#include <exception>

class ExcecaoSoma{
    private:
        int _x;
        int _n;
        int _soma = 0;
        int _numeros;
    public:
        ExcecaoSoma(int x, int n);
        void Soma();
       
};

#endif