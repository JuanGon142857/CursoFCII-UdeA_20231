#include "parcial1_punto3.h"

// Funcion que define el metodo de Euler modificado
void euler_modificado(float x0, float y0, float h, float x,int n){   
float y = y0;
cout << "Euler modificado" << endl;
cout << "xi" << "    " << "yi" << endl;
for (int i=1; i<=n; i++)
{
y = y + h * f(x0 + h/2, y + h/2 * f(x0, y));
x0 = x0 + h;
cout <<left<<setw(3)<< x0 << "   " << y << endl;
}
}

// Funcion que define el metodo de Runge-Kutta de orden 4
void runge_kutta_4(float x0, float y0, float h, float x,int n) 
{
float k1, k2, k3, k4, k5;
float y = y0;
cout << "Runge-Kutta de orden 4" << endl;
cout << "xi" << "    " << "yi" << endl;
for (int i=1; i<=n; i++)
{
k1 = h * f(x0, y);
k2 = h * f(x0 + 0.5 * h, y + 0.5 * k1);
k3 = h * f(x0 + 0.5 * h, y + 0.5 * k2);
k4 = h * f(x0 + h, y + k3);
y = y + (1.0/6.0)*(k1 + 2*k2 + 2*k3 + k4);
x0 = x0 + h;
cout <<left<<setw(3)<< x0 << "   " << y << endl;
}

}