#include <string>

using namespace std;

#include "LibroCalificaciones.h" 

int main()
{

  // arreglo de calificaciones de estudiantes
  int arregloCalificaciones[ LibroCalificaciones::estudiantes ] = { 0, 0, 98, 56, 76, 96, 86, 96, 84, 44};
  LibroCalificaciones miLibroCalificaciones("2023-1 Introduccion a la programacion en C++", arregloCalificaciones );
  miLibroCalificaciones.mostrarMensaje();
  miLibroCalificaciones.procesarCalificaciones();
  return 0;
}
