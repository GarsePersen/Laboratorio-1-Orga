%{
enum Lexema {
    INSTRUCCION,
    NUMERO,
    LABEL,
    IDENTIFICADOR,
    REGISTROS,
    COMA,
    PARENTESIS1,
    MEOF,
    PARENTESIS2
};

%}


%option noyywrap

instruccion [a-zA-Z]+

numero (0x|0X)[0-9a-fA-F]+|[0-9]+|0[0-9]+

label [a-zA-Z]+[a-zA-Z0-9_]*:

identificador [a-zA-Z]+[a-zA-Z0-9_]* 

registros $[a-z][0-9a-z]|$zero

coma ,

parentesis1 (

parentesis2 )

%%

instruccion { return INSTRUCCION; }
numero { return NUMERO; }
label { return LABEL; }
identificador { return IDENTIFICADOR; }
registros { return REGISTROS; }
coma { return COMA; }
parentesis1 { return PARENTESIS1; }
parentesis2 { return PARENTESIS2; }
eof { return MEOF; }
%%
	
