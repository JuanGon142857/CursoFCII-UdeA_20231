#include <iostream>
#include <iomanip>

#include "parcial1_punto1.h"

using namespace std;

Factura::Factura()
{
    // inicializa los miembros de datos
    numeroPieza = " ";
    descripcionPieza = " ";
    cantidad = 0;
    precioArticulo = 0;
    montoFactura = 0;
}

// establece el numero de la pieza
void Factura::set_numeroPieza()
{
    cout << "Ingrese el número de la pieza: ";
    cin >> numeroPieza;
}

// establece la descripcion de la pieza
void Factura::set_descripcionPieza()
{
    cout << "Ingrese la descripcion de la pieza: ";
    cin >> descripcionPieza;
}

// recibe la cantidad de articulos de tipo pieza
void Factura::set_cantidad()
{
    cout << "Ingrese la cantidad de articulos de tipo " << descripcionPieza << ": ";
    cin >> cantidad;
    if (cantidad < 0)
    {
        cout << "La cantidad de articulos no puede ser negativa" << endl;
        set_cantidad();
    }
}

// recibe el precio por articulo de tipo pieza
void Factura::set_precioArticulo()
{
    cout << "Ingrese el precio por articulo de tipo " << descripcionPieza << " en COP: ";
    cin >> precioArticulo;
    if (precioArticulo < 0)
    {
        cout << "El precio por articulo no puede ser negativo" << endl;
        set_precioArticulo();
    }
}

// imprime el numero de la pieza
void Factura::get_numeroPieza()
{
    cout << "El numero de la pieza es: " << numeroPieza << endl;
}

// imprime la descripcion de la pieza
void Factura::get_descripcionPieza()
{
    cout << "La descripcion de la pieza es: " << descripcionPieza << endl;
}

// imprime la cantidad de articulos de tipo pieza
void Factura::get_cantidad()
{
    cout << "La cantidad de articulos de tipo " << descripcionPieza << " es: " << cantidad << endl;
}

// imprime el precio por articulo de tipo pieza
void Factura::get_precioArticulo()
{
    cout << "El precio por articulo de tipo " << descripcionPieza << " es: " << precioArticulo << " COP"<< endl;
}

// calcula el monto total de la compra
void Factura::get_montoFactura()
{
    montoFactura = cantidad * precioArticulo;
    cout << "El monto total de la compra es: " << montoFactura << endl;
}

// imprime la factura final
void Factura::print_factura()
{   get_montoFactura();
    cout << endl;
    cout << "*******************************" << endl;
    cout <<"          Buenos días         " << endl;
    cout<<"         Muchas gracias        " << endl;
    cout <<"por su compra en la ferretería" << endl;
    cout << "          LA CONFIABLE        "<< endl;
    cout << "*******************************" << endl;
    
    cout << "Factura de compra" << endl;
    cout << "Resumen de la compra: " << endl;

  
    cout << numeroPieza<<"  "<< descripcionPieza<<endl;
    cout << "Precio unidad "<< precioArticulo<<" COP" << endl;
    cout << setw(11)<<"X"<<cantidad<<" "<<montoFactura<<" COP"<<endl;  

    cout << endl;
    cout << endl;
    cout << "Total a pagar: " << montoFactura <<" COP"<< endl;
    cout << "*******************************" << endl;

}
