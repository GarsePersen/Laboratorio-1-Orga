FLAGS=-Wall -g -std=c++11

all: InstruccionFalsa.o JFalso.o J.o Label.o TipoInmediato.o Estado.o Instruccion.o Main.cpp 
	make -C parser
	g++ $(FLAGS) Main.cpp parser/lexer.o parser/parser.o Instruccion.o Estado.o TipoInmediato.o Label.o JFalso.o J.o InstruccionFalsa.o -o lab1

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

InstruccionFalsa.o: InstruccionFalsa.cpp InstruccionFalsa.hpp
	g++ $(FLAGS) -c InstruccionFalsa.cpp -o InstruccionFalsa.o

J.o: J.cpp J.hpp
	g++ $(FLAGS) -c J.cpp -o J.o

clear:
	rm *.o  
 
