#include "HangedGame.h"
#include "hangdraw.h"
#include <iostream>
#include <fstream>

using namespace std;

Hang::Hang(){
    cout << "Bienvenido al juego \"Ahorcado\"\n";
    cout << "El objetivo de este juego es adivinar una palabra\n";
    cout << "Para jugar debes ir introduciendo letras y si la letra se encuentra en la palabra te mostraremos sus posiciones\n";
    cout << "Además, si aciertas podrás intentar ingresar toda la palabra\n";
    cout << "Puedes equivocarte hasta 7 veces\n";
    cout << "Si no lo logras, te colgamos :D\n";
    cout << "¡Buena suerte!\n";

    srand(time(NULL));
    
    if (checkFile()){
        start();}
    else cout << "Error fatal: No se encontró el archivo wordList.txt\n";
}

bool Hang::checkFile(){
    ifstream wordList("wordList.txt");
    return wordList.good();
}

// Escoge una palabra aleatoria del archivo wordList.txt
string Hang::randomWord(){
    // Número de palabras = 959
    short int random_line = rand() % 959 + 1;
    ifstream wordList("wordList.txt");
    
    for(int i=0; i<random_line; i++){
        getline(wordList, word);
    }

    return word;
}

void Hang::CodifiedWord(string guess){

    short int index = 0;
    bool correct = false;

    // Reemplaza las X por la letra adivinada. 

    // Halla la posición de la letra en la palabra.
    index = word.find_first_of(guess);


    while(index != string::npos){
        codifiedWord.replace(index, 1, guess);
        correct = true;
        
        index = word.find_first_of(guess, index + 1);
    }

    // Si la letra no se encuentra en la palabra, pierdes un intento.
    if(correct == false){
        lives--;
        cout << "¡Oh no! La letra no aparece en la palabra. Intenta otra vez.\n";
        cout << "\033[1;36m" <<"\nAdivina la palabra: " << codifiedWord << "\033[0m" << endl;
    }
    // Si la letra se encuentra da la opción de ingresar la palabra completa.
    else if(word!=codifiedWord){
        cout << "\033[1;36m" << "\nAdivina la palabra: " << codifiedWord << "\033[0m" << endl << endl;
        FullGuess();
    }
}

// Pide al usuario que ingrese una letra, valida que sí sea una letra (excluye letras con tilde y ñ), que no se haya ingresado previamente y la convierte a minúscula.
void Hang::inputGuess(){
    cout << "\033[1;36m" <<"\nAdivina la palabra: " << codifiedWord << "\033[0m" << endl;

    cout << "Ingresa una letra: ";
    string guess = "";
    getline(cin, guess);
    
    if (isalpha(guess[0]) and guess.length() == 1){
        if(guessedLetters.find_first_of(guess) != string::npos){
            cout << "¡Ya ingresaste esa letra!\n";
            inputGuess();}
        else{
        guess = tolower(guess[0]);
        guessedLetters += guess;
        CodifiedWord(guess);
        }
    }
    else{
        cout << "¡Debes ingresar un único caŕacter válido!\n";
        inputGuess();
    }

}

void Hang::FullGuess(){
    cout << "¡Bien hecho! La letra aparece en la palabra.\n";
    cout << "Ingresa una letra o adivina si quieres: ";
    string fullGuess;
    getline(cin, fullGuess);

    // Si la palabra ingresada es más larga que 1, se asume que es un intento de adivinar la palabra completa.
    if (fullGuess.length() > 1){
        if(fullGuess != word){
            cout << "¡Oh no! La palabra no es correcta. Pierdes un intento.\n";
            lives--;
        }
        else{
            codifiedWord = word;
        }
    }
    else{
        if (isalpha(fullGuess[0])){
            if(guessedLetters.find_first_of(fullGuess) != string::npos){
            cout << "¡Ya ingresaste esa letra!\n";
            inputGuess();}
            else{
                fullGuess = tolower(fullGuess[0]);
                CodifiedWord(fullGuess);
                guessedLetters += fullGuess;
            }
        }
        else{
            cout << "¡Debes ingresar un caŕacter válido!\n";
            FullGuess();
        }
    }
}

void Hang::chooseHanged(){
    switch(lives){
        case 7:
            cout << hang0 << endl;
            break;
        case 6:
            cout << hang1 << endl;
            break;
        case 5:
            cout << hang2 << endl;
            break;
        case 4:
            cout << hang3 << endl;
            break;
        case 3:
            cout << hang4 << endl;
            break;
        case 2:
            cout << hang5 << endl;
            break;
        case 1:
            cout << hang6 << endl;
            break;
        case 0:
            cout << hang7 << endl;
            break;
    }
}

void Hang::start(){
    word = randomWord();
    codifiedWord = word;
    guessedLetters = "";

    for(int i = 0; i < codifiedWord.length(); i++){
        codifiedWord.replace(i, 1, "X");
    }

    lives = 7;
    status = false;
    replay = false;

    //cout << word;
    //cout << "\033[1;36m" <<"\nAdivina la palabra: " << codifiedWord << "\033[0m" << endl;

    while (lives > 0 and status==false){
        chooseHanged();

        cout << "\nLetras usadas: " << guessedLetters << endl;
        cout << "Vidas restantes: " << lives << endl ;

        inputGuess();     
        
        if(word==codifiedWord){
            cout << "\033[38;5;48m" << codifiedWord << "\n¡Felicidades! ¡Adivinaste la palabra!\n";
            status = true;
        }
        else if(lives == 0){
            chooseHanged();
            cout << "\033[0;31m" <<"Llegó la hora de colgarte\n";
            cout << "\033[0m" << "La palabra era: " << "\033[1;34m" << word << "\033[0m" << endl;
        }
        
    }

    cout << "¿Deseas jugar de nuevo? (s/N): " << "\033[0m";
    getline(cin, replay);


    if(replay == "s" or replay == "S"){
        start();
    }
    else cout << "¡Gracias por jugar!\n";

}