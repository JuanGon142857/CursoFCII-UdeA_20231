#include <iostream>
#include <iomanip>
#include <string>

#include "Factura.h"

using namespace std;

Factura::Factura(){
	set_code();
	set_desc();
	set_cant();
	set_precio();
}

void Factura::set_code(){
	cout << "Introduzca el código del item a facturar:\n";
	getline(cin, code);
}

void Factura::set_desc(){
	cout << "Ingrese la descripción del ítem:\n";
	getline(cin, desc);

	{
  	if ( desc.length() > 20 ){ 
      	desc = desc.substr(0, 20 ); 
      	cout << "La descripción \"" << desc << "\" excede la longitud maxima (20).\n"
	   	<< "Se limitó a los primeros 20 caracteres." << endl;
    }
} 
}

void Factura::set_cant(){
	cout << "Ingrese el número de unidades del artículo: ";
	cin >> cantidad;
	if (cantidad < 0) cantidad = 0;
}

void Factura::set_precio(){
	cout << "Ingrese el precio por unidad: ";
	cin >> precio;
	if (precio < 0) precio = 0;
}

string Factura::get_code(){
	return code;
}

string Factura::get_desc(){
	return desc;
}

float Factura::get_precio(){
	return precio;
}

int Factura::get_cant(){
	return cantidad;
}

float Factura::obtenerMontoFactura(){
	total = cantidad * precio;
	return total;
}

void Factura::print_articulo(){
	cout << setw(10) << code
	<< setw(22) << desc
	<< setw(3) << cantidad
	<< setw(8) << precio
	<< setw(8) << total << endl;
}