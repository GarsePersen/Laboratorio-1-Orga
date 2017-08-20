#include "J.hpp"
#include "Instruccion.hpp"

J::J(size_t pos): Instruccion(NombreInstruccion::J){
    this->pos = pos;
}

void J::run(Estado &estado){
    estado.programCounter(this->pos);
}
