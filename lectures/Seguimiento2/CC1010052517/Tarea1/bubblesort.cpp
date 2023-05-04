#include <iostream>
#include <iomanip>
#include "bubblesort.h"

using namespace std;

void intercambiar(int * const item1Ptr, int * const item2Ptr){
	int buffer = *item1Ptr;
	*item1Ptr = *item2Ptr;
	*item2Ptr = buffer;
}

void bubbleSweep(int * const arreglo, int tamaño){
	for (int i=0; i < tamaño - 1; i++){
		if (arreglo[i] > arreglo[i+1]){
			intercambiar(&arreglo[i], &arreglo[i+1]);
		}
	}
}

void simpSort(int * const arreglo, int tamaño){
	for (int i=0; i < tamaño; i++){
		bubbleSweep(arreglo, tamaño - i);
	}
}

void refinedSort(int * const arreglo, int tamaño){
	int swaps = 1;
	int cut = tamaño - 1;

	while (swaps!=0){
		swaps = 0;
		for(int i=0; i < cut; i++){
			if (arreglo[i] > arreglo[i+1]){
				intercambiar(&arreglo[i], &arreglo[i+1]);
				swaps++;
			}
		}
		cut--;
	}

}

void imprimirArreglo(int * const arreglo, int tamaño){
	for (int i=0; i < tamaño; i++){
		cout << setw(4) << arreglo[i];
	}
	cout << endl;
}
