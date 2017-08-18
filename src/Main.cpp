#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

#include "Instruccion.hpp"
#include "Estado.hpp"
#include "TipoInmediato.hpp"
#include "parser/sintactico.tab.h"
#include "Archivo.hpp"

extern void parse(const string &file);


int main(int argc, char **argv){

    //parse("prueba.asm");
    //cout << "--fin--" << endl;
    


    cout << "Hola mundo" << endl;

    //Instruccion inst(NombreInstruccion::Add);
    //cout << inst.toString() << endl;
    Estado estado;


    vector<Instruccion*> programa;

    programa.push_back(new TipoInmediato(NombreInstruccion::Addi, 11, 0, 1));
    programa.push_back(new TipoInmediato(NombreInstruccion::Addi, 11, 11, 2));
    programa.push_back(new TipoInmediato(NombreInstruccion::Subi, 11, 11, 4));


    try{
        bool end_program = false;
        while(!end_program){
            cout << estado.toString() << endl;
            auto i = programa.at(estado.programCounter());
            i->run(estado);
        }
    }catch(logic_error e){
        cerr << "Error: " << e.what() << endl;
        return -1;
    }


    cout << estado.toString() << endl;
    cout << "Hola mundo" << endl;

    return 0;
}
