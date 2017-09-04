#include "TipoR.hpp"
#include <stdexcept>
using namespace std;

TipoR::TipoR(NombreInstruccion nombre, size_t r1, size_t r2, size_t r3): Instruccion(nombre){
    this->r1 = r1;
    this->r2 = r2;
    this->r3 = r3;
}

TipoR::TipoR(string nombre, string r1, string r2, string r3): Instruccion(nombre){
    this->r1 = this->storeg(r1);
    this->r2 = this->storeg(r2);
    this->r3 = this->storeg(r3);
}

void TipoR::run(Estado &estado, LineaControl &lineaControl){
    int valorR2 = estado.obtenerValor(this->r2);
    int valorR3 = estado.obtenerValor(this->r3);
    int result;
    
    switch(this->nombre){
        case NombreInstruccion::Add:
            /*Camino de datos del add */
            result = valorR2 + valorR3;
            break;
        case NombreInstruccion::Sub:
            result = valorR2 - valorR3;
            break;
	case NombreInstruccion::Mul:
	    result = valorR2 * valorR3;
	    break;
	case NombreInstruccion::Div:
	    result = valorR2 / valorR3;
	    break;
        default:
            throw logic_error("La instruccion no corresponde a un TipoR");
    }

    estado.programCounter(estado.programCounter() + 1);
    estado.modificarRegistro(this->r1, result);
}

