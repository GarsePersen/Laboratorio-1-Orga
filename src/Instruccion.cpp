#include "Instruccion.hpp"
#include <algorithm>
#include <locale>
#include <iostream>
#include <stdexcept>
using namespace std;


Instruccion::Instruccion(NombreInstruccion nombre){
    this->nombre = nombre;
}


Instruccion::Instruccion(string nombre){
    transform(nombre.begin(), nombre.end(), nombre.begin(), [](char c){ return tolower(c); });
    if(nombre == "addi"){
        this->nombre = NombreInstruccion::Addi;
    }else if(nombre == "subi"){
        this->nombre = NombreInstruccion::Subi;
    }else if(nombre =="label"){
        this->nombre == NombreInstruccion::Label;
    }else if(nombre =="j"){
        this->nombre == NombreInstruccion::J;
    }else{
        throw logic_error("Falta un caso en el constructor de string de Instruccion");
    }
}

string Instruccion::toString() const{
    switch(this->nombre){
        case NombreInstruccion::Add:
            return "Add";
        case NombreInstruccion::Sub:
            return "Sub";
        case NombreInstruccion::Addi:
            return "Addi";
        case NombreInstruccion::Subi:
            return "Subi";
        case NombreInstruccion::Label:
            return "Label";
        case NombreInstruccion::J:
            return "J";
        default:
	        return "Falta un caso en __LINE__";
    }
}


size_t Instruccion::storeg(string str){
    if(str == "$t0"){
        return 8;
    }else if(str == "$t1"){
        return 9;
    }else if(str == "$t2"){
        return 10;
    }else{
        throw logic_error("Falta un caso en storeg ");
    }
}
