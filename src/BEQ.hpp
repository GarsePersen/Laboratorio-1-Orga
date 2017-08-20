#ifndef _H_BEQ
#define _H_BEQ

#include <string>
using namespace std;
#include "Instruccion.hpp" 

class JFalso: public Instruccion{
    private:
       string nombreLabel;
    public:
        BEQ(string nombreLabel);
        void run(Estado &estado);
};

#endif 
