/*
Ecuaciones Diferenciales Ordinarias.
Proyecto asociado al parcial uno. Investigue en que consisten los metodos “Modified Euler" y
“Runge-Kutta Order Four". Cree un programa en c++ para resolver ecuaciones diferenciales
ordinarias usando estos métodos y compare los resultados.
Como ejemplo: dy/dx = y −t2+ 1, 0 ≤x ≤2, y(0) = 0.5.
*/
#include <iostream> 
#include <cmath>
#include <iomanip>
using namespace std;


void euler_modificado(float x0, float y0, float h, float x, int n);
void runge_kutta_4(float x0, float y0, float h, float x, int n);
float f( float x, float y);





