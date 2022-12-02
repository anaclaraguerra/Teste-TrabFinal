#include "arquivo.h"

int main()
{
    ArquivoIP *aip;

    try
    {
        aip = new ArquivoIP("entrada.txt");
    }
    catch(const std::ifstream::failure &e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    
   
    aip->validate();

    try
    {
        aip->save();
    }
    catch(const std::ofstream::failure &e)
    {
        std::cerr << e.what() << '\n';
        delete aip;
        return 1;
    }

    delete aip;
    return 0;
}