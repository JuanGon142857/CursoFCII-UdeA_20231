// punto 1 de la tarea 1 del seguimiento 1
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void ordenamientoBurbuja(int arr[], int tam);

int main(){
    const int tam = 10;
    int arr[tam];
    
    srand(time(NULL));
    
    // nmeros aleatorios del 1 al 100
    for(int i = 0; i < tam; i++){
        arr[i] = rand() % 100 + 1;
    }
    
    // Aqui imprimo el arreglo inicla  desordenado
    cout << "Arreglo desordenado: ";
    for(int i = 0; i < tam; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // ordeno usando el metodo de  la burbuja
    ordenamientoBurbuja(arr, tam);
    
    // Imprimo arreglo ordenado
    cout << "Arreglo ordenado: ";
    for(int i = 0; i < tam; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}


void ordenamientoBurbuja(int arr[], int tam){
    for(int i = 0; i < tam-1; i++){
        for(int j = 0; j < tam-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}