#ifndef _H_JFALSO
#define _H_JFALSO

#include <string>
using namespace std;
#include "Instruccion.hpp" 

class JFalso: public Instruccion{
    private:
       string nombreLabel;
    public:
        JFalso(string nombreLabel);
        void run(Estado &estado);
};

#endif 
