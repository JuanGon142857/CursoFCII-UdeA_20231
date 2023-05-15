#include <iostream>
#include <fstream> // flujo de archivo
#include <string>
#include <iomanip>
#include <stdlib.h> //random
#include <vector>
#include <ctime>

#include "Ahorcado.h"

using namespace std;

Ahorcado :: Ahorcado( const char* filename){
    
    Cargar_Archivo( filename );
    Empezar_Juego();
}

void Ahorcado :: Cargar_Archivo( const char* filename ){
    ifstream Palabras_archivo( filename );
    if (!Palabras_archivo){
        cerr << "No se pudo abrir el archivo \n";
        exit( 1 );
    }
    int j = 0;
    string word;
    while( getline(Palabras_archivo, word) ){
        Lista.push_back(word);
    }
    Palabras_archivo.close();
}

void Ahorcado :: Set_Palabra(){
    int i = rand() % Lista.size();
    palabra = Lista[i];
    palabra_adivinada = palabra;
    for( int i = 0; i < palabra_adivinada.length(); i++){
        palabra_adivinada[i] = 'x';
    }
    //cout << palabra;
}

void Ahorcado :: Empezar_Juego(){
    Set_Palabra();
    cout << "Se ha escogido una palabra aleatoria \n";
    Intentos = 7;
    Nuevo_Intento();
}

void Ahorcado :: Nuevo_Intento(){
    Comprobar_Game_Over();
    Dibujar();
    Mostrar_Palabra();
    Adivinar();
}

void Ahorcado :: Adivinar(){
    cin >> letra;
    Comprobar_Letra();
}

void Ahorcado :: Comprobar_Letra(){
    size_t found = palabra.find(letra);

    if( found != string::npos ){
        while( found != string::npos ){
            palabra_adivinada.replace(found, 1, letra);
            found = palabra.find(letra, found + 1);
        }
        Adivinar_Palabra();
    }
    else{
        Intentos = Intentos - 1;
    }
    Nuevo_Intento();
}

void Ahorcado :: Adivinar_Palabra(){
    Dibujar();
    Mostrar_Palabra();
    char userInput;
    cout << "Digite 1 si desea adivinar la palabra completa (esto contara como un intento) \n";
    cin >> userInput;

    if (userInput == '1'){
        
        cout << "Adivine la palabra completa: ";
        string intento_adivinar_palabra; // Aqui se guarda la entrada del usuario cuando trate de adivinar la palabra completa
        cin >> intento_adivinar_palabra;
        if (intento_adivinar_palabra == palabra){
            palabra_adivinada = palabra;
        }
        else{
            Intentos = Intentos - 1;   
        }
    }          
}

void Ahorcado :: Comprobar_Game_Over(){
    if (palabra_adivinada == palabra){
        Game_Over_Bueno();
    }
    if (Intentos == 0){
        Game_Over_Malo();
    }   
}

void Ahorcado :: Dibujar(){
    Limpiar_Pantalla();
    switch(Intentos){
        case 7:
        cout << " _________   \n" <<
                " |       |   \n" <<
                " |           \n" <<
                " |           \n" <<
                " |           \n" <<
                " |           \n" <<
                " |           \n" <<
                "_|_          \n"; break;

        case 6:
        cout << " _________   \n" <<
                " |       |   \n" <<
                " |       O   \n" <<
                " |           \n" <<
                " |           \n" <<
                " |           \n" <<
                " |           \n" <<
                "_|_          \n"; break;

        case 5:
        cout << " _________   \n" <<
                " |       |   \n" <<
                " |       O   \n" <<
                " |       |   \n" <<
                " |           \n" <<
                " |           \n" <<
                " |           \n" <<
                "_|_          \n"; break; 

        case 4:
        cout << " _________   \n" <<
                " |       |   \n" <<
                " |       O   \n" <<
                " |       |   \n" <<
                " |       |   \n" <<
                " |           \n" <<
                " |           \n" <<
                "_|_          \n"; break;  

        case 3:
        cout << " _________   \n" <<
                " |       |   \n" <<
                " |       O   \n" <<
                " |      /|   \n" <<
                " |       |   \n" <<
                " |           \n" <<
                " |           \n" <<
                "_|_          \n"; break;  

        case 2:
        cout << " _________   \n" <<
                " |       |   \n" <<
                " |       O   \n" <<
                " |      /|\\ \n" <<
                " |       |   \n" <<
                " |           \n" <<
                " |           \n" <<
                "_|_          \n"; break;     
        case 1:
        cout << " _________   \n" <<
                " |       |   \n" <<
                " |       O   \n" <<
                " |      /|\\ \n" <<
                " |       |   \n" <<
                " |      /    \n" <<
                " |           \n" <<
                "_|_          \n"; break;  
        case 0:
        cout << " _________   \n" <<
                " |       |   \n" <<
                " |       O   \n" <<
                " |      /|\\ \n" <<
                " |       |   \n" <<
                " |      / \\ \n" <<
                " |           \n" <<
                "_|_          \n"; break;                   
    }
}

void Ahorcado :: Game_Over_Bueno(){
    Mostrar_Palabra();
    cout << "Felicidades! \n";
    Reintentar();
}

void Ahorcado :: Game_Over_Malo(){
    Dibujar();
    cout << "Ha perdido. La letra era " << palabra << "\n";
    Reintentar();
}

void Ahorcado :: Mostrar_Palabra(){
    cout << "Adivine la palabra: " << palabra_adivinada << "\n";
}

void Ahorcado :: Reintentar(){
    cout << "Digite 1 para volver a jugar: ";
    int opcion;
    cin >> opcion;
    if (opcion == 1){
        Empezar_Juego();
    }
    else{
        exit(1);
    }
}

void Ahorcado :: Limpiar_Pantalla(){
    int n;
    for (n = 0; n < 10; n++)
      printf( "\n\n\n\n\n\n\n\n\n\n" );
}