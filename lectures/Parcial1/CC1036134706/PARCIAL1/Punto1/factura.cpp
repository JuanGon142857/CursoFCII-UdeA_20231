#include <iostream>

#include "factura.h"

using namespace std;

factura::factura(string)
{
    mostrarMensaje();
    establecer_Numero_factura();
    establecer_Descrip_articulo( );
    establecer_Precio_articulos( );
    establecer_Numero_articulos( );
    //numero_factura=numero1; 
} 

void factura::establecer_Numero_factura( )
{   
    cout<<" \n Ingrese por favor el numero de factura \t :";cin>>numero_factura;cout<<"\n";
}

string factura::obtener_Numero_factura()
{
  return numero_factura;
}

void factura::establecer_Descrip_articulo( )
{
  cout<<" \n Ingrese por favor la decripcion del articulo \t :";cin>>descrip_articulo;cout<<"\n";
}

string factura::obtener_Descrip_articulo()
{
  return descrip_articulo;
}

void factura::establecer_Precio_articulos( )
{
  cout<<" \n Ingrese por favor el precio del articulo \t :";cin>> precio_articulo;cout<<"\n";
}

float factura::obtener_Precio_articulos()
{
  return precio_articulo;
}

void factura::establecer_Numero_articulos( )
{
    cout<<" \n Ingrese por favor el numero de articulos que desea \t :";cin>> numero_articulos;cout<<"\n";
    
}

void factura::mostrarMensaje()
{
cout << "\nBienvenido, a su tienda preferida \n" ;
}

int factura::obtener_Numero_articulos()
{
  return numero_articulos;

cout << "Bienvenido, su numero de factura para su compra es \t" <<obtener_Numero_factura() << "!\n" << endl;
}


float factura::obtenerMontoFactura( )
{
if (precio_articulo<0 || numero_articulos<0)
{
    cout<<"Usted ha ingresado un precio de articulo o un numero de artculos negativo \n";
    precio_factura =0;
}

else
{
     precio_factura = precio_articulo*numero_articulos; 
    cout<<"Felicidades, usted ha comprado    "<<numero_articulos<<"  "<<descrip_articulo;
    cout<<" \n El total de su compra es : \t"<<precio_factura;
    cout<<" \n Se ha generado un factura con el numero "<<numero_factura <<" por su compra";


}

return precio_factura;
} 
