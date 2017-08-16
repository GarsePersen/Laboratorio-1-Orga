#include <sstream>
#include <stdexcept>
#include "Estado.hpp"

Estado::Estado(){
    for(size_t i = 0; i < NUMERO_REGISTROS; i++){
        this->registros[i] = 0;
    }
}

void Estado::verificarRegistro(size_t numero) const{
    if(numero < 0 || numero > NUMERO_REGISTROS){
        throw logic_error("Error en el numero de registro");
    }
	
    switch(numero){
        case 0: {
	    stringstream ss;
	    ss << "No se puede modificar el registro: " << numero;
            throw logic_error(ss.str());
        }
        default:
	    break;    
    }
}

void Estado::modificarRegistro(size_t numero, int valor){
    this->verificarRegistro(numero); 

    this->registros[numero] = valor;
}



int Estado::obtenerValor(size_t numero) const{
    return this->registros[numero];
}

int Estado::programCounter(){
    return this->obtenerValor(32);
}

void Estado::programCounter(int val){
    return this->modificarRegistro(32, val);
}

string Estado::toString() const{
    stringstream ss;
    
    for(size_t i = 0; i < NUMERO_REGISTROS; i++){
        ss << i << "\t" << this->registros[i] << endl;
    }

    return ss.str();
}
