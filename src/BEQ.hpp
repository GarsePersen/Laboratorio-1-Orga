#ifndef _H_BEQ
#define _H_BEQ

#include <string>
using namespace std;
#include "Instruccion.hpp" 

class BEQ: public Instruccion{
    private:
       size_t pos;
       int r1, r2;
    public:
        BEQ(size_t pos, int r1, int r2);
        void run(Estado &estado);
};

#endif 
