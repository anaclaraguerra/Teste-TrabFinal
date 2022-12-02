#ifndef FUNC_H
#define FUNC_H

#include <string>

class Funcionario{
    public:
        double gastoViagem;
        std::string nome;

        Funcionario();
        ~Funcionario();
        Funcionario(std::string nome, double gastoViagem);
        double getGastoViagem();
};

#endif