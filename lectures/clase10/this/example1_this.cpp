// Uso del apuntador this para hacer referencia a los miembros de un objeto.
#include <iostream>

using namespace std;

class Prueba
{
public:
  Prueba( int = 0 ); 
  void imprimir() const;
private:
  int x;
};


// constructor
Prueba::Prueba( int valor )
  : x( valor ) // inicializa x con valor
{
  // cuerpo vacío
}

// imprime x usando los apuntadores implícito y explícito;
// los paréntesis alrededor de *this son obligatorios
void Prueba::imprimir() const
{
  // usa de manera implícita el apuntador this para
  cout << "x = " << x;
  // usa de manera explícita el apuntador this y el apuntador (operador flecha)
  // para acceder a la x del miembro
  cout << "\n this->x = " << this->x;
  // usa de manera explícita el apuntador this desreferenciado y
  // el operador punto para acceder a la x del miembro
  cout << "\n(*this).x = " << ( *this ).x << endl;
} 

int main()
{
  Prueba objetoPrueba( 12 ); 
  objetoPrueba.imprimir();
  return 0;
} 
