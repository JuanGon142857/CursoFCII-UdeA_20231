#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

vector<string> obtenerPalabrasDesdeArchivo(const string& nombreArchivo) {
    vector<string> palabras;
    ifstream archivo(nombreArchivo);

    if (!archivo) {
        cerr << "Error al abrir el archivo." << endl;
        return palabras;
    }

    string palabra;
    while (archivo >> palabra) {
        palabras.push_back(palabra);
    }

    archivo.close();
    return palabras;
}

string seleccionarPalabra(const vector<string>& palabras) {
    srand(time(0));
    int indice = rand() % palabras.size();
    return palabras[indice];
}

int main() {
    const int MAX_INTENTOS = 6;
    const string nombreArchivo = "palabras.txt";

    vector<string> palabras = obtenerPalabrasDesdeArchivo(nombreArchivo);
    if (palabras.empty()) {
        return 1;
    }

    string palabraSeleccionada = seleccionarPalabra(palabras);
    int intentos = 0;
    string letrasCorrectas = "";
    string letrasIncorrectas = "";

    bool adivinado = false;

    while (intentos < MAX_INTENTOS && !adivinado) {
        cout << "Adivina la palabra: ";

        for (char letra : palabraSeleccionada) {
            if (letrasCorrectas.find(letra) != string::npos) {
                cout << letra << " ";
            } else {
                cout << "_ ";
            }
        }

        cout << endl;
        cout << "Letras incorrectas: " << letrasIncorrectas << endl;

        char letraIntento;
        cout << "Introduce una letra: ";
        cin >> letraIntento;

        if (letrasCorrectas.find(letraIntento) != string::npos || letrasIncorrectas.find(letraIntento) != string::npos) {
            cout << "¡Intenta con otra!" << endl;
            continue;
        }

        if (palabraSeleccionada.find(letraIntento) != string::npos) {
            letrasCorrectas += letraIntento;

            if (letrasCorrectas.length() == palabraSeleccionada.length()) {
                adivinado = true;
            }
        } else {
            letrasIncorrectas += letraIntento;
            intentos++;
            cout << "Letra incorrecta. Te quedan " << MAX_INTENTOS - intentos << " intentos." << endl;
        }
    }

    if (adivinado) {
        cout << "¡Has adivinado la palabra!" << endl;
    } else {
        cout << "¡Has perdido! La palabra era: " << palabraSeleccionada << endl;
    }

    return 0;
}
