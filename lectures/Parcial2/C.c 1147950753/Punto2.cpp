/*
 1. El programa debe elegir una palabra.
 2. Mostrar reemplazar la palabra por XXXXXX 
 3. Relaizar bucles while
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

const int MAX_ERRORES = 7;
const vector<string> PALABRAS = {"quiero", "vacaciones","pero","hay","que","terminar","esta","carrera"};

// elijo una palabra de PALABRAS
string obtenerPalabraAleatoria(const vector<string>& listaPalabras) {
    srand(time(nullptr));
    int indiceAleatorio = rand() % listaPalabras.size();
    return listaPalabras[indiceAleatorio];
}

// Cómo está el juego
void mostrarEstadoJuego(const string& palabraAdivinar, const string& letrasAdivinadas, int numErrores) {
    cout << "\nPalabra: ";
    for (char letra : palabraAdivinar) {
        if (letrasAdivinadas.find(letra) != string::npos) {
            cout << letra << " ";
        } else {
            cout << "X ";
        }
    }
    cout << "\nLetras adivinadas: " << letrasAdivinadas;
    cout << "\nErrores: " << numErrores << "/" << MAX_ERRORES << endl;
}

int main() {
    char opcionJugarDeNuevo;
    do {
        string palabraAdivinar = obtenerPalabraAleatoria(PALABRAS);
        string letrasAdivinadas = "";
        int numErrores = 0;

        while (numErrores < MAX_ERRORES && letrasAdivinadas != palabraAdivinar) {
            mostrarEstadoJuego(palabraAdivinar, letrasAdivinadas, numErrores);

            char letraIngresada;
            cout << "\nIngrese una letra: ";
            cin >> letraIngresada;

            if (letrasAdivinadas.find(letraIngresada) != string::npos) {
                cout << "Ya ha adivinado esa letra. Intente de nuevo." << endl;
                continue;
            }

            if (palabraAdivinar.find(letraIngresada) != string::npos) {
                cout << "¡Correcto!" << endl;
                letrasAdivinadas += letraIngresada;
            } else {
                cout << "Incorrecto." << endl;
                numErrores++;
            }
        }

        if (numErrores == MAX_ERRORES) {
            cout << "\nPailas, andate de aquí que perdiste. La palabra correcta era: " << palabraAdivinar << endl;
        } else {
            cout << "\n¡Buena! adivinaste, seguro en la otro intento no podrás: " << palabraAdivinar << endl;
        }

        cout << "¿otra vés? (s/n): ";
        cin >> opcionJugarDeNuevo;
    } while (opcionJugarDeNuevo == 's');

    return 0;
}