#include <iostream>
#include "arquivo.h"

ArquivoIP::ArquivoIP(std::string nome_arquivo)
{
    this->file_lines = 0;
    std::ifstream fin("entrada.txt");
    if (!fin.is_open())
    {
        throw std::ifstream::failure("Impossivel abrir o arquivo");
    }

    while (fin.peek() != EOF)
    {
        std::string a;
        fin >> a;
        this->file_lines++;
    }

    this->ips = new IP[this->file_lines];
    fin = std::ifstream("entrada.txt");
    if (!fin.is_open())
    {
        throw std::ifstream::failure("Impossivel abrir o arquivo");
    }

    int count = 0;
    while (fin.peek() != EOF)
    {
        char discart;
        fin >> this->ips[count].octeto1;
        fin >> discart;
        fin >> this->ips[count].octeto2;
        fin >> discart;
        fin >> this->ips[count].octeto3;
        fin >> discart;
        fin >> this->ips[count].octeto4;
        count++;
    }

    fin.close();
}

void ArquivoIP::validate()
{
    for (int i = 0; i < this->file_lines; i++)
    {
        if (
            this->ips[i].octeto1 > 255 ||
            this->ips[i].octeto2 > 255 ||
            this->ips[i].octeto3 > 255 ||
            this->ips[i].octeto4 > 255)
        {
            this->ips[i].valido = false;
        }
        else
        {
            this->ips[i].valido = true;
        }
    }
}
void ArquivoIP::save()
{
    std::ofstream fout("ips.txt");
    if (!fout.is_open())
    {
        throw std::ofstream::failure("Impossivel criar o arquivo para salvar.");
    }

    fout << "[Enderecos validos:]\n";
    for (int i = 0; i < this->file_lines; i++)
    {
        if (this->ips[i].valido)
        {
            fout << this->ips[i].octeto1 << "."
                 << this->ips[i].octeto2 << "."
                 << this->ips[i].octeto3 << "."
                 << this->ips[i].octeto4 << "\n";
        }
    }

    fout << "\n[Enderecos invalidos:]\n";
    for (int i = 0; i < this->file_lines; i++)
    {
        if (!this->ips[i].valido)
        {
            fout << this->ips[i].octeto1 << "."
                 << this->ips[i].octeto2 << "."
                 << this->ips[i].octeto3 << "."
                 << this->ips[i].octeto4 << "\n";
        }
    }

    fout.close();
}
ArquivoIP::~ArquivoIP()
{
    delete[] this->ips;
}
