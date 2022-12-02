#ifndef POSICAO_H
#define POSICAO_H

#include <iostream>
#include <exception>
#include <vector>

PosicoesVector {
    private: 
        int _tamanho;
        vector <int> _nome(_tamanho);

    public:
        PosicoesVector(int y);
        void PreencherValores();

};

#endif