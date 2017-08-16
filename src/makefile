all: TipoInmediato.o Estado.o Instruccion.o Main.cpp 
	g++ -Wall -std=c++11 Main.cpp Instruccion.o Estado.o TipoInmediato.o -o lab1

Instruccion.o: Instruccion.cpp Instruccion.hpp
	g++ -Wall -c -std=c++11 Instruccion.cpp -o Instruccion.o
	

Estado.o: Estado.cpp Estado.hpp
	g++ -Wall -c -std=c++11 Estado.cpp -o Estado.o

TipoInmediato.o: TipoInmediato.cpp TipoInmediato.hpp
	g++ -Wall -c -std=c++11 TipoInmediato.cpp -o TipoInmediato.o
