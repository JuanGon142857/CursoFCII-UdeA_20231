#include "Espiral.h"
#include "Circular.h"

#include <iostream>
#include <iomanip>

int main(){
    circular circulo(1, 10, 0.001, 1, 0);
    expiral espiral(1, 1, 10, 1, 0.001, 1, 0);

    circulo.imprimir();
    espiral.imprimir();

    /*std::cout << "Vectores: " << std::endl;

    for(int i = 0; i < espiral.get_N(); i++){
        std::cout << std::setw(14) << espiral.get_xvec().at(i);
        std::cout << std::setw(14) << espiral.get_yvec().at(i);
        std::cout << std::setw(14) << espiral.get_zvec().at(i) << std::endl;
    }*/

    // Para generar la gráfica, Python3 debe estar instalado junto con matplotlib y pandas
    // Si no cumple los requisitos deje comentada la línea:
    espiral.graphdata();
    return 0;

}
