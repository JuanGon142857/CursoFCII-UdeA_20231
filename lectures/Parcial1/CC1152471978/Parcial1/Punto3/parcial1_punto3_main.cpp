
#include "parcial1_punto3.h"

float f( float x, float y){
    return y - pow(x,2) + 1;
    }
int main()
{

float x0 = 0;
float y = 0.5;
float x ; 
float h = 0.2;
int n = 10;
euler_modificado(x0, y, h, x=2,n=10);
runge_kutta_4(x0, y, h, x=2,n=10); 
return 0;
}