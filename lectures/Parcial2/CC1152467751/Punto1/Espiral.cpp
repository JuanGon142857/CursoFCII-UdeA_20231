#include <iostream>
#include <iomanip>
#include <math.h>
#include "Espiral.h"
#include <fstream>
#include <vector>
using namespace std;

Espiral::Espiral(const double radio, const double frecuencia, const double delta_t, const double tiempo, const double fase, const double z_inicial, const double velocidad_z) : Circular(radio, frecuencia, delta_t, tiempo, fase)
{
    setZ_Inicial(z_inicial);
    setVelocidad_z(velocidad_z);
    z = new vector<double>;
}

Espiral::~Espiral()
{
    delete z;
    z = 0;
}

void Espiral::setZ_Inicial(double z_inicial)
{
    z_inicialEspiral = z_inicial;
}

double Espiral::getZ_Inicial() const
{
    return z_inicialEspiral;
}

void Espiral::setVelocidad_z(double velocidad_z)
{
    velocidad_zEspiral = velocidad_z;
}

double Espiral::getVelocidad_z() const
{
    return velocidad_zEspiral;
}

double Espiral::zpos(double t)
{
    return getZ_Inicial() + getVelocidad_z() * t;
}

void Espiral::setZ()
{
    for (int i = 0; i <= getN(); i++)
    {
        z->push_back(zpos(getT(i)));
    }
}

double Espiral::getZ(int indice) const
{
    return z->at(indice);
}

void Espiral::printZ() const
{
    cout << "Las posiciones en z son: " << endl;
    for (int i = 0; i <= getN(); i++)
    {
        cout << "Para t= " << getT(i) << setw(3) << " se tiene z= " << z->at(i) << endl;
    }
}

void Espiral::EscribirDocumento()
{
    ofstream dataMovimiento("dataMovimiento.txt");

    if (!dataMovimiento)
    {
        // cout << "No se pudo abrir el archivo" << endl;
        cerr << "No se pudo abrir el archivo" << endl;
        exit(1);
    }
    dataMovimiento << "t,x,y,z" << endl;
    for (int i = 0; i <= getN(); i++)
    {
        dataMovimiento << getT(i) << "," << getX(i) << "," << getY(i) << "," << z->at(i) << endl;
    }

    dataMovimiento.close();
}
