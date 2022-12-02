#ifndef VIAGEM_H
#define VIAGEM_H

#include "funcionario.h"

#include <string>
#include <fstream>
#include <exception>
#include <iostream>
#include <cmath>


class Viagem {
    private:
        Funcionario *lFuncionarios;
        double gastoMensal;
        int nFuncionarios;

    public:
        ~Viagem();
        Viagem(std::string nome_arquivo);
        void gerarRelatorio();
        void salvar();
        
};
#endif