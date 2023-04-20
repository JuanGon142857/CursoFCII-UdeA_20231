#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <numeric>
#include <cctype>

using namespace std;

void imprimirComparacion(string cadena1, string cadena2)
{
    int resultado{cadena1.compare(cadena2)};

    if (resultado == 0)
        cout << "La cadena 1 y la cadena 2 son iguales.";
    else
    {
        if (resultado > 0)
            cout << "La cadena 1 es mayor a la cadena 2";
        else // resultado < 0
            cout << "La cadena 1 es menor a la cadena 2";
    }
}

int freqVocales(string cadena1, vector<int> array_vocales)
{
    for (int i = 0; i < cadena1.length(); i++)
    {
        char letra = cadena1.at(i);
        if ((letra == 'a') || (letra == 'A'))
        {
            array_vocales.at(0)++;
        }
        else if ((letra == 'e') || (letra == 'E'))
        {
            array_vocales.at(1)++;
        }
        else if ((letra == 'i') || (letra == 'I'))
        {
            array_vocales.at(2)++;
        }
        else if ((letra == 'o') || (letra == 'O'))
        {
            array_vocales.at(3)++;
        }
        else if ((letra == 'u') || (letra == 'U'))
        {
            array_vocales.at(4)++;
        }
    }
    cout << endl;
    cout << "Frecuencia de las vocales que hay en la cadena 1: " << endl;
    cout << setw(5) << "a" << setw(5) << setw(5) << "e" << setw(5) << setw(5) << "i" << setw(5) << setw(5) << "o" << setw(5) << setw(5) << "u" << setw(5) << endl;
    for (size_t i = 0; i < 5; i++)
    {
        cout << setw(5) << array_vocales.at(i);
    }
    cout << endl;
    cout << endl;

    return accumulate(array_vocales.begin(), array_vocales.end(), 0);
}

void toUpperVocals(string &cadena)
{
    int indice = 0;
    while (cadena.find_first_of("aeiou", indice) && (indice < cadena.length()))
    {
        indice = cadena.find_first_of("aeiou", indice);
        cadena[indice] = toupper(cadena[indice]);
    }

    cout << endl
         << "La cadena 1 con las vocales convertidas a mayúsculas es: " << cadena << endl;
}

void toUpperCons(string &cadena)
{
    int indice = 0;
    while (cadena.find_first_of("bcdfghjklmnñpqrstvwxyz", indice) && (indice < cadena.length()))
    {
        indice = cadena.find_first_of("bcdfghjklmnñpqrstvwxyz", indice);
        cadena[indice] = toupper(cadena[indice]);
    }

    cout << endl
         << "La cadena 2 con las consonantes convertidas a mayúsculas es: " << cadena << endl;
}

void invertirCadena(string &cadena, string cadena_to_convert)
{
    int i = cadena_to_convert.length() - 1, j = 0;
    while ((i = 0) && (j < cadena_to_convert.length()))
    {
        // char letra = ;
        // cadena.insert(j, letra);
        cadena.push_back(cadena_to_convert[i]);
        i--;
        j++;
    }
}

void ccambiarPuntuacion(string &cadena)
{
    int indice = 0;
    while (cadena.find_first_of(",.;_!¡¿?", indice) && (indice < cadena.length()))
    {
        indice = cadena.find_first_of(",.;_!¡¿?", indice);
        // cadena.replace(0,cadena[indice]," ");
    }

    cout << endl
         << "La cadena 2 con las consonantes convertidas a mayúsculas es: " << cadena << endl;
}

void RecibirCadenas(string cadena1, string cadena2)
{
    // enum Vocales{a=1,e,i,o,u};
    imprimirComparacion(cadena1, cadena2);
    vector<int> vocales(5, 0);
    int suma_cadena1 = freqVocales(cadena1, vocales);
    cout << "La cantidad de vocales es: " << suma_cadena1 << endl;
}

int main()
{
    string outfilename = "texto.txt";
    ifstream archivoTexto(outfilename.c_str());
    // ofstream archivoTexto(outfilename );

    if (!archivoTexto)
    {
        // cout << "No se pudo abrir el archivo" << endl;
        cerr << "No se pudo abrir el archivo" << endl;
        exit(1);
    }
    // string cadena1, cadena2;
    vector<string> cadenas;
    string linea;

    while (getline(archivoTexto, linea))
    {
        cadenas.push_back(linea);
    }
    cout << "La cadena 1 es: " << cadenas[0] << endl
         << "la cadena 2 es: " << cadenas[1] << endl
         << endl;

    RecibirCadenas(cadenas[0], cadenas[1]);

    string cadena1_copy(cadenas[0]);
    string cadena2_copy(cadenas[1]);

    toUpperVocals(cadena1_copy);
    toUpperCons(cadena2_copy);

    string cadena3_concat(cadena1_copy + " " + cadena2_copy);
    cout << endl
         << "La concatenación de las dos cadenas convertidas es:\t " << endl
         << cadena3_concat << endl;

    string cadena4_invert;
    invertirCadena(cadena4_invert, cadena3_concat);
    cout << endl
         << "La cadena invertida es: " << cadena4_invert << endl;

    return 0;
}