#ifndef RESIDUO
#define RESIDUO

#include <string>
#include <iostream>

class Residuo
{
    private:
        std::string nome;
        std::string formaArmazenamento;
    public:
        Residuo(std::string nome, std::string formaArmazenamento);
        Residuo();
        std::string getNome();
        void setNome(std::string nome);
        std::string getForma();
        void setForma(std::string formaArmazenamento);
};

#endif