#include<iostream>
#include<cmath>

using namespace std;

int main() {
    int n = 4; // Número de ecuaciones
    int iteraciones = 100; // Número de iteraciones
    double tol = 0.0001;
    double A[n][n] = {{10, -1, 2, 0}, {-1, 11, -1, 3}, {2, -1, 10, -1}, {3, -1, 8, 15}}; // Matriz de 4x4 que representa A
    double b[n] = {6, 25, -11, 15}; // Vector b que contiene los valores del igual.
    double x0[n] = {0}; // Vector de aproximación inicial.
    double x[n]; // Vector de soluciones para x1, x2, x3, x4

    int k = 1;

    while (k <= iteraciones) {
        for (int i = 0; i < n; i++) {
            double sumatoria1 = 0;
            double sumatoria2 = 0;
            for(int j=1;j<i-1;j++){
                sumatoria2 += A[i][j]*x[j];
            }
            for (int j = i+1; j < n; j++) {
                if (j != i) {
                    sumatoria1 += A[i][j] * x0[j];
                }
            
            }
            x[i] = (b[i] - sumatoria1- sumatoria2) / A[i][i];
        }
        
    bool convergencia = true;
    for (int i = 0; i < n; i++) {
        if (abs(x[i] - x0[i]) >= tol) {
            convergencia = false;
            break;
        }
    }

    if (convergencia) {
        cout << "Se alcanzo la convergencia en la iteracion " << k << endl;
        break;
    }

    for (int i = 0; i < n; i++) {
        x0[i] = x[i];
    }

    k++;
    }

    if (k > iteraciones) {
        cout << "No se alcanzo la convergencia en " << iteraciones << " iteraciones." << endl;
    }

    for (int i = 0; i < n; i++) {
        cout << "El valor de x[" << i + 1 << "] es: " << x[i] << endl;
    }

    return 0;
}