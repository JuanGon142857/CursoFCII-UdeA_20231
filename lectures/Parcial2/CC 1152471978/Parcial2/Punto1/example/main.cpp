#include "../include/punto1.h"

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    //sacamos un circulo
    Circular circulo(1.0, 3.1416, 0.01, 10.0, 0.2);

    vector<float> x = circulo.get_xpos();
    vector<float> y = circulo.get_ypos(); 

    circulo.save_data("circular.dat");

    //sacamos una espiral

    Expiral espiral(1.0, 3.1416, 0.01, 10.0, 0.2, 1, 5);

    vector<float> z = espiral.get_zpos();

    espiral.save_data("espiral.dat");  
       



    return 0;

}