#include <stdlib.h> 
#include <time.h>
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main(){
    int num;
    int num_persona;
    bool condicional=true;

    srand(time(NULL));
    num= 1+ rand() % (10);
    cout << "Adivine un numero entre 1 y 1000" << endl;
    cin >> num_persona;
    while(condicional)
    {
        if(num_persona!=num){
            if(num_persona>num){
                cout<<"\nSu numero es mayor. Digite uno menor\n";
                cin >> num_persona;
            }
            if(num_persona<num){
                cout<<"\nSu numero es menor. Digite uno mayor\n";
                cin >> num_persona;
            }
        }

        else{
            int respuesta;
            cout << "Has adivinado el numero!" << endl;
            cout << "Si desea volver a jugar ingrese el 1, sino ingrese el 0" <<endl;
            cin >> respuesta;
            if(respuesta==0){
                cout<<"El juego termino"<<endl;
                condicional=false;
            }
            else if (respuesta==1){
                cout <<"Ingrese el nuevo numero para el nuevo juego"<<endl;
                cin >> num_persona;
                num = 1 +rand() % (10);
                condicional=true;
            }
            else{
                cout <<"No ingreso un valor valido"<<endl;
                cout <<"Cerrando programa"<<endl;
                condicional=false;
            }
            
            
        }
        
    }

    
    


    return 0;
}