
#include <string> 
using std::string;

class Factura{
public:
    Factura(); 
    void establecerNumero_pieza(); 
    void establecerDescripcion_pieza(); 
    void establecerCantidad(); 
    void establecerPrecio_unidad(); 

    string obtenerNumero_pieza();
    string obtenerDescripcion_pieza();
    int obtenerCantidad();
    float obtenerPrecio_unidad();

    float obtenerMontoFactura();

    void mostrarFactura(); 
 
private:
    string Numero_pieza;
    string Descripcion_pieza; 
    float Cantidad; 
    float Precio_unidad;
}; 