#include <iostream>
#include <string>
using std::string;

class Factura
{
private:
    string numArt;
    string descriptionArt;
    int cantArt;
    double priceArt;

public:
    Factura();
    string getNumArt();
    void setNumArt();
    string getDescriptionArt();
    void setDescriptionArt();
    int getCantArt();
    void setCantArt();
    double getPriceArt();
    void setPriceArt();
    void resumenCompra();
    void obtenerMontoFactura();
};