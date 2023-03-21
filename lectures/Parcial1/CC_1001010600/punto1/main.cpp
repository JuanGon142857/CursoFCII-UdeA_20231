#include <iostream>
#include "Factura.h"

int main(){
  Factura F;//Crea el objeto
  //F.establecer(); //Permite cambiar la informacion del articulo
  F.obtener();//Obtiene un dato que solicita el usuario por consola
  F.obtenerMontoFactura();//Obtiene el monto total del articulo
  return 0;
}
