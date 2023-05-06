#include <iostream>
#include <iomanip>
#include <math.h>
#include "Circular.h"
#include <fstream>
#include <vector>
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
    x = new vector<double>;
    y = new vector<double>;
}

Circular::~Circular()
{
    cout << "destructor" << endl;
    delete t;
    // delete[] x;
    // delete[] y;
    cout << "destructor 2" << endl;
}

void Circular::setRadio(double radio)
{
    if (radio >= 0)
    {
        radioCircular = radio;
    }
}

double Circular::getRadio() const
{
    return radioCircular;
}

void Circular::setFrecuencia(double frecuencia)
{
    if (frecuencia >= 0)
    {
        frecuenciaCircular = frecuencia;
    }
}

double Circular::getFrecuencia() const
{
    return frecuenciaCircular;
}

void Circular::setDelta_t(double delta_t)
{
    if (delta_t >= 0)
    {
        delta_tCircular = delta_t;
    }
}

double Circular::getDelta_t() const
{
    return delta_tCircular;
}

void Circular::setTiempo(double tiempo)
{
    if (tiempo >= 0)
    {
        tiempo_totalCircular = tiempo;
    }
}

double Circular::getTiempo() const
{
    return tiempo_totalCircular;
}

void Circular::setFase(double fase)
{

    faseCircular = fase * (PI / 180);
}

double Circular::getFase() const
{
    return faseCircular;
}

void Circular::setN()
{
    NCircular = (int)(getTiempo() / getDelta_t());
}

int Circular::getN() const
{
    return NCircular;
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

    for (int i = 0; i <= getN(); i++)
    {
        t->push_back((double)i * getDelta_t());
        // t->at(i) = (double)i * getDelta_t();
    }
}

double Circular::getT(int indice) const
{
    return t->at(indice);
}

void Circular::printT() const
{
    cout << "t=" << endl;
    for (int i = 0; i <= getN(); i++)
    {
        cout << t->at(i) << endl;
    }
}

void Circular::setX()
{

    for (int i = 0; i <= getN(); i++)
    {
        x->push_back(xpos(t->at(i)));
    }
}

double Circular::getX(int indice) const
{
    return x->at(indice);
}

void Circular::printX() const
{
    cout << "Las posiciones en x son: " << endl;
    for (int i = 0; i <= getN(); i++)
    {
        cout << "Para t= " << t->at(i) << setw(3) << " se tiene x= " << x->at(i) << endl;
    }
}

void Circular::setY()
{
    for (int i = 0; i <= getN(); i++)
    {
        y->push_back(ypos(t->at(i)));
    }
}

double Circular::getY(int indice) const
{
    return y->at(indice);
}

void Circular::printY() const
{
    cout << "Las posiciones en y son: " << endl;
    for (int i = 0; i <= getN(); i++)
    {
        cout << "Para t= " << t->at(i) << setw(3) << " se tiene y= " << y->at(i) << endl;
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
    for (int i = 0; i <= getN(); i++)
    {
        dataMovimiento << t->at(i) << "," << x->at(i) << "," << y->at(i) << endl;
    }

    dataMovimiento.close();
}
