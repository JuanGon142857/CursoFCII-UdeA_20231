/*
 El método de Euler mejorado consiste en tomar las fórmulas del método de Euler para calcular la
  pendiente en un punto inicial y en un punto final y luego promediarlas. De esta manera el resultado 
  será mucho más acertado a lo largo de todo el intervalo
*/
#include <iostream>
#include <cmath>

using namespace std;

double f(double x, double y){
    return y - pow(x, 2) + 1; // Función f(x,y)
}

int main(){
    double h = 0.1; // tamaño del paso
    double x0 = 0, y0 = 0.5; // defino condiciones iniciales
    double xn = 2; // valor final de x
    double y, k1, k2, k3, k4;

    for(double x = x0; x <= xn; x += h){
        k1 = f(x, y0);
        k2 = f(x + h/2, y0 + (h/2)*k1);
        k3 = f(x + h/2, y0 + (h/2)*k2);
        k4 = f(x + h, y0 + h*k3);
        y = y0 + (h/6) * (k1 + 2*k2 + 2*k3 + k4);
        y0 = y;
        cout << "x = " << x << ", y = " << y << endl; // Se imprime la solución
    }

    return 0;
}
