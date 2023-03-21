#include<string>
#include<iostream>

using namespace std;


// Defino la clase Factura
class Factura{

    //Factura(string, string, int, float);

     private:
        string Numero_pieza;
        string descripcion;
        int cantidad;
        float precio;
        
    public:
        Factura(string, string, int, float);//string, string, int, float); // Indica a la clase el tipo de datos va a recibir

        void obtenerMontoFactura();
 
        void setNumero_pieza(string);
        string getNumero_pieza();

        void setdescripcion(string);
        string getdescripcion();

        void setcantidad(int);
        int getcantidad();

        void setprecio(float);
        float getprecio();
};