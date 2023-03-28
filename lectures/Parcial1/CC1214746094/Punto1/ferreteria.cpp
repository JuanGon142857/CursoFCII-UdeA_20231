#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;
#include "factura.h"

Factura::Factura(string numero, string detalle,int cantidad, float precio){
    setNumero_art(numero);
    setDetalle_art(detalle);
    setCantidad_art(cantidad);
    setPrecio_art(precio);
}

void Factura::setNumero_art(string numero){
    Numero_art = numero;
}

string Factura::getNumero_art(){
    return Numero_art;
}

void Factura::setDetalle_art(string detalle){
    Detalle_art = detalle;
}

string Factura::getDetalle_art(){
    return Detalle_art;
}

void Factura::setCantidad_art(int cantidad){
    Cantidad_art = cantidad;
    if (Cantidad_art < 0){
        Cantidad_art=0;
    };
}

int Factura::getCantidad_art(){
    return Cantidad_art;
}

void Factura::setPrecio_art(float precio){
    Precio_art = precio;
    if (Precio_art < 0){
        Precio_art=0;
    }
}

float Factura::getPrecio_art(){
    return Precio_art;
}

float Factura::getMontoFactura(){
    float montofactura;

    montofactura = Cantidad_art * Precio_art;
    cout <<"El monto de la factura es:"<<montofactura<<endl;
}