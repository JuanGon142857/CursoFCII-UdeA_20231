#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <ctime>  // a la c++ :)

#include "jueguito.h"

using namespace std;

jueguito::jueguito( )
{
bool estado_juego=true;
bool error=false;
int numero=0;
int respuesta=0;
int decision=0;
}

void jueguito::presentacion()
{
  cout << "\n Bienvendio al juego mas divertido de Fisica computacional II \n "<<"Nosotros vamos a escoger un numero pseudoaleatorio y usted tendra que adivinarlo, el numero estara entre 1-1000, les deseamos mucha suerte \n";
}

void jueguito::mensaje()
{
    switch (error)
    {
    case true : 
    cout<<"\n Usted no ha seguido las indicaciones \n";
        break;
    
    default:
    cout<<"\nIntente adivinar el numero con todas sus fuerzas\n"<<"Ingrese un numero de 1 a 1000\n";

    cout<<"\n";cin>>numero;cout<<"\n \n";

    ////error=false;
        break;
    }
}
void jueguito::juego()
{
    respuesta=1 + rand() % 1000;
    //cout<<respuesta;
    cout<<"\n \n";
    while (estado_juego==true)
    {
    //cout<<"<<error"<<error;
        mensaje();
    error=false;

    //usleep(1);

    

    if (numero==respuesta || error==true)
    {
        cout<<"\n ¿Desea seguir jugando?\n"<<"Si(1), No(2), ingrese solamente el numero.\n";
        cin>>decision;
        //cout<<decision;

        switch (decision)
        {
        case 1:
            estado_juego=true;
            respuesta=1 + rand() % 1000;


            cout<<" \n Felicitaciones, usted ha encontrado el numero ganador, continuemos jugando  \n";

            break;
        
        case 2:
            estado_juego=false;

            cout<<" \n Felicitaciones, usted ha encontrado el numero ganador \n";

            break;
        default:
            
            error=true;
            break;
        }
        
    }

    else if (numero>respuesta)
    {
        cout<<"\n El numero escogido es mayor que la respuesta \n";
    }
    
    else
    {
        
        cout<<"\n El numero escogido es menor que la respuesta \n";

    }
  
}
}