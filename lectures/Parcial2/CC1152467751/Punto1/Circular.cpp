#include <iostream>
#include <iomanip>
#include <math.h>
#include "Circular.h"
#include <fstream>
using namespace std;

const double PI = acos(-1);

Circular::Circular(double radio, double frecuencia, double delta_t, double tiempo, double fase)
{
    setRadio(radio);
    setFrecuencia(frecuencia);
    setDelta_t(delta_t);
    setTiempo(tiempo);
    setFase(fase);
    setN();
    t = new vector<double>;
    setT();
    x = new vector<double>;
    setX();
    y = new vector<double>;
    setY();
}

Circular::~Circular()
{
    delete[] t;
    delete[] x;
    delete[] y;
}

void Circular::setRadio(double radio)
{
    if (radio >= 0)
    {
        radio = radio;
    }
}

double Circular::getRadio() const
{
    return radio;
}

void Circular::setFrecuencia(double frecuencia)
{
    if (frecuencia >= 0)
    {
        frecuencia = frecuencia;
    }
}

double Circular::getFrecuencia() const
{
    return frecuencia;
}

void Circular::setDelta_t(double delta_t)
{
    if (delta_t >= 0)
    {
        delta_t = delta_t;
    }
}

double Circular::getDelta_t() const
{
    return delta_t;
}

void Circular::setTiempo(double tiempo)
{
    if (tiempo >= 0)
    {
        tiempo_total = tiempo;
    }
}

double Circular::getTiempo() const
{
    return tiempo_total;
}

void Circular::setFase(double fase)
{

    fase = fase * (PI / 180);
}

double Circular::getFase() const
{
    return fase;
}

void Circular::setN()
{
    N = (int)(getTiempo() / getDelta_t());
}

int Circular::getN() const
{
    return N;
}

double Circular::xpos(double t)
{
    return getRadio() * cos(getFrecuencia() * t + getFase());
}

double Circular::ypos(double t)
{
    return getRadio() * sin(getFrecuencia() * t + getFase());
}

void Circular::setT()
{

    for (int i = 0; i < N; i++)
    {
        t->push_back(i * getDelta_t());
    }
}

void Circular::setX()
{
    for (int i = 0; i < N; i++)
    {
        x->push_back(xpos(t->at(i)));
    }
}

void Circular::getX() const
{
    cout << "Las posiciones en x son: " << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "Para t=" << t->at(i) << setw(3) << "se tiene x=" << x->at(i) << endl;
    }
}

void Circular::setY()
{
    for (int i = 0; i < N; i++)
    {
        y->push_back(ypos(t->at(i)));
    }
}

void Circular::getY() const
{
    cout << "Las posiciones en y son: " << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "Para t=" << t->at(i) << setw(3) << "se tiene y=" << y->at(i) << endl;
    }
}

void Circular::EscribirDocumento()
{
    ofstream dataMovimiento("dataMovimiento.txt");

    if (!dataMovimiento)
    {
        // cout << "No se pudo abrir el archivo" << endl;
        cerr << "No se pudo abrir el archivo" << endl;
        exit(1);
    }
    dataMovimiento << "t,x,y" << endl;
    for (int i = 0; i < t->size(); i++)
    {
        dataMovimiento << t->at(i) << "," << x->at(i) << "," << y->at(i) << endl;
    }

    dataMovimiento.close();
}
