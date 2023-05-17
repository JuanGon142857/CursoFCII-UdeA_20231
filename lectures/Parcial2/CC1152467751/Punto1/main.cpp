#include <iostream>
#include <iomanip>
#include <math.h>
#include "Espiral.h"
#include <fstream>
using namespace std;

const double PI = acos(-1);

int main()
{
    Espiral espiral(3.0, 1.0, 0.1, 5 * PI, 0.0, 0.0, 2.0);
    espiral.setT();
    espiral.setX();
    espiral.setY();
    espiral.setZ();
    espiral.EscribirDocumento();

    return 0;
}
