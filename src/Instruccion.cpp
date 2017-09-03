#include "Instruccion.hpp"
#include "InstruccionFalsa.hpp"
#include "Label.hpp"
#include <algorithm>
#include <locale>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <forward_list>
#include <unordered_map>
#include <utility>
#include <sstream>
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
    }else if(nombre == "label"){
        this->nombre = NombreInstruccion::Label;
    }else if(nombre == "j"){
        this->nombre = NombreInstruccion::J;
    }else if(nombre == "beq"){
        this->nombre = NombreInstruccion::Beq;
    }else if(nombre == "add"){
        this->nombre = NombreInstruccion::Add;
    }else if(nombre == "sub"){
	this->nombre = NombreInstruccion::Sub;
    }else if(nombre == "mul"){
        this->nombre = NombreInstruccion::Mul;
    }else if(nombre == "div"){
        this->nombre = NombreInstruccion::Div;
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
	case NombreInstruccion::Beq:
	    return "Beq";
	case NombreInstruccion::J:
            return "J";
	case NombreInstruccion::Mul:
	    return "Mul";
	case NombreInstruccion::Div:
	    return "Div";
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
    }else if(str == "$t3"){
        return 11;
    }else if(str == "$t4"){
        return 12;
    }else if(str == "$t5"){
        return 13;
    }else{
        throw logic_error("Falta un caso en storeg ");
    }
}

void transformarLabels(vector<Instruccion*> &instrucciones){
    unordered_map<string, size_t> labels;
    forward_list<Label*> labelsElim;
    size_t posicion = 0;
    for(auto i: instrucciones){
        Label *lbl = dynamic_cast<Label*>(i);
        if(lbl){
            labels.insert(make_pair(lbl->getLabel(), posicion));
            labelsElim.push_front(lbl);
        }
        posicion++;
    }
    for(auto l: labelsElim){
        auto it = find(instrucciones.begin(), instrucciones.end(), l);
        if(it != instrucciones.end()){
            delete *it;
            instrucciones.erase(it);       
        }
    }
    for(auto it = instrucciones.begin(); it != instrucciones.end(); it++){
        InstruccionFalsa *inst = dynamic_cast<InstruccionFalsa*>(*it);
        if(inst){
            auto found = labels.find(inst->getLabel());
            if(found != labels.end()){
                Instruccion *nueva = inst->getReal((*found).second);
                *it = nueva;
            }else{
                stringstream ss;
                ss << "Label " << inst->getLabel() << " no encontrada";
                throw logic_error(ss.str());
            }
        }
    }
}
