#include <iostream>
#include <string>
#include <vector>
#include <numeric>

#include "procesarTexto.h"

using namespace std;

enum LetraMayus{VOCALES, CONSON};

void compararCadenas(string cadena1, string cadena2){
	if (cadena1 > cadena2){
		cout << "La primera cadena es mayor alfabéticamente.\n\n"; 
	}
	else{
		if (cadena2 > cadena1){
			cout << "La segunda cadena es mayor alfabéticamente.\n\n";
		}
		else cout << "Las cadenas son iguales.\n\n";
	}
}

// ¿Cómo se manejan las tildes en esto?
void contarVocales(string cadena){
	vector <int> vocales{0, 0, 0, 0, 0};
	for (int i = 0; i<cadena.length(); i++){
		switch(tolower(cadena[i])){
      case 'a':
				vocales.at(0) += 1;
				break;
			case 'e':
				vocales.at(1) += 1;
				break;
			case 'i':
				vocales.at(2) += 1;
				break;
			case 'o':
				vocales.at(3) += 1;
				break;
			case 'u':
				vocales.at(4) += 1;
				break;
		}

	}

	int total = 0;

	cout << "La cadena tiene un total de " << accumulate(vocales.begin(), vocales.end(), total) << " vocales (excluyendo vocales con tilde).\n";

	cout << "La frecuencia para cada vocal es la siguiente:\n";
	cout << "a: " << vocales.at(0) << endl;
	cout << "e: " << vocales.at(1) << endl;
	cout << "i: " << vocales.at(2) << endl;
	cout << "o: " << vocales.at(3) << endl;
	cout << "u: " << vocales.at(4) << endl;

}

void aMayusculas(string &cadena, short int tipo){
	switch(tipo){
		// Caso de las vocales
		case 0:
			for (int i = 0; i<cadena.length(); i++){
				if (cadena[i] == 'a' or cadena[i] == 'e' or cadena[i] == 'i' or cadena[i] == 'o' or cadena[i] == 'u'){
					cadena[i] = toupper(cadena[i]);
				}
			}
			break;
		// Caso de las consonantes
		case 1:
			for (int i = 0; i<cadena.length(); i++){
				if (cadena[i] != 'a' and cadena[i] != 'e' and cadena[i] != 'i' and cadena[i] != 'o' and cadena[i] != 'u'){
					cadena[i] = toupper(cadena[i]);
				}
			}
			break;
	}
}

void invertirCadena(string &cadena){
    int n = cadena.length();
 
    for (int i = 0; i < n / 2; i++)
        swap(cadena[i], cadena[n - i - 1]);
}


void noPuntuacion(string cadena){
	short int index = 0;
	while(index != -1){
		index = cadena.find_first_of(".,;:¿?!¡()[]{}-—");
		if (index != -1) cadena.replace(index, 1, " ");
	}
	// Falla con ¿ y ¡
	/*for (int i = 0; i<cadena.length(); i++){
		if (ispunct(cadena[i])){
			cadena.replace(i, 1, " ");
		}
	}*/
	cout << cadena << endl;
}

void RecibirCadenas(string cadena1, string cadena2){

	cout << "Las cadenas originales son:\n";
	cout << cadena1 << endl;
	cout << cadena2 << endl;

	string cadbuff = cadena2;

	compararCadenas(cadena1, cadena2);

	cout << "Para la cadena 1:\n";
	contarVocales(cadena1);

	aMayusculas(cadena1, VOCALES);
	aMayusculas(cadena2, CONSON);

	cout << "\nCadenas con conversiones de mayúsculas:\n";
	cout << cadena1 << endl;
	cout << cadena2 << endl;


	string concatcad = cadena1 + cadena2;
	cout << "\nLas cadenas concatenadas son:\n";
	cout << concatcad << endl << endl;

	invertirCadena(concatcad);
	cout << "La invertida queda así:\n";
	cout << concatcad << endl;

	cout << "\nLa segunda cadena original sin signos de puntuación es:\n";
	noPuntuacion(cadbuff);
}
