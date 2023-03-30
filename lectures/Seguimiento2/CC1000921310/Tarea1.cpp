#include <iostream>
#include <iomanip>
#include <random>
#include <ctime>
#include <array>

using namespace std;

void Burbuja(int * const, const int);
void Burbuja_Modificado(int * const, const int);

void Intercambiar(int * const, int  * const);

int main() {
    default_random_engine engine(static_cast<unsigned int>(time(NULL)));
    uniform_int_distribution<unsigned int> randomInt(1, 10);

    const int Tamanio{10};
    int Arreglo_a_ordenar[Tamanio];
    cout << endl << endl << "Arreglo original 1:" << endl;
    for (int i{0}; i < Tamanio; i++){
        Arreglo_a_ordenar[i] = randomInt(engine);
        cout << setw(4) << Arreglo_a_ordenar[i];
    }

    Burbuja(Arreglo_a_ordenar, Tamanio);

    cout << endl << "Arreglo 1 organizado con bubblesort:" << endl;
    for (int i{0}; i < Tamanio; i++){
        cout << setw(4) << Arreglo_a_ordenar[i];
    }

    int Arreglo_a_ordenar2[Tamanio];
    cout << endl << endl << "Arreglo original 2:" << endl;
    for (int i{0}; i < Tamanio; i++){
        Arreglo_a_ordenar2[i] = randomInt(engine);
        cout << setw(4) << Arreglo_a_ordenar2[i];
    }

    Burbuja_Modificado(Arreglo_a_ordenar2, Tamanio);

    cout << endl << "Arreglo 1 organizado con modified bubblesort:" << endl;
    for (int i{0}; i < Tamanio; i++){
        cout << setw(4) << Arreglo_a_ordenar2[i];
    }
    
    return 0;
}

void Burbuja(int * const arreglo, const int tamanio){
    for (int i = 0; i < tamanio - 1; i++){ //Recorre el array las veces necesarias para asegurarse que todo queda ordenada
        for(int j = 0; j < tamanio - 1; j++){
            if(arreglo[j + 1] < arreglo[j]){
                Intercambiar( &arreglo[ j ], &arreglo[j + 1] );
            }   
        } 
    }
}

void Burbuja_Modificado(int * const arreglo, const int tamanio){
    int i{0};
    bool Listo{false};
    while (!Listo){
        Listo = true; //Al inicio del recorrido asume que todo ya esta organizado, esto se desmiente en caso de que tenga que hacer una modificacion
        for(int j{0}; j < tamanio - 1 - i; j++){ //Cambiamos hasta donde se recorre el arreglo en cada iteracion
            if(arreglo[j + 1] < arreglo[j]){
                Intercambiar( &arreglo[ j ], &arreglo[j + 1] );
                Listo = false;
            }   
        } 
    }
}

void Intercambiar(int * const a1, int * const a2){
    int temporal = *a1;
    *a1 = *a2;
    *a2 = temporal;
}
