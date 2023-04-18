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
    Por ultimo. En la cadena2 reemplace todos los signos de puntuación ++ terciarycon espacios.

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
#include <iomanip>
#include <cstdlib>
#include <cstring>

void RecibirCadenas(string cadena1, string cadena2){
    int Comparacion{ cadena1.compare(cadena 2) };
    if (Comparacion == 0){
    	std :: cout << "Las dos lineas son iguales. \n"; 
    }
    else{
    	cout << (Comparacion > 0 ? "La cadena 1 es mayor y la cadena 2 es menor" : "La cadena 2 es mayor y la cadena 1 es menor")
    }
    
    
    
    
    


}
