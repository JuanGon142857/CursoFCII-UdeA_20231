#include <iostream>
#include <cmath>
using namespace std;

//Ecuacion diferencias a solucionar
float diff(float x, float y){
  return y - x*x;
}

/*
  Los metodos reciben:
  - Valores iniciales x0, y0
  - Intervalo a, b
  - Particion del intervalo n
  - Funcion a solucionar dev
  - Valor donde se desea hallar la solucion x
 */
void RK4(float, float, float, float, float, float);
void EulerMej(float, float, float, float, float, float);


int main(){
  cout << "Runge-Kutta 4" << endl;
  RK4(0, 0.5, 0, 2, 1000, 1);
  cout << "Euler mejorado" << endl;
  EulerMej(0, 0.5, 0, 2, 1000, 1);
  return 0;
}

void RK4(float x0, float y0, float a, float b, float n, float x){
  //Definimos variables de paso
  float xf{x0}, yf{y0};
  float h = (b-a)/n;
  //Definimos los diferentes valores de Runge Kutta
  float K1{0}, K2{0}, K3{0}, K4{0};

  while(abs(xf - x) > 0.0001){
    K1 = h * diff(xf, yf);
    K2 = h * diff(xf + 0.5*h, yf + 0.5*K1);
    K3 = h * diff(xf + 0.5*h, yf + 0.5*K2);
    K4 = h * diff(xf + h, yf + K3);

    xf = h + xf;
    yf = yf + ( K1 + 2*K2 + 2*K3 + K4 )/6;
  }
  cout << "y(" << x << ") = " << yf << endl;
}

void EulerMej(float x0, float y0, float a, float b, float n, float x){
  //Definimos variables de paso
  float xf{x0}, yf{y0};
  float h = (b-a)/n;
  float yp{0};

  while(abs(xf - x) > 0.0001){
    yp = yf + h*diff(xf, yf);
    yf = yf + 0.5*h * (diff(xf, yf) + diff(xf + h, yp));
    xf = h + xf;
  }
  cout << "y(" << x << ") = " << yf << endl;
}
