#include "Instruccion.hpp"


Instruccion::Instruccion(NombreInstruccion nombre){
    this->nombre = nombre;
}

string Instruccion::toString() const{
    switch(this->nombre){
        case NombreInstruccion::Add:
            return "Add";
        case NombreInstruccion::Sub:
            return "Sub";
        case NombreInstruccion::Addi:
            return "Addi";
        case NombreInstruccion::Subi:
            return "Subi";
        default:
	    return "Falta un caso en __LINE__";
    }
}
