FLAGS=-Wall -g -std=c++11

all: JFalso.o Label.o TipoInmediato.o Estado.o Instruccion.o Main.cpp 
	make -C parser
	g++ $(FLAGS) Main.cpp parser/lexer.o parser/parser.o Instruccion.o Estado.o TipoInmediato.o Label.o JFalso.o -o lab1

Instruccion.o: Instruccion.cpp Instruccion.hpp
	g++ $(FLAGS) -c Instruccion.cpp -o Instruccion.o
	

Estado.o: Estado.cpp Estado.hpp
	g++ $(FLAGS) -c Estado.cpp -o Estado.o

TipoInmediato.o: TipoInmediato.cpp TipoInmediato.hpp
	g++ $(FLAGS) -c TipoInmediato.cpp -o TipoInmediato.o

Label.o: Label.cpp Label.hpp
	g++ $(FLAGS) -c Label.cpp -o Label.o

JFalso.o: JFalso.cpp JFalso.hpp
	g++ $(FLAGS) -c JFalso.cpp -o JFalso.o

clear:
	rm *.o  
 
