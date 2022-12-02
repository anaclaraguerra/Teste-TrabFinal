#include "excecaosoma.h"
#include "acima.h"
#include <iostream>

int main(){

    try{
        ExcecaoSoma es = ExcecaoSoma(99,4);
        es.Soma();
    } catch (std::invalid_argument &e){
        std::cout << e.what();
    } catch(std::overflow_error &e){
        std::cout << e.what();
    }
}