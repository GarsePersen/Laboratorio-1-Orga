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
    cout << "\n" << endl;
    cout << valorR1 << endl;
    cout << valorR2 << endl;
    cout << counter << endl;
    cout << "\n" << endl;
    if(valorR1 == valorR2){
    	estado.programCounter(this->pos);
    }else{
        estado.programCounter(counter+1);
    }
}
