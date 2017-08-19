#include <string>
#include <stdexcept>
using namespace std;

#include "Label.hpp"

Label::Label(string nombre): Instruccion(NombreInstruccion::Label){
    this->nombre = nombre;
}

void Label::run(Estado &estado){
    throw logic_error("Error, label no se puede ejecutar");
}


