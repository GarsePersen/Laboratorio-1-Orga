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
    
    ss << "  RegDest  Jump  Branch MemRead MemToReg ALUOp MemWrite ALUSrc RegWrite\n"<< endl;
    for(size_t i = 0; i < NUMERO_LINEAS_CONTROL; i++){
	if(i==6){
            ss << this->registros[i] ;
	}else{
            ss << "      " << this->registros[i] ;

	}
    }
    return ss.str();
}

void LineaControl::modificarLinea(size_t numero, int valor){
    this->registros[numero] = valor;
}
