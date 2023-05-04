#include <iostream>
#include <fstream>
#include <string>
#include "procesarTexto.h"

using namespace std;

int main(){

	ifstream ArchivoImportante("InformaciónImportante.txt");

	string linea1;
	string linea2;

	getline(ArchivoImportante, linea1);
	getline(ArchivoImportante, linea2);

	RecibirCadenas(linea1, linea2);

	return 0;
}
