#ifndef _H_JFALSO
#define _H_JFALSO

#include <string>
using namespace std;
#include "InstruccionFalsa.hpp" 

class JFalso: public InstruccionFalsa{
    private:
        string nombreLabel;
    public:
        JFalso(string nombreLabel);
        void run(Estado &estado);
        Instruccion *getReal(size_t pos);
        string getLabel();
};

#endif 
