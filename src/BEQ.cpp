#include "BEQ.hpp"
#include "Instruccion.hpp"

//Borrar despues
#include <iostream>

BEQ::BEQ(size_t pos, int r1, int r2): Instruccion(NombreInstruccion::Beq){
    this->pos = pos;
    this->r1 = r1;
    this->r2 = r2;
}

void BEQ::run(Estado &estado, LineaControl &lineaControl){
    int valorR1 = estado.obtenerValor(this->r1);
    int valorR2 = estado.obtenerValor(this->r2);
    int counter = estado.obtenerValor(32);
    if(valorR1 == valorR2){
    	estado.programCounter(this->pos);
        lineaControl.modificarLinea(0, -1);
        lineaControl.modificarLinea(1, 0);
        lineaControl.modificarLinea(2, 1);
        lineaControl.modificarLinea(3, 0);
        lineaControl.modificarLinea(4, -1);
        lineaControl.modificarLinea(5, 0);
        lineaControl.modificarLinea(6, 1);
        lineaControl.modificarLinea(7, 0);
        lineaControl.modificarLinea(8, 0);
        lineaControl.modificarLinea(9, 0);
    }else{
        estado.programCounter(counter+1);
    }
}
