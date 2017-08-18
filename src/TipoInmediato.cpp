#include "TipoInmediato.hpp"

TipoInmediato::TipoInmediato(NombreInstruccion nombre, size_t r1, size_t r2, int valor): Instruccion(nombre){
    this->r1 = r1;
    this->r2 = r2;
    this->valor = valor;
}

void TipoInmediato::run(Estado &estado){
    /* Camino de datos */
    int valorR2 = estado.obtenerValor(this->r2);
    int result;
    
    switch(this->nombre){
        case NombreInstruccion::Addi:
            /*Camino de datos del addi */
	    result = valorR2 + this->valor;
	    break;
        case NombreInstruccion::Subi:
            result = valorR2 - this->valor;
	    break;
        default:
           throw "La instruccion no corresponde a un TipoInmediato";
    }

    estado.programCounter(estado.programCounter() + 1);
    estado.modificarRegistro(this->r1, result);
}

