#include <string>
#include <stdexcept>
using namespace std;

#include "BEQ.hpp"

BEQ::BEQ(string nombreLabel): Instruccion(NombreInstruccion::J){
    this->nombreLabel = nombreLabel;
}

void JFalso::run(Estado &estado){
    throw logic_error("Error, j falso no se puede ejecutar");
}


