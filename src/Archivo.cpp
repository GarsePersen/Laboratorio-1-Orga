#include <sstream>
#include <string>
#include <iostream> 

#include "Archivo.hpp"

using namespace std;

Archivo::Archivo(string nombre){
    this->nombre=nombre;
    cout << nombre << endl;
}

