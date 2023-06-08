#include "neurona_multicapa.h"

using namespace std;

int main() {
    // Conjunto de entrenamiento para la compuerta OR
    const int tam_entrenamiento = 16;
    double** X = new double*[tam_entrenamiento];
    double** y = new double*[tam_entrenamiento];
    for (int i = 0; i < tam_entrenamiento; i++) {
        X[i] = new double[4];
        y[i] = new double[1];
    }
    X[0][0] = 0; X[0][1] = 0; X[0][2]=0;X[0][2]=0; y[0][0] = 0;
    X[1][0] = 0; X[1][1] = 0; X[1][2]=0;X[1][3]=1; y[1][0] = 0;
    X[2][0] = 0; X[2][1] = 0; X[2][2]=1;X[2][3]=0; y[2][0] = 1; 
    X[3][0] = 0; X[3][1] = 0; X[3][2]=1;X[3][3]=1; y[3][0] = 1; 
    X[4][0] = 0; X[4][1] = 1; X[4][2]=0;X[4][3]=0; y[4][0] = 0; 
    X[5][0] = 0; X[5][1] = 1; X[5][2]=0;X[5][3]=1; y[5][0] = 1; 
    X[6][0] = 0; X[6][1] = 1; X[6][2]=1;X[6][3]=0; y[6][0] = 0; 
    X[7][0] = 0; X[7][1] = 1; X[7][2]=1;X[7][3]=1; y[7][0] = 1;
    X[8][0] = 1; X[8][1] = 0; X[8][2]=0;X[8][3]=0; y[8][0] = 0;
    X[9][0] = 1; X[9][1] = 0; X[9][2]=0;X[9][3]=1; y[9][0] = 0;
    X[10][0] = 1; X[10][1] = 0; X[10][2]=1;X[10][3]=0; y[10][0] = 0; 
    X[11][0] = 1; X[11][1] = 0; X[11][2]=1;X[11][3]=1; y[11][0] = 1; 
    X[12][0] = 1; X[12][1] = 1; X[12][2]=0;X[12][3]=0; y[12][0] = 0; 
    X[13][0] = 1; X[13][1] = 1; X[13][2]=0;X[13][3]=1; y[13][0] = 1; 
    X[14][0] = 1; X[14][1] = 1; X[14][2]=1;X[14][3]=0; y[14][0] = 0; 
    X[15][0] = 1; X[15][1] = 1; X[15][2]=1;X[15][3]=1; y[15][0] = 0;

    // Crear y entrenar la red neuronal
    neurona_multicapa neurona_multicapa(4, 7, 1); 
    neurona_multicapa.entrenamiento(X, y, 0.1, 10000, tam_entrenamiento);  // Ajuste: Incrementar el número de épocas de entrenamiento

    // Predecir la salida para nuevos datos
    const int tamano_datos = 16;
    double** nuevo_x = new double*[tamano_datos];
    for (int i = 0; i < tamano_datos; i++) {
        nuevo_x[i] = new double[4];
    }
    nuevo_x[0][0] = 0; nuevo_x[0][1] = 0; nuevo_x[0][2]=0;nuevo_x[0][2]=0;
    nuevo_x[1][0] = 0; nuevo_x[1][1] = 0; nuevo_x[1][2]=0;nuevo_x[1][3]=1; 
    nuevo_x[2][0] = 0; nuevo_x[2][1] = 0; nuevo_x[2][2]=1;nuevo_x[2][3]=0; 
    nuevo_x[3][0] = 0; nuevo_x[3][1] = 0; nuevo_x[3][2]=1;nuevo_x[3][3]=1; 
    nuevo_x[4][0] = 0; nuevo_x[4][1] = 1; nuevo_x[4][2]=0;nuevo_x[4][3]=0;
    nuevo_x[5][0] = 0; nuevo_x[5][1] = 1; nuevo_x[5][2]=0;nuevo_x[5][3]=1; 
    nuevo_x[6][0] = 0; nuevo_x[6][1] = 1; nuevo_x[6][2]=1;nuevo_x[6][3]=0;
    nuevo_x[7][0] = 0; nuevo_x[7][1] = 1; nuevo_x[7][2]=1;nuevo_x[7][3]=1; 
    nuevo_x[8][0] = 1; nuevo_x[8][1] = 0; nuevo_x[8][2]=0;nuevo_x[8][3]=0; 
    nuevo_x[9][0] = 1; nuevo_x[9][1] = 0; nuevo_x[9][2]=0;nuevo_x[9][3]=1; 
    nuevo_x[10][0] = 1; nuevo_x[10][1] = 0; nuevo_x[10][2]=1;nuevo_x[10][3]=0;
    nuevo_x[11][0] = 1; nuevo_x[11][1] = 0; nuevo_x[11][2]=1;nuevo_x[11][3]=1;
    nuevo_x[12][0] = 1; nuevo_x[12][1] = 1; nuevo_x[12][2]=0;nuevo_x[12][3]=0;
    nuevo_x[13][0] = 1; nuevo_x[13][1] = 1; nuevo_x[13][2]=0;nuevo_x[13][3]=1;
    nuevo_x[14][0] = 1; nuevo_x[14][1] = 1; nuevo_x[14][2]=1;nuevo_x[14][3]=0;
    nuevo_x[15][0] = 1; nuevo_x[15][1] = 1; nuevo_x[15][2]=1;nuevo_x[15][3]=1;

    double* prediciones = neurona_multicapa.predecir(nuevo_x, tamano_datos);

    // Imprimir las predicciones
    for (int i = 0; i < tamano_datos; i++) {
        cout << "prediccion " << i << ": " << prediciones[i] << endl;
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
