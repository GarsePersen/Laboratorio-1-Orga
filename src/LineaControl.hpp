#ifndef _H_LINEACONTROL_
#define _H_LINEACONTROL_

#include <string>
using namespace std;

#define NUMERO_LINEAS_CONTROL 10

class LineaControl{
    private:
        int registros[NUMERO_LINEAS_CONTROL];
    public:
        LineaControl();
        string toString() const;
        void modificarLinea(size_t numero, int valor);
};



#endif
