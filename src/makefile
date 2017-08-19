FLAGS=-Wall -std=c++11

all: Archivo.o TipoInmediato.o Estado.o Instruccion.o Main.cpp 
	make -C parser
	g++ $(FLAGS) Main.cpp parser/lexer.o parser/parser.o Instruccion.o Estado.o TipoInmediato.o Archivo.o -o lab1

Instruccion.o: Instruccion.cpp Instruccion.hpp
	g++ $(FLAGS) -c Instruccion.cpp -o Instruccion.o
	

Estado.o: Estado.cpp Estado.hpp
	g++ $(FLAGS) -c Estado.cpp -o Estado.o

TipoInmediato.o: TipoInmediato.cpp TipoInmediato.hpp
	g++ $(FLAGS) -c TipoInmediato.cpp -o TipoInmediato.o

Archivo.o: Archivo.cpp Archivo.hpp
	g++ $(FLAGS) -c Archivo.cpp -o Archivo.o

