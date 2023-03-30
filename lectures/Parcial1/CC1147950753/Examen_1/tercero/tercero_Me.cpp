/*
 El método de Euler mejorado consiste en tomar las fórmulas del método de Euler para calcular la
  pendiente en un punto inicial y en un punto final y luego promediarlas. De esta manera el resultado 
  será mucho más acertado a lo largo de todo el intervalo
*/

#include <iostream>
#include <cmath>

using namespace std;

// Definimos la función f(x,y) para el problema de valor inicial
double f(double x, double y) {
    return x + y;
}

// implemetación método de Euler modificado
double Mod_Euler(double x0, double y0, double h, int n) {
    double x = x0;
    double y = y0;
    for (int i = 0; i < n; i++) {
        // calculo la pediente en el punto (x,y)
        double k1 = f(x, y);
        // avence  h/2 con k1 para estimar el valor del punto
        double y_mid = y + (h/2)*k1;
        double x_mid = x + h/2;
        // pendiente en el punto (x+h/2, y+h/2*k1)
        double k2 = f(x_mid, y_mid);
        // paso completo de longitud h utilizando la media ponderada de k1 y k2
        y = y + h*((k1 + k2)/2);
        x = x + h;
    }
    // retorno del valor de y en el punto final
    return y;
}

int main() {
    //parámetros del problema de valor inicial
    double x0 = 0;
    double y0 = 1;
    double h = 0.1;
    int n = 10;
    // se llama al método de Euler modificado para estimar y(1)
    double y = Mod_Euler(x0, y0, h, n);
    // impresion en pantalla
    cout << "y(1) = " << y << endl;
    return 0;
}
