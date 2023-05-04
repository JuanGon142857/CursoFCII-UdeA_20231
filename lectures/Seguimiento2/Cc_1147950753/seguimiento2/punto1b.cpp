// punto 2 de la tarea 1 del seguimiento 1
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void ordenamientoBurbujaOptimizado(int arr[], int tam){
    bool intercambio = true;
    int comparaciones = tam - 1;
    int pasadas = 0;
    while (comparaciones > 0 && intercambio) {
        intercambio = false;
        int numComparaciones = comparaciones - pasadas; // Reduce el número de comparaciones
        for (int i = 0; i < numComparaciones; i++) {
            if (arr[i] > arr[i+1]) {
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                intercambio = true;
            }
        }
        pasadas++;
    }
}

int main() {
    const int tam = 10;
    int arr[tam];
    
    srand(time(NULL));
    
    // Generar números aleatorios del 1 al 100
    for (int i = 0; i < tam; i++) {
        arr[i] = rand() % 100 + 1;
    }
    
    // Imprimir arreglo desordenado
    cout << "Arreglo desordenado: ";
    for (int i = 0; i < tam; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // Ordenar arreglo con ordenamiento de burbuja optimizado
    ordenamientoBurbujaOptimizado(arr, tam);
    
    // Imprimir arreglo ordenado
    cout << "Arreglo ordenado: ";
    for (int i = 0; i < tam; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
