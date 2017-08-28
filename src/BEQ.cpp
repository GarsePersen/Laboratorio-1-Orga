#include "BEQ.hpp"
#include "Instruccion.hpp"

BEQ::BEQ(size_t pos): Instruccion(NombreInstruccion::Beq){
    this->pos = pos;
}

void BEQ::run(Estado &estado){
    estado.programCounter(this->pos);
}
