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
    SALTO,
    PARENTESIS2,
    DOSPUNTOS
};

%}


%option noyywrap
%option yylineno


instruccion [a-zA-Z]

numero (0x|0X)[0-9a-fA-F]+|[0-9]+|0[0-9]+

identificador [a-zA-Z]+[a-zA-Z0-9_]* 

registros $[a-z][0-9a-z]|$zero

dospuntos :

coma ,

parentesis1 \(

parentesis2 \)

salto \n


%%

{instruccion} { return INSTRUCCION; }
{numero} { return NUMERO; }
{identificador} { return IDENTIFICADOR; }
{registros} { return REGISTROS; }
{dospuntos} { return DOSPUNTOS; }
{coma} { return COMA; }
{parentesis1} { return PARENTESIS1; }
{parentesis2} { return PARENTESIS2; }
{salto} { return SALTO; }

%%
	
