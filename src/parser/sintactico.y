%{
    #include <iostream>
    #include <string>
    #include <cstdlib>
    #include <cstdio>
    #include "lexico.h"
    #include "sintactico.tab.h" 
    using namespace std;

    extern int yyparse (void);
    
    int yylex(int*);
    void yyerror(char *s);

    
    void parse(const string &file);
%}

%token INSTRUCCION
%token NUMERO
%token LABEL
%token IDENTIFICADOR
%token REGISTROS
%token COMA
%token PARENTESIS1
%token PARENTESIS2
%token SALTO
%token DOSPUNTOS
%token END

%%



mips: | mips linea;

linea: INSTRUCCION;
    
    
 
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
