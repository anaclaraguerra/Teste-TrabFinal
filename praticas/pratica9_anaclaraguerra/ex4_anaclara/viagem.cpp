#include "viagem.h"

Viagem::Viagem(std::string nome_arquivo)
{
    std::ifstream arq(nome_arquivo);
    if (!arq.is_open())
    {
        throw std::ifstream::failure("Impossivel abrir o arquivo.");
    }

    this->nFuncionarios = 0;

    while (arq.peek() != EOF)
    {
        std::string a;
        getline(arq, a);
        this->nFuncionarios++;
    }

    this->lFuncionarios = new Funcionario[nFuncionarios];

    arq = std::ifstream(nome_arquivo);
    if (!arq.is_open())
    {
        throw std::ifstream::failure("Impossivel abrir o arquivo.");
    }

    int cont = 0;
    while (arq.peek() != EOF)
    {
        arq >> this->lFuncionarios[cont].nome;
        arq.ignore(3);
        arq >> this->lFuncionarios[cont].gastoComViagem;
        this->gastoMensal += this->lFuncionarios[cont].gastoComViagem;
        cont++;
    }

    arq.close();
}

void Viagem::gerarRelatorio()
{
    for (int i = 0; i < this->nFuncionarios; i++)
    {
        for (int j = 0; j < this->nFuncionarios; j++)
        {
            if (this->lFuncionarios[i].gastoComViagem >= this->lFuncionarios[j].gastoComViagem)
            {
                Funcionario aux = lFuncionarios[i];
                lFuncionarios[i] = lFuncionarios[j];
                lFuncionarios[j] = aux;
            }
        }
    }
}

void Viagem::salvar()
{
    std::ofstream fout("relatorio.txt");
    if (!fout.is_open())
    {
        throw std::ofstream::failure("Impossivel criar o arquivo para salvar.");
    }

    fout << "Nro. Funcionario Gasto %\n";
    for (int i = 0; i < this->nFuncionarios; i++)
    {
        double percent = this->lFuncionarios[i].gastoComViagem * 100.0 / this->gastoMensal;
        fout << i + 1 << " " << this->lFuncionarios[i].nome << " R$" << this->lFuncionarios[i].gastoComViagem << " " << round(percent) << "%\n";
    }

    fout << "Gasto mensal total = R$" << this->gastoMensal << "\n";
    fout << "Gasto medio/funcionario = R$" << this->gastoMensal / this->nFuncionarios << "\n";
    fout.close();
}

Viagem::~Viagem(){
    delete[] this->lFuncionarios;
}