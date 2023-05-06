#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <array>
#include <iomanip>
#include <ctime>  // a la c++ :)
using namespace std;


int item1=0,max=0,min=0, j=0, tamaño_arreglo=10;
string decision;
bool continuar= true;

//array<int, 10> A;
int B[10], A[ 10 ], C[ 10 ];

void presentacion();
void ordenamiento_borbuja(int [], int);
void ordenamiento_eficiente(int [], int);
int maximo(int [],int);
void imp_arreglo(int[],int);


int main() {

    presentacion();
    srand(time(NULL)); // TENGA CUIDADO SOLO LLAMAR UNA VEZ

   for (int i = 0  ;i<size(A) ;i=i+1) 
   {
        item1=1 + rand() % 100;
        A[i]=item1;
        
   }
    
    while (continuar)
    {


  
        cout << "\n ¿ Que metodo quiere utilizar para organizar su arreglo? Ingrese la opcion (1) para el metodo eficiente o (2) para el metodo de borbujas" <<endl; 
        cin >> decision;
    
        if (decision=="1")
        {
            
            ordenamiento_eficiente(A,tamaño_arreglo);
            continuar=false;
            
        }
        
        else if(decision=="2")
        {
            ordenamiento_borbuja(A,tamaño_arreglo);
            continuar=false;
            
        }

        else
        {
            cout << " \n Por favor ingrese una opción valida. (1) o (2) \n" << endl;
            
        }
        
        string k;
        if (continuar==false)
        {
            cout << "\n \n ¿Desea continuar volver a correr el codigo?, (si (y), no (n))"<<endl;
            cin>> k;
            if (k=="n")
            {
                cout << " \n Gracias por escogernos" <<endl;
                exit;
            }
        
            else if (k=="y")
            {
                string repeat;
                continuar=true;
                 cout << " \n El menu se va a reiniciar ¿Quiere utilizar el mismo arreglo  (si (y), no (n)) ? \n" <<endl;
                 cin>>  repeat;
                 if (repeat=="n")
                 {
                          //Creación de arreglo
                    for (int i = 0  ;i<size(A) ;i=i+1) 
                        {
                        item1=1 + rand() % 100;
                        A[i]=item1;
                        }
                    
                 }
                 if (repeat=="y")
                 {
                    cout<<"En breve iniciara con el mismo arreglo "<<endl;

                 }

                 else{
                    cout<<"Error, opcion no valida. Vuelve a ejecutar el programa"<<endl;
                    exit;
                 }

                 
                 
            }
            else
            {
               continuar=true;
               cout << " \n Escogio una opcion incorrecta, vuelva a ingresar la opcion" <<endl;
               
            }
            
            
    
        }         
    }
   return 0;
}
void imp_arreglo(int A[],int tamaño)
    {
        for (int i = 0; i < tamaño; i++)
        {
            cout << setw( 4 )<< A[i]  << setw( 10);
        }    
    }
int maximo(int A[],int tamaño)
    {
    int max_local=0;
    int k=0;
    for (int i = 0; i < tamaño; i++)
    {
        if (A[i]>max_local)
        {
            max_local=A[i];
            k=i;
        }
    }
    return k;
 }
void ordenamiento_borbuja(int A[], int tamaño_arreglo){
    int max_conteo=0;
    int num_intercambios=0;
    cout << "\n Arreglo ordenado con borbujas " <<endl;
    //arreglo espejo
    for ( int mm = 0; mm < tamaño_arreglo; mm++ )
    {
        B[mm]=A[mm];
    }

    for ( int i = 1; i < tamaño_arreglo; i++ )
    {
        for (j=0 ; j<tamaño_arreglo - 1; j++)
        {
            max_conteo+=1;
            if (A[j] > A[j+1] )
            {
                num_intercambios+=1;
                item1 = A[j];
                A[j] = A[j+1];
                A[j+1] = item1;
            }
        cout<<" \n Arreglo por partes \n";
        imp_arreglo(A,tamaño_arreglo);
        } 
    }
    cout<<" \n Resultados finales \n";
    cout<<" \n Arreglo ordenado \n";
    imp_arreglo(A,tamaño_arreglo);
    cout<<"\n Arreglo inicial \n";
    imp_arreglo(B,tamaño_arreglo);

     cout<<" \n \n Numero de intercambios : "<< num_intercambios<<" ,Numero de iteraciones \n : "<<max_conteo<<endl;
}
void ordenamiento_eficiente(int [], int)
{
    int exchange=1;
    cout << "\n Arreglo ordenado con borbujas_eficiente " <<endl;
    //arreglo espejo
    for ( int mm = 0; mm < tamaño_arreglo; mm++ )
    {
        B[mm]=A[mm];
    }
    //ordenar
    int max_conteo=0;
    int num_intercambios=0;
    //int max_local = A[k], change;
    //cout <<" \n max local \t"<< max_local<<endl;
    for ( int i = 0; i < tamaño_arreglo; i++ )
    {

        if (exchange==0)
        {
            cout<< "No hay mas intercambios" << endl;
            break;
        }
        exchange=0;
        for (j=0 ; j<tamaño_arreglo - (1+i); j++)
        {

            max_conteo+=1;
            if (A[j] > A[j+1] )
            {   
                num_intercambios+=1;
                exchange+=1;
                item1 = A[j];
                A[j] = A[j+1];
                A[j+1] = item1;
            }

            else
            {
                exchange+=0;
    
            }
            

            
            
            
        cout<<" \n Iteracion interna : "<< j<<" , Iteracion externa : "<<i<<endl;
        imp_arreglo(A,tamaño_arreglo);
        
       
        
        } 
    }

     cout<<" \n Numero de intercambios : "<< num_intercambios<<" ,Numero de iteraciones  : "<<max_conteo<<endl;
    cout<<" \n Arreglo ordenado \n";
    imp_arreglo(A,tamaño_arreglo);
    cout<<"\n Arreglo inicial \n";
    imp_arreglo(B,tamaño_arreglo);
}
void presentacion()
{
  cout << "\n Bienvendio al curso de Fisica computacional II \n "<<"Vamos a organizar una lista de 10 números aleatorios entre 1-100, para ello se va utilizar el metodo de borbuja(Buble sort) y el metodo eficiente(buble sort modificado) para mejor descriícón y entendimiento del problema, revisar el cap 7.7 de libro c++ for engineers and scientists \n";

}
