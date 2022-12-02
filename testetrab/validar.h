#include <string>
#include <iostream>
#include <exception>

class ValidarAtributos {
    public:
        void validarNome(std::string nome);
        std::string validarData(int dia, int mes, int ano);
        std::string validarCPF(std::string cpf);
        int validarAvaliacao(int avaliacao);
        std::string validarCargo(std::string cargo);
        std::string validarTelefone(std::string telefone);
        std::string validarHorario(std::string hora, std::string minuto);      //avaliar que horas o restaurante abre e fecha

/* std::string _nome;
        std::string _diacontrato;
        std::string _mescontrato;
        std::string _anocontrato;
        std::string _cpf;
        int _avaliacao;
        std::string _cargo;
        std::string _telefone;
        std::string _hora;
        std::string _minuto;
*/

};
