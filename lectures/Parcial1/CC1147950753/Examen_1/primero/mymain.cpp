#include <iostream>
#include <string>
#include "punto1.h"

using namespace std;

int main()
{
string Numero_pieza,descripcion;
float precio;
int cantidad;

cout<<"Para obtener la factura de tu compra por favor ingrese:  "<<endl;
cout<<"*Numero de pieza, *Descripción, *Cantidad y *Precio"<<endl;
cout<<"Número de pieza : "<<endl;
getline(cin,Numero_pieza);
cout<<"Descripción : "<<endl;
getline(cin,descripcion);
cout<<"Cantidad : "<<endl;
cin>>cantidad;
cout<<"Precio : "<<endl;
cin>>precio;

Factura factura(Numero_pieza,descripcion,cantidad,precio);

factura.obtenerMontoFactura();

return 0; 
}