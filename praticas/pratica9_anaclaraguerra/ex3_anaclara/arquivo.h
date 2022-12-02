#include <string>
#include <fstream>
#include <exception>
#include <iostream>

struct IP
{
    int octeto1;
    int octeto2;
    int octeto3;
    int octeto4;
    bool valido;
};


class ArquivoIP
{
private:
    IP *ips;
    int file_lines;
    
public:
    ArquivoIP(std::string nome_arquivo);
    void validate();
    void save();
    ~ArquivoIP();
    
};