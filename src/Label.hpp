#ifndef _H_LABE
#define _H_LABEL

#include <string>
using namespace std;
#include "Instruccion.hpp" 

class Label: public Instruccion{
    private:
       string nombre; 
    public:
        Label(string nombre);
        void run(Estado &estado);
        string getLabel() const;
};

#endif 
