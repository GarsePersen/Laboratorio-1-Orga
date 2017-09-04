#include "TipoInmediato.hpp"
#include <stdexcept>
#include <iostream>
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

void TipoInmediato::run(Estado &estado, LineaControl &lineaControl){
    /* Camino de datos */
    int valorR2 = estado.obtenerValor(this->r2);
    int result;
    
    switch(this->nombre){
        case NombreInstruccion::Addi:
            /*Camino de datos del addi */
            //cout << "   0     0     0       0       0       00      0      1        0"<< endl;
	    lineaControl.modificarLinea(8, 1);
	    result = valorR2 + this->valor;
            break;
        case NombreInstruccion::Subi:
            //cout << "RegDest Jump Branch MemRead MemToReg ALUOp MemWrite ALUVSrc RegWrite"<< endl;
            //cout << "   0     0     0       0       0       00      0      1        0"<< endl;
            result = valorR2 - this->valor;
            break;
        default:
            throw logic_error("La instruccion no corresponde a un TipoInmediato");
    }

    estado.programCounter(estado.programCounter() + 1);
    estado.modificarRegistro(this->r1, result);
}

