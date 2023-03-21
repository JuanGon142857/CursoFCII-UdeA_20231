#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

float dydx (float x, float y); //Función derivada

float ModifiedEuler (float x, float y, float dx); 
float RK4 (float x, float y, float dx);

float t = 3; //Variable global para la función dy/dx = y - t**2 + 1

int main() {
  float x0 = 0; float xf = 2; //Extremos del intervalo
  float y0 = 1; //Valor inicial
  float m = 20;

  float yRK4 = y0; //Valor que se actualizará mediante RK4
  float yEM = y0; //Valor que se actualizará mediante Euler modificado

  float x = x0;
  
  float dx = (xf - x0) / m;

  cout << "   X      Y por Euler        Y por RK4" << endl;
  cout << setw(6) << fixed << setprecision(2) << x
       << setw(12) << setprecision(2) << yEM
       << setw(18) << setprecision(2) << yRK4 << endl;

  for(int i = 0; i < m; i++){
    
    yEM = ModifiedEuler(x, yEM, dx);    yRK4 = RK4(x, yRK4, dx);
    x = x + dx;
    
  cout << setw(6) << fixed << setprecision(2) << x
       << setw(12)  << setprecision(2) << yEM
       << setw(18) << setprecision(2) << yRK4 << endl;
    }  
  return 0;
}

float dydx (float x, float y){
  
  return sin(y);
};

float ModifiedEuler (float x, float y, float dx){
  float y1  = y + dydx(x, y) * dx; //First approximation
  
  return y + (dydx(x, y) + dydx(x + dx, y1)) * dx / 2;
}

float RK4 (float x, float y, float dx){
  float k1 = dydx(x, y);
  float k2 = dydx(x + dx / 2, y + k1 * dx / 2);
  float k3 = dydx(x + dx / 2, y + k2 * dx / 2);
  float k4 = dydx(x + dx, y + k3 * dx);
  
  return y + (k1 + 2 * k2 + 2 * k3 + k4) * dx / 6;
}

