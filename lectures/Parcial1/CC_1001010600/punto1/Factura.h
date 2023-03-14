#include <iostream>
#include <string>
using namespace std;

class Factura{
 public:
  Factura();
  void establecer();
  void obtener();
  void obtenerMontoFactura();
 private:
  string numPieza{""}, descripcion{""};
  int cantidad{0};
  float precio{0};
};
