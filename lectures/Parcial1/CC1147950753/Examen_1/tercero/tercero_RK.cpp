#include <iostream>
#include <cmath>

using namespace std;

double f(double x, double y) {
    return y - x*x + 1; // defino función f(x, y)
}

int main() {
    double x0 = 0, y0 = 0.5, xn, yn, h = 0.1; // Defino condiciones iniciales y tamaño de paso
    int n = 20; // defino el número de iteraciones

    for (int i = 0; i < n; i++) {
        xn = x0 + i*h;
        double k1 = h*f(xn, y0);
        double k2 = h*f(xn + h/2, y0 + k1/2);
        double k3 = h*f(xn + h/2, y0 + k2/2);
        double k4 = h*f(xn + h, y0 + k3);
        yn = y0 + (k1 + 2*k2 + 2*k3 + k4)/6;
        cout << "y(" << xn+h << ") = " << yn << endl;
        y0 = yn;
    }

    return 0;
}

