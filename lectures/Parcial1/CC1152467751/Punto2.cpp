#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

bool Flag = 1, repetir = 1;
int number, number_choice;

int main()
{
    srand(time(NULL));

    while (repetir != 0)
    {
        number = 1 + rand() % (100 + 1 - 1);
        cout << "Seleccione un número del 1 al 100: " << endl;
        while (Flag != 0)
        {
            cin >> number_choice;
            if (number_choice == number)
            {
                cout << "¡Ha adivinado el número!" << endl;
                Flag = 0;
            }
            else if (number_choice < number)
            {
                cout << "El número seleccionado es menor" << endl;
            }
            else
            {
                cout << "El número seleccionado es mayor" << endl;
            }
        }
        cout << endl
             << "¿Desea volver a jugar?" << endl
             << "Introduzca 1 si desea volver a jugar o 0 si desea salir del juego:  " << endl;
        cin >> repetir;
        Flag = repetir == 1 ? 1 : 0;
    }
}
