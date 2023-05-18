#include "espiral.h"
//#include "circular.h"

using namespace std;

int main(){
    //circular circulo(6,30,0.01,10,0);
    espiral espi(5, 30, 0.1, 20, 0, 4,20);

    //circulo.imprimir();
    espi.imprimir();

    return 0;
}