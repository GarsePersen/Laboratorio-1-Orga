#ifndef _H_BEQFALSO
#define _H_BEQFALSO

#include <string>
using namespace std;
#include "InstruccionFalsa.hpp" 

class BeqFalso: public InstruccionFalsa{
    private:
        string nombreLabel;
    public:
        BeqFalso(string nombreLabel);
        void run(Estado &estado);
        Instruccion *getReal(size_t pos);
        string getLabel();
};

#endif 
