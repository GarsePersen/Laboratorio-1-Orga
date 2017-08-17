%{
    #include <iostream>
    #include <string>
    #include <cstdlib>
    #include <cstdio>
    
    using namespace std;

    extern "C" int yyparse (void);
    int yylex(int*);
    void yyerror(const char *);
%}

%token INSTRUCCION
%token NUMERO
%token LABEL
%token IDENTIFICADOR
%token REGISTROS
%token COMA
%token PARENTESIS1
%token PARENTESIS2
%token MEOF

%%


mips:
    linea mips
    |
    ;
    
linea: LABEL { cout << $1 << endl; }
    ;
    
    
 
%%      

void parse(const string &file){
    extern FILE *yyin;
    yyin=fopen(file.c_str(), "r");
    yyparse();
}
