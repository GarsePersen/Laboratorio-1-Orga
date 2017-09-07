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
    }else if(nombre == "sw"){
        this->nombre = NombreInstruccion::Sw;
    }else if(nombre == "lw"){
        this->nombre = NombreInstruccion::Lw;
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
        case NombreInstruccion::Lw:
            return "Lw";
        case NombreInstruccion::Sw:
            return "Sw";
        default:
            return "Falta un caso en __LINE__";
    }
}


size_t Instruccion::storeg(string str){
    if(str == "$zero"){
        return 0;
    }else if(str == "$at"){
        return 1;
    }else if(str == "$v0"){
        return 2;
    }else if(str == "$v1"){
        return 3;
    }else if(str == "$a0"){
        return 4;    
    }else if(str == "$a1"){
        return 5;
    }else if(str == "$a2"){
        return 6;
    }else if(str == "$a3"){
        return 7;
    }else if(str == "$t0"){
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
    }else if(str == "$t6"){
        return 14;
    }else if(str == "$t7"){
        return 15; 
    }else if(str == "$s0"){
        return 16;
    }else if(str == "$s1"){
        return 17;
    }else if(str == "$s2"){
        return 18;
    }else if(str == "$s3"){
        return 19;
    }else if(str == "$s4"){
        return 20;
    }else if(str == "$s5"){
        return 21;
    }else if(str == "$s6"){
        return 22;
    }else if(str == "$s7"){
        return 23;
    }else if(str == "$t8"){
        return 24;
    }else if(str == "$t9"){
        return 25;
    }else if(str == "$k0"){
        return 26;
    }else if(str == "$k1"){
        return 27;
    }else if(str == "$gp"){
        return 28;
    }else if(str == "$sp"){
        return 29;
    }else if(str == "$fp"){
        return 30;
    }else if(str == "$ra"){
        return 31;
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
