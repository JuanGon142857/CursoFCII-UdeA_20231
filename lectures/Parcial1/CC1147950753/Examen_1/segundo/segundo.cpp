#include <iostream> 
#include <cstdlib> 

using namespace std;

int main() {
    int numero_correcto, eleccion, intentos = 0; // Declaro las variables 
    char jugar_de_nuevo = 's'; // inicioaliso la variable
    
    while (jugar_de_nuevo == 's' || jugar_de_nuevo == 'S') { // Mientras el jugador quiera jugar de nuevo
        // Reinicio el contador de intentos
        intentos = 0; 
        srand(time(NULL)); // Inicializo la semilla 
        numero_correcto = rand() % 1000 + 1; // Genero un número aleatorio entre 1-1000
        
        cout << "Adivina un número entre 1 y 1000" << endl;
        
        // Repito hasta que haya coincidencia 
        do { 
            cout << "Introduce el número: ";
            cin >> eleccion;
            intentos++; 
            
            // Si el jugador adivina
            if (eleccion == numero_correcto) { 
                cout << "Has adivinado el número en " << intentos << " intentos." << endl;
            } else if (eleccion < numero_correcto) { // Si la elección es menor que el número correcto
                cout << "La elección es menor que el número correcto. Sigue intentándolo." << endl;
            // Si la elección es mayor que el número correcto
            } else { 
                cout << "La elección es mayor que el número correcto. Sigue intentando." << endl;
            }
        } while (eleccion != numero_correcto); // se  repite hasta que haya coincidencia
        
        cout << "¿Quieres jugar de nuevo? (s/n): ";
        cin >> jugar_de_nuevo; // pregunto se el jugador quiere jugar de otra vez
    }
    
    cout << "¡Gracias por jugar¡" << endl;
    
    return 0;
}
