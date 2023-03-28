#include "parcial1_punto1.h"

int main()
{
    Factura factura1;
    factura1.set_numeroPieza();
    factura1.set_descripcionPieza();
    factura1.set_cantidad();
    factura1.set_precioArticulo();
    factura1.print_factura();
    return 0;
}