#ifndef _H_INSTRUCCION_
#define _H_INSTRUCCION_

#include <string>
using namespace std;

#include "Estado.hpp"

enum class NombreInstruccion{
    Add,
    Sub,
    Addi,
    Subi,
    J,
    Beq,
    Mul,
    Div,
    Label
};

class Instruccion{
    protected:
        NombreInstruccion nombre;

        size_t storeg(string str);

    public:
        Instruccion(NombreInstruccion nombre);
        Instruccion(string nombre);

        virtual void run(Estado &estado) = 0;

        /*Retorna una reresentacion en string de la instruccion*/
        string toString() const;
};

#endif
