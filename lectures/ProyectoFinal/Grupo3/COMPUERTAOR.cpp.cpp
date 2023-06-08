#include "neurona_multicapa.h"

using namespace std;

int main() {
    // Conjunto de entrenamiento para la compuerta OR
    const int tam_entrenamiento = 4;
    double** X = new double*[tam_entrenamiento];
    double** y = new double*[tam_entrenamiento];
    for (int i = 0; i < tam_entrenamiento; i++) {
        X[i] = new double[2];
        y[i] = new double[1];
    }
    X[0][0] = 0; X[0][1] = 0; y[0][0] = 0;
    X[1][0] = 0; X[1][1] = 1; y[1][0] = 1;
    X[2][0] = 1; X[2][1] = 0; y[2][0] = 1;
    X[3][0] = 1; X[3][1] = 1; y[3][0] = 1;

    // Crear y entrenar la red neuronal
    neurona_multicapa neurona_multicapa(2, 5, 1); 
    neurona_multicapa.entrenamiento(X, y, 0.1, 10000, tam_entrenamiento);  // Ajuste: Incrementar el número de épocas de entrenamiento

    // Predecir la salida para nuevos datos
    const int tamano_datos = 4;
    double** nuevo_x = new double*[tamano_datos];
    for (int i = 0; i < tamano_datos; i++) {
        nuevo_x[i] = new double[2];
    }
    nuevo_x[0][0] = 0; nuevo_x[0][1] = 0;
    nuevo_x[1][0] = 0; nuevo_x[1][1] = 1;
    nuevo_x[2][0] = 1; nuevo_x[2][1] = 0;
    nuevo_x[3][0] = 1; nuevo_x[3][1] = 1;

    double* prediciones = neurona_multicapa.predecir(nuevo_x, tamano_datos);

    // Imprimir las predicciones
    for (int i = 0; i < tamano_datos; i++) {
        cout << "prediccion " << i+1 << ": " << prediciones[i] << endl;
    }

    // Liberar la memoria utilizada por los arreglos
    for (int i = 0; i < tam_entrenamiento; i++) {
        delete[] X[i];
        delete[] y[i];
    }
    delete[] X;
    delete[] y;

    for (int i = 0; i < tamano_datos; i++) {
        delete[] nuevo_x[i];
    }
    delete[] nuevo_x;

    delete[] prediciones;

    return 0;
}