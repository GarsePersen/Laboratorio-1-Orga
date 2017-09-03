#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

#include "Instruccion.hpp"
#include "LineaControl.hpp"
#include "Estado.hpp"
#include "TipoInmediato.hpp"
#include "parser/sintactico.tab.h"

extern void parse(const string &file);
extern vector<Instruccion*> getInstrucciones();
void transformarLabels(vector<Instruccion*> &instrucciones);
int mymain();

int main(int argc, char **argv){
    try{
        return mymain();
    }catch(logic_error error){
        cerr << error.what() << endl;
    }catch(...){
        cerr << "Error" << endl;
    }
}

int mymain(){
    parse("prueba.asm");

    vector<Instruccion*> programa = getInstrucciones();

    ////cout << programa.size() << endl;
       
    transformarLabels(programa); 
     
    Estado estado;
    LineaControl lineaControl;

    try{
        bool end_program = false;
        while(!end_program){
            //cout << estado.toString() << endl;
            auto i = programa.at(estado.programCounter());
            i->run(estado);
	    cout << lineaControl.toString() << endl;
        }
    }catch(logic_error e){
        cerr << "Error: " << e.what() << endl;
        return -1;
    }
    return 0;
    for(auto i: programa){
        cout << i->toString() << endl;
    }

    return 0;

    //cout << "--fin--" << endl;
    


    cout << "Hola mundo" << endl;

    //Instruccion inst(NombreInstruccion::Add);
    //cout << inst.toString() << endl;
    
    /* Lectura de archivo */

    /*switch(argc){
        case 2: {   
            Archivo archivo(argv[1]);
            break;
        }
        default:
            cout << "faltan argumentos" << endl;
            return -1;
    }*/
    
    
    //Estado estado;

    try{
        bool end_program = false;
        while(!end_program){
            //cout << estado.toString() << endl;
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



