#ifndef COLETA
#define COLETA

#include "usuario.h"
#include "residuo.h"

class Coleta {
  private:
    Usuario doador;
    Usuario receptor;
    Residuo residuo;
  public:
    Coleta(Usuario doador, Usuario receptor, Residuo residuo);
    Coleta();
};

#endif