#include "SwLw.hpp"
#include <stdexcept>
#include <iostream>
using namespace std;

SwLw::SwLw(NombreInstruccion nombre, size_t r1, int offset, size_t r2): Instruccion(nombre){
    this->r1 = r1;
    this->r2 = r2;
    this->offset = offset;
}

SwLw::SwLw(string nombre, string r1, string offset, string r2): Instruccion(nombre){
    this->r1 = this->storeg(r1);
    this->r2 = this->storeg(r2);
    this->offset = stoi(offset);
}

void SwLw::run(Estado &estado, LineaControl &lineaControl){
    int result;
    switch(this->nombre){
        case NombreInstruccion::Lw:
	        result = estado.obtenerValor(this->r2);
            estado.modificarRegistro(this->r1, result);
            break;
        case NombreInstruccion::Sw:
            result = estado.obtenerValor(this->r1);
            estado.modificarRegistro(this->r2, result);
            break;
        default:
            throw logic_error("La instruccion no corresponde a un Save/Load word");
    }
    lineaControl.modificarLinea(0, 0); 
    lineaControl.modificarLinea(1, 0);
    lineaControl.modificarLinea(2, 0);
    lineaControl.modificarLinea(3, 0);
    lineaControl.modificarLinea(4, 0);
    lineaControl.modificarLinea(5, 0);
    lineaControl.modificarLinea(6, 0);
    lineaControl.modificarLinea(7, 0);
    lineaControl.modificarLinea(8, 1);
    lineaControl.modificarLinea(9, 1);
    estado.programCounter(estado.programCounter() + 1);
}
