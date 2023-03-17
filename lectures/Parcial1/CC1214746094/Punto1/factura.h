#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class Factura{
    private:
        string Numero_art;
        string Detalle_art;
        int Cantidad_art;
        float Precio_art;

    public:
        Factura(string, string, int, float);
        void setNumero_art(string);
        string getNumero_art();

        void setDetalle_art(string);
        string getDetalle_art();

        void setCantidad_art(int);
        int getCantidad_art();

        void setPrecio_art(float);
        float getPrecio_art();

        float getMontoFactura();




};