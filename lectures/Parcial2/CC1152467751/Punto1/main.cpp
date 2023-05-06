#include <iostream>
#include <iomanip>
#include <math.h>
#include "Circular.h"
#include <fstream>
using namespace std;

const double PI = acos(-1);

int main()
{

    Circular circulo(3.0, 1.0, 0.1, 2 * PI, 0.0);
    cout << circulo.xpos(PI) << endl;
    cout << "Cos de pi= " << cos(PI) << endl;
    cout << "los atributos: " << circulo.getRadio() << " " << circulo.getFrecuencia() << " " << circulo.getFase() << endl;
    cout << "replicando xpos: " << circulo.getRadio() * cos(circulo.getFrecuencia() * PI + circulo.getFase()) << endl;
    cout << circulo.getN() << endl;
    circulo.setT();
    circulo.printT();
    circulo.setX();
    circulo.printX();
    circulo.setY();
    circulo.printY();
    circulo.EscribirDocumento();

    return 0;
}
