#include "coleta.h"
#include "usuario.h"
#include "residuo.h"

Coleta::Coleta(Usuario doador, Usuario receptor, Residuo residuo){
  this->doador = doador;
  this->receptor = receptor;
  this-> residuo = residuo;
}

Coleta::Coleta(){}