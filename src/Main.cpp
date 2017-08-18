#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

#include "Instruccion.hpp"
#include "Estado.hpp"
#include "TipoInmediato.hpp"
#include "parser/sintactico.tab.h"

extern void parse(const string &file);


int main(int argc, char **argv){

    parse("prueba.asm");
    return 0;


    cout << "Hola mundo" << endl;

    //Instruccion inst(NombreInstruccion::Add);
    //cout << inst.toString() << endl;
    Estado estado;


    vector<Instruccion*> programa;

    programa.push_back(new TipoInmediato(NombreInstruccion::Addi, 11, 0, 1));
    programa.push_back(new TipoInmediato(NombreInstruccion::Addi, 11, 11, 2));


    try{
        bool end_program = false;
        while(!end_program){
            auto i = programa.at(estado.programCounter());
            i->run(estado);
            cout << estado.toString() << endl;
        }
    }catch(logic_error e){
        cerr << "Error: " << e.what() << endl;
        return -1;
    }


    cout << estado.toString() << endl;
    cout << "Hola mundo" << endl;

    return 0;
}
