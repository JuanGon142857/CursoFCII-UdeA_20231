#include <iostream>
#include <vector>
#include <string>

#ifndef AHORCADO_H
#define AHORCADO_H

class Ahorcado{
    public:
        Ahorcado( const char* = "palabras.txt");

    private:
        void Cargar_Archivo( const char* );
        void Set_Palabra();
        void Empezar_Juego();
        void Nuevo_Intento();
        void Adivinar();
        void Comprobar_Letra();
        void Comprobar_Palabra();
        void Mostrar_Palabra();
        void Reintentar();
        void Dibujar();
        void Comprobar_Game_Over();
        void Game_Over_Bueno();
        void Game_Over_Malo();
        void Limpiar_Pantalla();
        void Adivinar_Palabra();

        std :: vector<std :: string> Lista;
        std :: string palabra;  //La palabra que se debe adivinar
        std :: string palabra_adivinada;  //Aqui se guardan las letras que el usuario haya adivinado
        char letra;
        int Intentos;

};


#endif
