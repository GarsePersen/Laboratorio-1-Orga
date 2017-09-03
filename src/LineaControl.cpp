#include <sstream>
#include <stdexcept>
#include "LineaControl.hpp"

LineaControl::LineaControl(){
    for(size_t i = 0; i < NUMERO_LINEAS_CONTROL; i++){
        this->registros[i] = 0;
    }
}


string LineaControl::toString() const{
    stringstream ss;
    
    for(size_t i = 0; i < NUMERO_LINEAS_CONTROL; i++){
        ss << i << "\t" << this->registros[i] << endl;
    }

    return ss.str();
}

void LineaControl::modificarLinea(size_t numero, int valor){
    this->registros[numero] = valor;
}
