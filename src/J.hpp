#ifndef _H_JFALSO
#define _H_JFALSO

#include <string>
using namespace std;
#include "Instruccion.hpp" 

class J: public Instruccion{
    private:
        size_t pos;
    public:
        J(size_t pos);
        void run(Estado &estado);
};

#endif 
