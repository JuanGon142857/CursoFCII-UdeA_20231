#include <iostream>
#include <time.h>
#include <stdlib.h>

#include "bubblesort.h"


using namespace std;

int main(){
	srand(time(NULL));

	int tamaño_array = 10;
	int random_array[tamaño_array];
	int random_array2[tamaño_array];

	for(int i=0; i<tamaño_array; i++){
		int random_number = rand() % 100 + 1;
		random_array[i] = random_number;
		random_array2[i] = random_number;
	}


	cout << "El arreglo generado es:\n";
	imprimirArreglo(random_array, tamaño_array);

	cout << "El arreglo ordenado por método simple es:\n";
  simpSort(random_array, tamaño_array);
	imprimirArreglo(random_array, tamaño_array);
//  imprimirArreglo(random_array2, tamaño_array);

	cout << "El arreglo ordenado por método optimizado es:\n";
	refinedSort(random_array2, tamaño_array);
	imprimirArreglo(random_array2, tamaño_array);

	return 0;
}
