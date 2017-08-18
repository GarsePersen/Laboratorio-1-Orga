all:
	flex -l --header-file=lexico.h lexico.l 
	bison -d sintactico.y 
	g++ -c lex.yy.c -o lexer.o
	g++ -c sintactico.tab.c -o parser.o

