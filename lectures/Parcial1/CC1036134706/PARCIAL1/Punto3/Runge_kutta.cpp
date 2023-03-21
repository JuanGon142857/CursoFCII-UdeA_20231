#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <ctime>  // a la c++ :)


using namespace std;

bool error=true;
float a=0; float b=0;
int N=0;
double x; double y;
double k1; double k2;double k3;double k4;
int numero=0;
double f(double x,double y)
{
    return y - x*x +1;
}

double sol(double x)
{
    return (x+1)*(x+1)-0.5*exp(x);
}

void presentacion() 
{
    cout<<"\nHola, este codigo es para calcular la solucion numerica de una ecuacion diferencial, en particular vamos a resolver dy/dx= y-x*x+1 \n";


    cout<<"\n Ingrese las condciones de frontera (a,b) y el número de puntos de nuestro problema \n \n";
    
    cout<<"Frontera inicial a:\t";cin>>a;cout<<"\n";
    cout<<"Frontera final b:\t";cin>>b;cout<<"\n";
    cout<<"Condicion inicial a:\t";cin>>y;cout<<"\n";
    cout<<"numero de puntos:\t";cin>>N;cout<<"\n";
}

void euler()
{

    float h=(b-a)/N;
    float arreglo_y[N+1]; arreglo_y[0]=y;
    float arreglo_x[N+1]; arreglo_x[0]=a;
    x=a;
    cout<<"euler";
    for (int i = 1; i < N+1; i++)
    {

        //cout<<" x\t";cout<<x<<"\n";
        //cout<<"y\t";cout<<y<<"\n";
        //cout<<"valor i"<<i*h<<"\n";
        y = y + h*f(x,y); 
        x = a + i*h; 
        arreglo_x[i] =x;
        arreglo_y[i] =y;



        cout<<"\nPaso en x\t "<<arreglo_x[i]<<"\n";
        cout<<"Paso en y\t "<<arreglo_y[i]<<"\n";

    }
}

void RK4()
{
    float h=(b-a)/N;
    float arreglo_y[N+1]; arreglo_y[0]=y;
    float arreglo_x[N+1]; arreglo_x[0]=a;
    x=a;
    cout<<"RK4";

    for (int i = 1; i < N+1; i++)
    {
        k1 = h*f(x, y);
        k2 = h*f(x + h/2,y + k1/2);
        k3 = h*f(x + h/2,y + k2/2);
        k4 = h*f(x + h,y + k3);
        y = y + (k1 + 2*k2 + 2*k3 + k4)/6;
        //cout<<" x\t";cout<<x<<"\n";
        //cout<<"y\t";cout<<y<<"\n";
        //cout<<"valor i"<<i*h<<"\n";
        x = a + i*h; 
        arreglo_x[i] =x;
        arreglo_y[i] =y;

        cout<<"\n Paso en x\t"<<arreglo_x[i]<<"\n";
        cout<<"Paso en y\t "<<arreglo_y[i]<<"\n";

    }    
}

void compara()
{   
    float y2=y;
    float y1=y;
    float h=(b-a)/N;
    float arreglo_y[N+1]; arreglo_y[0]=y;
    float arreglo_x[N+1]; arreglo_x[0]=a;
    x=a;
    cout<<"comparación";

    for (int i = 1; i < N+1; i++)
    {

        //Runge
        k1 = h*f(x, y);
        k2 = h*f(x + h/2,y + k1/2);
        k3 = h*f(x + h/2,y + k2/2);
        k4 = h*f(x + h,y + k3);
        y = y + (k1 + 2*k2 + 2*k3 + k4)/6;


        //Euler

        y1 = y1 + h*f(x,y1); 


        //solucion exacta

        y2=sol(x);


        //paso en x
        x = a + i*h; 


        cout<<"\n\nPaso en x\t "<<x<<" \n";
        cout<<"Error euler y\t "<<abs(y2-y1)<<" \n";
        cout<<"Error Runge y\n "<<abs(y2-y)<<" \n";
        cout<<"S/n Exacta, Euler, RK4 \t";cout<<abs(y2)<<", "<<abs(y1)<<", "<<abs(y);

    }    
}

void metodo()
{
    while(error)
    {
        error=false;
        cout<<"\nEscoja el metodo para solucionar la ecuacion diferencial determinada anteriormente. Runge(1), Euler(2), comparacion(3) selecciones un numero. \n \n ";
        cin>>numero;

        switch (numero)
        {
            case 1:
                cout<<"\n \n Euler \n";
                euler();
                break;

            case 2:
                cout<<"\n RK4 \n";
                RK4();
                break;
            case 3:
                
                cout<<"\n Comparacion error \n";
                compara();
                
    
        
                break;
            default:
                cout<<"\n Error, usted no escogio la opcion correcta \n";
                error=true;
                break;
         }   
    }
}

int main()

{

presentacion();
metodo();

}