/*
Cree una clase llamada Factura , que una ferretería podría utilizar para representar una fac-
tura por un artículo vendido en la tienda. Una Factura debe incluir cuatro piezas de informa-
ción como miembros de datos: un número de pieza (tipo string ), la descripción de la pieza
(tipo string ), la cantidad de artículos de ese tipo que se van a comprar y el precio por artículo.
Su clase debe tener un constructor que inicialice los cuatro miembros de datos. Proporcione
una función establecer y una función obtener para cada miembro de datos. Además, pro-
porcione una función miembro llamada obtenerMontoFactura , que calcule el monto de la
factura (es decir, que multiplique la cantidad por el precio por artículo) y después devuelva
ese monto como un valor. Si la cantidad no es positiva, debe establecerse en 0. Si el precio por
artículo no es positivo, debe establecerse en 0. Escriba un programa de prueba que demuestre
las capacidades de la clase Factura
*/  
#include <string>
class Factura

{
public:
    Factura();                  // constructor
    void set_numeroPieza();     // establece el numero de pieza
    void set_descripcionPieza();// establece la descripcion de la pieza
    void set_cantidad();        // establece la cantidad de articulos
    void set_precioArticulo();  // establece el precio por articulo

    void get_numeroPieza();     // obtiene el numero de pieza
    void get_descripcionPieza();// obtiene la descripcion de la pieza
    void get_cantidad();        // obtiene la cantidad de articulos
    void get_precioArticulo();  // obtiene el precio por articulo
    void get_montoFactura();    // obtiene el monto de la factura

    void print_factura();       // imprime la factura

private:
    
    std::string numeroPieza;         // numero de pieza
    std::string descripcionPieza;    // descripcion de la pieza
    int cantidad;                   // cantidad de articulos
    int precioArticulo;             // precio por articulo
    int montoFactura;               // monto de la factura
};