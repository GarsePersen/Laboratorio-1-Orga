#include "Instruccion.hpp"


Instruccion::Instruccion(NombreInstruccion nombre){
    this->nombre = nombre;
}

string Instruccion::toString(){
    switch(this->nombre){
        case NombreInstruccion::Add:
            return "Add";
        case NombreInstruccion::Sub:
            return "Sub";
        default:
	    return "Falta un caso en __LINE__";
    }
}
