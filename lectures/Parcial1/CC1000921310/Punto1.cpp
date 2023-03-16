#include <iostream>
#include <iomanip>

#include "Punto1.h"

using namespace std;

Factura::Factura(){
    establecerNumero_pieza();
    establecerDescripcion_pieza();
    establecerPrecio_unidad();
    establecerCantidad();
} 

void Factura::establecerNumero_pieza(){
    cout << endl << "Ingrese el numero del producto: ";
    cin >> Numero_pieza;
}

void Factura::establecerDescripcion_pieza(){
    cout << endl << "Ingrese una descripcion del producto: ";
    std::getline(std::cin, Descripcion_pieza);
    std::getline(std::cin, Descripcion_pieza);
    
    if ( Descripcion_pieza.length() > 25 ){
    Descripcion_pieza = Descripcion_pieza.substr( 0, 25 );
    cout << "La descricion excede la longitud maxima (25)." << endl
	   << "Se limito a los primeros 25 caracteres." << endl;
    }
}

void Factura::establecerPrecio_unidad(){
    cout << endl << "Ingrese el precio del producto por unidad: $";
    cin >> Precio_unidad;
    if ( Precio_unidad < 0 ){
        cout << endl << "Precio invalido, se redefine como 0" << endl;
        Precio_unidad = 0;
    }
}

void Factura::establecerCantidad(){
    cout << endl << "Digite la cantidad ordenada del producto: " ;
    cin >> Cantidad;
    if ( Cantidad < 0 ){
        cout << endl << "Cantidad invalida, se redefine como 0" << endl;
        Cantidad = 0;
    }
}

string Factura::obtenerNumero_pieza(){
    return Numero_pieza;
}

string Factura::obtenerDescripcion_pieza(){
    return Descripcion_pieza;
}

int Factura::obtenerCantidad(){
    return Cantidad;
}

float Factura::obtenerPrecio_unidad(){
    return Precio_unidad;
}

float Factura::obtenerMontoFactura(){
    return float(Cantidad) * Precio_unidad;
}

void Factura::mostrarFactura(){
    cout << "\n\n\n\n" << "FACTURA" << endl;
    cout << "Numero producto: " << obtenerNumero_pieza() << endl;
    cout << "Descripcion producto: " << obtenerDescripcion_pieza() << endl;
    cout << "Precio unitario: $" << setw(3) << fixed << setprecision(2) << obtenerPrecio_unidad() << endl;
    cout << "Cantidad: " << obtenerCantidad() << endl;

    cout << "Monto total: $" << setw(3) << fixed << setprecision(2) << obtenerMontoFactura() << endl;
}