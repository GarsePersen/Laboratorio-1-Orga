#ifndef _H_BEQ
#define _H_BEQ

#include <string>
using namespace std;
#include "Instruccion.hpp" 

class BEQ: public Instruccion{
    private:
       size_t pos;
    public:
        BEQ(size_t pos);
        void run(Estado &estado);
};

#endif 
