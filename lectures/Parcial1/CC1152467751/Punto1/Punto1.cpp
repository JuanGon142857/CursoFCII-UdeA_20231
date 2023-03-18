#include <iostream>
#include <string>
#include "Punto1.h"
// using std::string;
using namespace std;

Factura::Factura()
{
    setNumArt();
    setDescriptionArt();
    setCantArt();
    setPriceArt();
}

string Factura::getNumArt()
{
    return numArt;
};

void Factura::setNumArt()
{
    cout << "Ingrese el número del artículo: " << endl;
    getline(cin, numArt);
};

string Factura::getDescriptionArt()
{
    return descriptionArt;
};

void Factura::setDescriptionArt()
{
    cout << "Ingrese la descripción del artículo en venta: " << endl;
    getline(cin, descriptionArt);
};

int Factura::getCantArt()
{
    return cantArt;
};

void Factura::setCantArt()
{
    int cantidad;
    cout << "Ingrese la cantidad de artículos que se van a vender: " << endl;
    cin >> cantidad;
    if (cantidad < 0)
    {
        cantArt = 0;
    }
    else
    {
        cantArt = cantidad;
    }
};

double Factura::getPriceArt()
{
    return priceArt;
};

void Factura::setPriceArt()
{
    double precioUnidad;
    cout << "Ingrese el precio por unidad del artículo: " << endl;
    cin >> precioUnidad;
    if (precioUnidad < 0)
    {
        priceArt = 0;
    }
    else
    {
        priceArt = precioUnidad;
    }
};

void Factura::resumenCompra()
{
    cout << "Resumen de la compra: " << endl
         << "El número de artículo es: " << getNumArt() << endl
         << "La descripción del artículo es: " << getDescriptionArt() << endl
         << "La cantidad de artículos que se van a comprar son: " << getCantArt() << endl
         << "El precio por unidad es: " << getPriceArt() << endl;
}

void Factura::obtenerMontoFactura()
{
    double monto;
    monto = getCantArt() * getPriceArt();
    cout << "El monto total de la compra es: " << monto << endl;
};