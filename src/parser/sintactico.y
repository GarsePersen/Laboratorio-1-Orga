%{
	#include "sintactico.tab.h"
	#include <string>
    #include <cstdio>
    #include <iostream>
    #include <vector>
    #include "lexico.h"
    #include "../TipoInmediato.hpp"
    #include "../Instruccion.hpp"
    using namespace std;
	void yyerror(char *s);
	extern int yylineno;
    vector<string> readed;
    vector<Instruccion*> instrucciones;
    void crearTipoInmediato();

    vector<Instruccion*> getInstrucciones();
     
%}
%token IDENTIFICADOR
%token NUMERO
%token REGISTRO
%%

mips: linea mips 
    |
    ;

linea: IDENTIFICADOR REGISTRO ',' REGISTRO ',' NUMERO { crearTipoInmediato(); }
    ;

%%


void parse(const string &file){
    extern FILE *yyin;
    yyin=fopen(file.c_str(), "r");
    yyparse();
    fclose(yyin);
}


void yyerror(char *s) {
	printf("%s%i%s","Error sintactico en la linea: ", yylineno,".");
	exit(1);
}


void crearTipoInmediato(){
    Instruccion *inst = new TipoInmediato(readed.at(0), readed.at(1), readed.at(2), readed.at(3));
    instrucciones.push_back(inst);
    readed.clear();
}



vector<Instruccion*> getInstrucciones(){
    return instrucciones;
}
