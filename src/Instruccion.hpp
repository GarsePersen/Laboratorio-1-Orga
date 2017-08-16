#ifndef _H_INSTRUCCION_
#define _H_INSTRUCCION_

#include <string>
using namespace std;


enum class NombreInstruccion{
    Add,
    Sub
};

class Instruccion{
    private:
        NombreInstruccion nombre;
    public:
        Instruccion(NombreInstruccion nombre);

	/*Retorna una reresentacion en string de la instruccion*/
	string toString();
};

#endif
