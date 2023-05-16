#include <string>
#include <iostream>
using namespace std;

void jugarNuevamente(); //Pregunta al usuario si desea jugar nuevamente
void jugar();

const string palabra = "ahorcado";

int main(){

    cout << string(20, '=') << endl;
    cout << "JUEGO DEL AHORCADO" << endl << "ADIVINA LA PALABRA" << endl;
    cout << "REGLAS:\nIngrese una letra (minuscula). si desea adivinar ingrese una palabra" << endl;
    cout << string(20, '=') << endl;

    jugar();
    return 0;
}

void jugarNuevamente(){
    string j{""};
    cout << "Deseas jugar nuevamente? (S/N)";
    cin >> j;

    if(j == "S" || j == "s")
        jugar();
    else{
        cout << "FIN DEL JUEGO!" << endl;
        exit(0);
    }
}

void jugar(){
    string adivinado = string(palabra.size(), '*'); //Letras adivinadas por el usuario
    unsigned int j{0}; //Contador del while
    string input{""}; //Input del usuario
    cout << string(20, '=') << endl;;
    while(j<7){
        cout << "PALABRA:" << adivinado << endl;
        cout << "Adivinar: ";
        cin >> input;

        //Busca y reemplaza la letra ingresada si es que pertenece a la palabra
        int l = palabra.find(input[0]);
        if(input.size() == 1){

            //Remplazada en adivinado para mostrar en pantalla las letras adivinadas
            while(l != string::npos){
                adivinado.replace(l, 1, input);
                l = palabra.find(input[0], l+1);
            }

            //Si logra adivinar imprime GANASTE!
            if(adivinado == palabra){
                cout << "GANASTE!" << endl;
                jugarNuevamente();
            }
            else{
            j++;
            }
        }

        //Si ingresa una palabra y es correcta imprime GANASTE! de lo contrario imprime PALABRA INCORRECTA, aquí resta 1 a j para no contarlo en los 7 intentos
        else{
            if(input == palabra){
                cout << "GANASTE!" << endl;
                jugarNuevamente();
            }
            else{
                cout << "PALABRA INCORRECTA" << endl;
            }
            j--;
        }
    }
    
    cout << "PERDISTE" << endl;
    jugarNuevamente();
}

