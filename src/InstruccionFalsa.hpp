#ifndef _H_INSTRUCCIONFALSA
#define _H_INSTRUCCIONFALSA

#include <string>
using namespace std;

#include "Instruccion.hpp"

class InstruccionFalsa: public Instruccion{
    public:
        InstruccionFalsa(string nombre);
        InstruccionFalsa(NombreInstruccion nombre);
        virtual void run(Estado &estado) = 0;
        virtual string getLabel() = 0;
        virtual Instruccion *getReal(size_t pos) = 0;
};

#endif 
