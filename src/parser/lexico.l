%option noyywrap
%option yylineno
%{
#include <iostream>
#include <vector>
#include <string>
using namespace std;
#include "sintactico.tab.h"
extern vector<string> readed;
%}

identificador [a-zA-Z]+ 
registro $[a-zA-Z][a-zA-Z1-9]
numero (0x|0X)[0-9a-fA-F]+|[0-9]+|0[0-9]+

%%
\{	{return '{';}
\} {return '}';}
\( {return '(';}
\)	{return ')';}
\-	{return '-';}
\:	{return ':';}
\;	{return ';';}
\,	{return ',';}
\|	{return '|';}
\&	{return '&';}
\<	{return '<';}
\>	{return '>';}
\!	{return '!';}
\=	{return '=';}
\+	{return '+';}
\[	{return '[';}
\]	{return ']';}
\*	{return '*';}
\/	{return '/';}
\%	{return '%';}
" "	{;}
"\n" {;}
"\t"	{;}
"\r"	{;}
"\f"	{;}
{identificador} { readed.push_back(string(yytext)); return IDENTIFICADOR; }
{registro} { readed.push_back(string(yytext)); return REGISTRO; }
{numero} { readed.push_back(string(yytext)); return NUMERO; }
%%


