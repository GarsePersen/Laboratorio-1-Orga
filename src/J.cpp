#include "J.hpp"
#include "Instruccion.hpp"

J::J(size_t pos): Instruccion(NombreInstruccion::J){
    this->pos = pos;
}

void J::run(Estado &estado, LineaControl &lineaControl){
    estado.programCounter(this->pos);
    lineaControl.modificarLinea(0, 0);
    lineaControl.modificarLinea(1, 0);
    lineaControl.modificarLinea(2, 0);
    lineaControl.modificarLinea(3, 0);
    lineaControl.modificarLinea(4, 0);
    lineaControl.modificarLinea(5, 0);
    lineaControl.modificarLinea(6, 0);
    lineaControl.modificarLinea(7, 0);
    lineaControl.modificarLinea(8, 0);
    lineaControl.modificarLinea(9, 1);
}
