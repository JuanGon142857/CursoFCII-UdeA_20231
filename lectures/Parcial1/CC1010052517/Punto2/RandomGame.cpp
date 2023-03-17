#include <iostream>

#include "RandomGame.h"

using namespace std;

RandomGame::RandomGame(){
    cout << "Bienvenido al juego \"Adivina el numero\"\n";
    cout << "El objetivo de este juego es adivinar un numero entre 1 y 1000\n";
    cout << "Cada vez que ingreses un número te diremos si el número es mayor o menor al ingresado :D\n";
    cout << "¡Buena suerte!\n";

    srand(time(NULL));
    numberGenerator();
    start();
}

void RandomGame::numberGenerator(){
    number = rand() % 1000 + 1;
}

short int RandomGame::compareNumber(){
    cout << "Ingresa un numero: ";
    cin >> guess;

    if(guess > number){
        cout << "¡El número ingresado es mayor!\n";
        return 1;
    }else if(guess < number){
        cout << "¡El número ingresado es menor!\n";
        return -1;
    }else{
        cout << "¡Felicidades! ¡Adivinaste el numero!\n";
        return 0;
    }
}

void RandomGame::start(){
    short int estado = compareNumber();

    while(estado != 0){
        estado = compareNumber();
    }

    char replay = 'n';

    cout << "¿Deseas jugar de nuevo? (s/n): ";
    cin >> replay;

    if(replay == 's'){
        numberGenerator();
        start();
        }
    else cout << "¡Gracias por jugar!\n";
}