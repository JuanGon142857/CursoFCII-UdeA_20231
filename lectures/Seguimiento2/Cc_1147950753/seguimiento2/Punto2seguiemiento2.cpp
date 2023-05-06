#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

void RecibirCadenas(string cadena1, string cadena2);

int main(){
    string linea1 = "Profe. subile al primer examen, no sea malito siiiiiii,Dios lo vé todo :)";
    string linea2 = "Profe.Lo anterior era un broma-ensayo, pero si quiere no es una broma-ensayo.!!!";
    //creo el archivo
    ofstream archivo("archivo.txt");
    archivo << linea1 << endl; // Escribo la linea 1
    archivo << linea2<< endl; // Escribo la linea 2
    archivo.close();

    //string linea1;//cad1="Hola";
    //string linea2;//cad2="sombra, mi nombre es. zapata";

    RecibirCadenas(linea1, linea2);



    return 0;
}


    
void RecibirCadenas(string cadena1, string cadena2) {
    string concatenacion1;
    //string cadenaInvertida = " ";


    //int longitud = concatenacion1.length();
    
    // mprimir las dos cadenas originales

     cout<<"Cadena1 : "<<cadena1<<endl;
     cout<<"Cadena2 : "<<cadena2<<endl;


    // Compara las cadenas 
    if (cadena1 < cadena2) {
        cout << "La cadena 1 es menor alfabéticamente que la cadena 2." << endl;
    } else if (cadena1 > cadena2) {
        cout << "La cadena 2 es menor alfabéticamente que la cadena 1." << endl;
    } else {
        cout << "Las cadenas son iguales alfabéticamente." << endl;
    }

    // Contar las vocales y la frecuencia de cada una en la cadena 1
    int vocales[5] = {0, 0, 0, 0, 0}; 
    for (char c : cadena1) {
        if (c == 'a' || c == 'A') {
            vocales[0]++;
        } else if (c == 'e' || c == 'E') {
            vocales[1]++;
        } else if (c == 'i' || c == 'I') {
            vocales[2]++;
        } else if (c == 'o' || c == 'O') {
            vocales[3]++;
        } else if (c == 'u' || c == 'U') {
            vocales[4]++;
        }
    }

    cout << "La cadena 1 contiene " << (vocales[0] + vocales[1] + vocales[2] + vocales[3] + vocales[4]) << " vocales." << endl;
    cout << "Frecuencia de vocales en la cadena 1:" << endl;
    cout << "a: " << vocales[0] << endl;
    cout << "e: " << vocales[1] << endl;
    cout << "i: " << vocales[2] << endl;
    cout << "o: " << vocales[3] << endl;
    cout << "u: " << vocales[4] << endl;


    // Convertir las vocales de la cadena 1 a mayúsculas
    //string cadena1 = "SapoPerro";
    //string cadena1;
    string cadena1_vocales_mayus = cadena1;

    for (char& c : cadena1_vocales_mayus) {
        if (c == 'a'  || c == 'e'  || c == 'i'  || c == 'o'  || c == 'u' ) {
            c = toupper(c);
        }

     }
    cout << "Cadena 1 con vocales en mayúsculas: " << cadena1_vocales_mayus << endl;

    // Convertir las vocales de la cadena 2 a mayúculas
    string cadena2_vocales_mayus = cadena2;
    for (char& c : cadena2_vocales_mayus) {
        if (c == 'a'  || c == 'e'  || c == 'i'  || c == 'o'  || c == 'u' ) {
            c = toupper(c);
        }

     }
    cout << "Cadena 2 con vocales en mayúsculas: " << cadena2_vocales_mayus << endl;


    //Generar una nueva cadena concatenando las dos que ya fueron convertidas
    concatenacion1 = cadena1_vocales_mayus + cadena2_vocales_mayus;
    cout<<"cadena concatenando las dos que ya fueron convertidas : "<<concatenacion1<<endl;

    //Generar una nueva cadena que contenga la cadena concatenada invertida

    string cadena = concatenacion1;
    int longitud = cadena.length();


    string cadenaInvertida = "";


    for (int i = longitud - 1; i >= 0; i--) {
        cadenaInvertida += cadena[i];
    }


    cout << "La cadena invertida : " << cadenaInvertida << endl;

    //Imprimir la cadena 2 cuando los signos de puntuación se reemplace con espacios

    //string kadena = cadena2;


    string resultado = cadena2;
    replace_if(resultado.begin(), resultado.end(), [](char c) {
        return ispunct(c);
    }, ' ');

      
    cout << "Cadena original: " << resultado<< endl;


}
