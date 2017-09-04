#include <string>
#include <stdexcept>

using namespace std;

#include "BEQ.hpp" 
#include "BeqFalso.hpp"

BeqFalso::BeqFalso(string nombreLabel, size_t r1, size_t r2): InstruccionFalsa(NombreInstruccion::Beq){
    this->r1 = r1;
    this->r2 = r2;
    this->nombreLabel = nombreLabel;
}

BeqFalso::BeqFalso(string nombreLabel, string r1, string r2): InstruccionFalsa(NombreInstruccion::Beq){
    this->r1 = this->storeg(r1);
    this->r2 = this->storeg(r2);
    this->nombreLabel = nombreLabel;
}
void BeqFalso::run(Estado &estado, LineaControl &lineaControl){
    throw logic_error("Error, Beq falso no se puede ejecutar");
}

Instruccion *BeqFalso::getReal(size_t pos){
    return new BEQ(pos, this->r1, this->r2);
}

string BeqFalso::getLabel(){
   return this->nombreLabel;
}
