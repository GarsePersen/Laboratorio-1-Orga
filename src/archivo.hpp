#ifndef _H_ARCHIVO_
#define _H_ARCHIVO_

#include <string>

using namespace std;

class Archivo{
    private:
        string nombre; 
    public:
        Archivo(string nombre);
	    void leerArchivo();
	    void escribirArchivo();
};

#endif
