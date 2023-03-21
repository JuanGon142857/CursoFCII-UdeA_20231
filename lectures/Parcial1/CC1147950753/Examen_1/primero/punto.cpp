#include <iostream>
#include "punto1.h" // traigo el archivo cursename.h

using namespace std;

// Defino el constructor para inicializar las variables
Factura::Factura(string valor_1, string valor_2, int valor_3, float valor_4){
     setNumero_pieza(valor_1);
     setdescripcion(valor_2);
     setcantidad(valor_3);
     setprecio(valor_4);
}




// defino la funcion "obtenerMonoFactura()"
void Factura::obtenerMontoFactura(){
    float monto;
        monto = precio*cantidad;
   

        cout<<"...... Factura del articulo ...... "<<endl;
        cout<<" Descripcion : "<<descripcion<<endl;
        cout<<" numero de pieza : "<<Numero_pieza<<endl;
        cout<<"Cantidad : "<<cantidad<<endl;
        cout<<"Precion por unidad : "<<precio<<endl;
        cout<<"--------------------------------------"<<endl;
        cout<<"Valor total : "<<monto<<endl;


}

/// Defino los setters

void Factura::setNumero_pieza(string _Numero_pieza){
        Numero_pieza = _Numero_pieza;
}

void Factura::setdescripcion(string _descripcion){
        descripcion = _descripcion;
}

void Factura::setcantidad(int _cantidad){
        if(_cantidad<0){
            cantidad=0;
        }else{
            cantidad=_cantidad;
        }

        //cantidad=_cantidad<0?0:_cantidad;
        
}

void Factura::setprecio(float _precio){
        if(_precio<0){
            precio=0;
        }else{
            precio=_precio;
        }
}

//// Defino los getters-----------------------------------------

string Factura::getNumero_pieza(){
        return Numero_pieza;
}

string Factura::getdescripcion(){
        return descripcion;
}

int Factura::getcantidad(){
        return cantidad;
}

float Factura::getprecio(){
        return precio;
}
