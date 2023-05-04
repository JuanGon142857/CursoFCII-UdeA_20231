#include "tarea_2.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){

    ifstream archivoClientesEntrada("test.dat");
    if( archivoClientesEntrada.fail() )
    {
        cerr << "Error: no se pudo abrir el archivo" << endl;
        exit(1);
    }

    string cadena1;
    string cadena2;

    getline(archivoClientesEntrada,cadena1);
    getline(archivoClientesEntrada,cadena2);


    RecibirCadenas(cadena1,cadena2);
    return 0;
    

}