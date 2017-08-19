#include <string>
#include <stdexcept>
using namespace std;

#include "JFalso.hpp"

JFalso::JFalso(string nombreLabel): Instruccion(NombreInstruccion::J){
    this->nombreLabel = nombreLabel;
}

void JFalso::run(Estado &estado){
    throw logic_error("Error, j falso no se puede ejecutar");
}


