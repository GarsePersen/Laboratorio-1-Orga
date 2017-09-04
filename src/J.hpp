#ifndef _H_J_
#define _H_J_

#include <string>
using namespace std;
#include "Instruccion.hpp" 

class J: public Instruccion{
    private:
        size_t pos;
    public:
        J(size_t pos);
        void run(Estado &estado, LineaControl &lineaControl);
};

#endif 
