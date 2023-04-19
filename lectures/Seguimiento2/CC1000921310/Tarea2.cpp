/*
Tarea2 (Jueves 13 de Abril)
ESCRIBIR EN UN ARCHIVO DE TEXTO DOS LINEAS.
Escribir una funcion, "RecibirCadenas",  que recibe como parametros dos cadenas que puede contener espacios y signos de puntuacion.
la funcion deberá:

    Decir qué cadena es mayor y cuál es menor alfabéticamente
    Contar el número total de vocales en la cadena 1. Imprimir la frecuencia de cada vocal.
    Generar una nueva cadena que será la primera cadena leída, con las vocales convertidas a MAYÚSCULAS
    Generar una nueva cadena que será la segunda cadena leída, con las consonantes convertidas a MAYÚSCULAS
    Generar una nueva cadena concatenando las dos que ya fueron convertidas
    Generar una nueva cadena que contenga la cadena concatenada invertida
    Por ultimo. En la cadena2 reemplace todos los signos de puntuación con espacios.

Incluya la función "RecibirCadenas"  en un programa ejecutable en C++, y use el programa para leer el archivo de texto creado,
y asi introduzca las dos cadena con las que probara su función.

Al finalizar el programa, este deberá:
    Imprimir las dos cadenas originales
    Imprimir la frecuencia de cada vocal en la cadena 1
    Imprimir las dos cadenas con las conversiones
    Imprimir la cadena concatenada
    Imprimir la cadena concatenada invertida
    Imprimir la cadena 2 cuando los signos de puntuación se reemplace con espacios*/

#include <iostream>
#include <fstream>
#include <cstdlib> //isUpper
#include <string>
#include <algorithm>    // std::reverse
#include <ctype.h> // ispunct

void RecibirCadenas(const std :: string, const std :: string);
void Comparar_Alfabeticamente(const std :: string, const std :: string);
void ContarVocales(const std :: string);
void toUpper_Seleccion(std :: string &, const std :: string);
void CambiarPuntuacion(std :: string &, const std :: string);

int main(){

    std :: string cadena1;  std :: string cadena2;

    std :: ifstream TextoLineas( "./lineas_Tarea2.txt");
    
    if( TextoLineas.fail() ){
        std :: cout << "No se pudo abrir el archivo \n";
        exit( 1 );
    }

    std :: getline(TextoLineas, cadena1);
    std :: getline(TextoLineas, cadena2);

    RecibirCadenas(cadena1, cadena2);

    std :: cout << cadena1 << "\n";
    std :: cout << cadena2 << "\n";                 //Imprimir las dos cadenas originales.
}

void RecibirCadenas(const std :: string cadena1, const std :: string cadena2){

    Comparar_Alfabeticamente(cadena1, cadena2);     //Decir qué cadena es mayor y cuál es menor alfabéticamente.
    ContarVocales(cadena1);                         //Contar el número total de vocales en la cadena 1. Imprimir la frecuencia de cada vocal en la cadena 1.

    std :: string cadena3 = cadena1;
    toUpper_Seleccion(cadena3, "aeiou");
    std :: cout << cadena3 << "\n";                 //La primera cadena leída, con las vocales convertidas a MAYÚSCULAS

    std :: string cadena4 = cadena2;
    toUpper_Seleccion(cadena4, "bcdfghjklmnpqrstvxyz");
    std :: cout << cadena4 << "\n";                 //La segunda cadena leída, con las consonantes convertidas a MAYÚSCULAS

    std :: string cadena5 = cadena3 + cadena4;
    std :: cout << cadena5 << "\n";                 //Imprimir la cadena concatenada

    std :: string cadena6 = cadena5;
    std :: reverse(cadena6.begin(), cadena6.end());
    std :: cout << cadena6 << "\n";                 //Imprimir la cadena concatenada invertida

    std :: string cadena7 = cadena2;
    CambiarPuntuacion(cadena7, " ");
    std :: cout << cadena7 << "\n";                 //Imprimir la cadena 2 cuando los signos de puntuación se reemplace con espacios
}
    
void Comparar_Alfabeticamente(const std :: string cadena1, const std :: string cadena2){
    int Comparacion{ cadena1.compare(cadena2) };
    if (Comparacion == 0){
    	std :: cout << "Las dos lineas son iguales. \n"; 
    }
    else{
    	std :: cout << "Alfabeticamente, la cadena "<< (Comparacion > 0 ? "1" : "2") << " es mayor y la " << (!(Comparacion > 0) ? "1" : "2") <<" es menor. \n";
     }   
}

void ContarVocales(const std :: string cadena){
    char vocales[5] = {'a', 'e', 'i', 'o', 'u'};
    int vocal_count[5] = {0, 0, 0, 0, 0};
    for (char letra: cadena){
        switch(toupper(letra)){ 
            case 'A': vocal_count[0]++; break;
            case 'E': vocal_count[1]++; break;
            case 'I': vocal_count[2]++; break;
            case 'O': vocal_count[3]++; break;
            case 'U': vocal_count[4]++; break;
            default: break;//No hace nada;
        }
    }
    std :: cout << "El numero total de vocales de la cadena 1 es: " << vocal_count[0] + vocal_count[1] + vocal_count[2] + vocal_count[3] + vocal_count[4] << ". \n";
    for (size_t i = 0; i < 5; i++){
        std :: cout << "La vocal '" << vocales[i] << "' se repite " << vocal_count[i] << (vocal_count[i] == 1? " vez" : " veces") << ".\n";
    }
}

void toUpper_Seleccion(std :: string &cadena, const std :: string letras){
    std :: size_t posicion = cadena.find_first_of(letras);
    while ( posicion != std :: string :: npos ){
      cadena[posicion] = toupper(cadena[posicion]);
      posicion = cadena.find_first_of(letras, posicion + 1);
    }
}

void CambiarPuntuacion(std :: string &cadena, const std :: string QuePoner){
    for(size_t i = 0; cadena[i] != '\0'; i++){
        if(std :: ispunct(cadena[i])){
            cadena.replace(i, 1, QuePoner);
        }
    }
}