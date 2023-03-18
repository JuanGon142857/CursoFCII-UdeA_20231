#include <iostream>
#include <vector>
#include <iomanip>

#include "Factura.h"

using namespace std;

int main(){

    cout << "Bienvenido al sistema de facturación.\n";
    cout << "A continuación se le solicitará información para generar la factura de la compra.\n";

    int keep_going = 1;
    string keep = "S";
    vector <Factura> articulos;
    float total_articulos = 0;


    while (keep_going == 1){
        Factura articulo;
        cout << "El monto total de la factura es: " << articulo.obtenerMontoFactura() << endl;
        articulos.push_back(articulo);
        cout << "\n";
        cout << "¿Desea agregar otro ítem a la factura? (S ó N)";
        cin >> keep;
        // Para ignorar el salto de línea del último cin.
        // Si no se ignora se salta el siguiente getline
        // ¿Cómo se trabaja con getline y cin dentro de la implementación de la clase?
        cin.ignore();
        if (keep == "S" || keep == "s") keep_going = 1;
        else keep_going = 0;
    }

    cout << setw(10) << left << "Código"
	<< setw(24) << left << "Descripción"
	<< setw(3) << left << "#"
	<< setw(8) << left << "Precio"
	<< setw(8) << left << "Total" << endl;

    for  (Factura f : articulos){
        f.print_articulo();
        total_articulos += f.obtenerMontoFactura();
    }

    cout << "Total: " << total_articulos << endl;


    return 0;
}