#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Archivo.hpp"
using namespace std;


vector<int> Archivo::archivoEntrada(string nombre){
    string linea;
    int aux = 0;
    string::iterator it;
    vector<int> lineaControl;
    ifstream myfile (nombre);
    if (myfile.is_open())
    {
        while ( getline (myfile,linea) )
        {
            if(aux>0){
                for ( it = linea.begin() ; it < linea.end(); it++)
                {
                    if(*it != 32){
                        lineaControl.push_back(*it-48);
                    }
                }
            }
            aux++;
        }
        myfile.close();
    }

    else cout << "Unable to open file";
    return lineaControl;
}
