#include <cstring>
#include <iostream>
#include <cctype>
#include <exception>

class ValidarAtributos(){
    private:
        std::string _nome;
        std::string _diacontrato;
        std::string _mescontrato;
        std::string _anocontrato;
        std::string _cpf;
        int _avaliacao;
        std::string _cargo;
        std::string _telefone;
        std::string _hora;
        std::string _minuto;
    public:
        void validarNome(std::string nome);
        void validarData(std::string dia, std::string mes, std::string ano);
        void validarCPF(std::string cpf);
        void validarAvaliacao(int avaliacao);
        void validarCargo(std::string cargo);
        void validarTelefone(std::string telefone);
        void validarHorario(std::string hora, std::string minuto);      //avaliar que horas o restaurante abre e fecha



};

#endif