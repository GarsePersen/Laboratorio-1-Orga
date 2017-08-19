#include "TipoInmediato.hpp"
#include <stdexcept>
using namespace std;

TipoInmediato::TipoInmediato(NombreInstruccion nombre, size_t r1, size_t r2, int valor): Instruccion(nombre){
    this->r1 = r1;
    this->r2 = r2;
    this->valor = valor;
}

TipoInmediato::TipoInmediato(string nombre, string r1, string r2, string valor): Instruccion(nombre){
    this->r1 = this->storeg(r1);
    this->r2 = this->storeg(r2);
    this->valor = stoi(valor);
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
           throw logic_error("La instruccion no corresponde a un TipoInmediato");
    }

    estado.programCounter(estado.programCounter() + 1);
    estado.modificarRegistro(this->r1, result);
}

