all:
	flex -c++ lexico.l 
	bison -d -L c++ sintactico.y 
	g++ -c lex.yy.cc -o lexer.o
	g++ -c sintactico.tab.cc -o parser.o

