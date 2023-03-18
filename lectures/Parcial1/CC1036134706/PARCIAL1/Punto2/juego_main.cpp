#include <iostream>
#include<cmath>
#include <iomanip>
#include <cstdlib> // contiene el prototipo de la función rand
//#include <time.h> // "ala c"
#include <ctime>  // a la c++ :)
#include "jueguito.h"


int main()
{
srand(time(NULL)); // TENGA CUIDADO SOLO LLAMAR UNA VEZ
jueguito adivina;
adivina.presentacion();
adivina.juego();

}