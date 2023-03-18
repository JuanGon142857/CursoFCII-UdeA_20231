#include <string> 
using std::string;

class factura
{
public:

factura(string); 

void establecer_Numero_factura( ); 
string obtener_Numero_factura();

void establecer_Descrip_articulo(  ); 
string obtener_Descrip_articulo();

void establecer_Precio_articulos(  ); 
float obtener_Precio_articulos();

void establecer_Numero_articulos(  ); 
int obtener_Numero_articulos();


void mostrarMensaje(); 
float obtenerMontoFactura( ); 

float precio_factura; 
string numero;

private:

string descrip_articulo; 
string numero_factura;
float precio_articulo;
int numero_articulos;

}; 