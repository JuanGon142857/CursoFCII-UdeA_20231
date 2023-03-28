#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;
#include "factura.h"

int main(){
    Factura f1("serrucho","dientes_planos",20,10.500);
    f1.getMontoFactura();
    return 0;
}