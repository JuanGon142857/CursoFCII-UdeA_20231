#include <iostream>
#include "parcial1_punto2.h"

using namespace std;


int init_num(){
    int g;
    cout << "Adivina el numero del 1 al 1000: ";
    cin >> g;
    return g;
}
void is_num_correct(int guess, int numero){
    
    //cout << "El numero es: " << numero << endl; //Para verificar el numero
    if (guess==numero){
    
        cout << "¡Acertaste!"<< endl;
        cout << "¿Quieres jugar de nuevo? (s/n)" << endl;
        char respuesta;
        cin >> respuesta;
        if (respuesta=='s'){
            numero = rand() % 1000 + 1;
                int n;
                is_num_correct(init_num(),n= rand() % 1000 + 1);
            }
            else{
                cout << "Gracias por jugar" << endl;
            }
    }
    else if (guess>numero){
        cout << "El numero es menor" << endl;
        cout << "Adivina el numero: ";
        cin >> guess;
        is_num_correct(guess,numero);
    }
    else if (guess<numero){
        cout << "El numero es mayor" << endl;
        cout << "Adivina el numero: ";
        cin >> guess;
        is_num_correct(guess,numero);
    }
}
