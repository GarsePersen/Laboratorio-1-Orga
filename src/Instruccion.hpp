#ifndef _H_INSTRUCCION_
#define _H_INSTRUCCION_

#include <string>
using namespace std;

#include "Estado.hpp"

enum class NombreInstruccion{
    Add,
    Sub,
    Addi,
    Subi
};

class Instruccion{
    protected:
        NombreInstruccion nombre;
    public:
        Instruccion(NombreInstruccion nombre);

	virtual void run(Estado &estado) = 0;

	/*Retorna una reresentacion en string de la instruccion*/
	string toString() const;
};

#endif
