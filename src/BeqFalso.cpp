#include <string>
#include <stdexcept>
using namespace std;


#include "BEQ.hpp" 
#include "BeqFalso.hpp"

BeqFalso::BeqFalso(string nombreLabel): InstruccionFalsa(NombreInstruccion::Beq){
    this->nombreLabel = nombreLabel;
}

void BeqFalso::run(Estado &estado){
    throw logic_error("Error, Beq falso no se puede ejecutar");
}

Instruccion *BeqFalso::getReal(size_t pos){
   return new BEQ(pos);
}


string BeqFalso::getLabel(){
   return this->nombreLabel;
}
