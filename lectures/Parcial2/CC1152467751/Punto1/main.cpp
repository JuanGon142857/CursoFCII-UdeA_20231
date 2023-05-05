#include <iostream>
#include <iomanip>
#include <math.h>
#include "Circular.h"
#include <fstream>
using namespace std;

int main()
{

    Circular circulo(3.0, 5.0, 0.1, 3.0, 0.0);
    circulo.getX();
    circulo.getY();
    // circulo.EscribirDocumento();

    return 0;
}
