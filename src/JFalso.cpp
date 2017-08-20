#include <string>
#include <stdexcept>
using namespace std;

#include "JFalso.hpp"
#include "J.hpp"

JFalso::JFalso(string nombreLabel): InstruccionFalsa(NombreInstruccion::J){
    this->nombreLabel = nombreLabel;
}

void JFalso::run(Estado &estado){
    throw logic_error("Error, j falso no se puede ejecutar");
}

Instruccion *JFalso::getReal(size_t pos){
   return new J(pos);
}


string JFalso::getLabel(){
   return this->nombreLabel;
}
