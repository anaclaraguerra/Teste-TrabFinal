#include "viagem.h"

int main(){

    Viagem *viagem = nullptr;

    try{
        viagem = new Viagem("funcionarios.txt");
    }
    catch (const std::ifstream::failure &e){
        std::cerr << e.what() << '\n';
        return 1;
    }

    viagem->gerarRelatorio();

    try{
        viagem->salvar();    
    }
    catch(const std::ofstream::failure& e){
        std::cerr << e.what() << '\n';
        delete viagem;
        return 1;
    }
    
    
    delete viagem;
    return 0;
}