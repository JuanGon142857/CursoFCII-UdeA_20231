#include <iostream>
#include "Tarea4.h"
#include <cmath>

using namespace std;

Quadratic::Quadratic()
{
    setA(a);
    setB(b);
    setC(c);
    setDisc();
}

void Quadratic::getCoeff()
{
    cout << "Los coeficientes son: " << endl
         << "a: " << a << endl
         << "b: " << b << endl
         << "c: " << c << endl;
}

void Quadratic::setA(float x)
{
    cout << "Ingrese el valor de a: " << endl;
    cin >> a;
}

void Quadratic::setB(float x)
{
    cout << "Ingrese el valor de b: " << endl;
    cin >> b;
}

void Quadratic::setC(float x)
{
    cout << "Ingrese el valor de c: " << endl;
    cin >> c;
}

void Quadratic::setDisc()
{
    disc = pow(b, 2) - 4 * a * c;
}

void Quadratic::typeSol()
{
    if (disc > 0)
    {
        cout << "Las raíces son reales y distintas" << endl;
    }
    else if (disc < 0)
    {
        cout << "Las raíces son complejas y conjugadas" << endl;
    }
    else
    {
        cout << "Las raíces son iguales" << endl;
    }
}

void Quadratic::solQuad()
{
    if (disc > 0)
    {
        float x1, x2;
        x1 = (-b / 2) + (pow(disc, 0.5) / 2);
        x2 = (-b / 2) - (pow(disc, 0.5) / 2);
        cout << "Las raíces reales son: " << endl
             << "x1: " << x1 << endl
             << "x2: " << x2 << endl;
    }
    else if (disc < 0)
    {
        float real, imag;
        real = -b / 2;
        imag = pow(abs(disc), 0.5) / 2;
        cout << "La raíces imaginarias son: " << endl
             << "x1: " << real << "+" << imag << "i" << endl
             << "x2: " << real << "-" << imag << "i" << endl;
    }
    else
    {
        float x;
        x = -b / 2;
        cout << "Las raíces repetidas son: " << endl
             << "x: " << x << endl;
    }
}