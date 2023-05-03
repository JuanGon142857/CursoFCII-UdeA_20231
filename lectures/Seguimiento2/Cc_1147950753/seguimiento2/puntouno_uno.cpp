'''''
1) En el "ordenamiento de burbuja", los valores más pequeños van “subiendo como burbujas” gradualmente,
hasta llegar a la parte superior del arreglo (es decir, hacia el primer elemento) como las burbujas de aire que se elevan en el agua,
mientras que los valores más grandes se hunden en el fondo. Esta técnica realiza varias pasadas a través del arreglo.
En cada pasada compara pares sucesivos de elementos. Si un par se encuentra en orden ascendente (o los valores son idénticos),
el ordenamiento de burbuja deja los valores como están. Si un par se encuentra en orden descendente,
el ordenamiento de burbuja intercambia sus valores en el arreglo. Escriba una función que ordene el arreglo de 10 enteros mediante el
uso del ordenamiento de burbuja.
'''
#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

int LL[10]; // defin array de 10 elementos

int main(){

    int num;  
    int limite_superior = 100;
    int limite_inferior = 1;
    int d;
    srand(time(NULL));  // semilla

    

    for(int i = 0; i<10; i++){
        num = limite_inferior + rand()%(limite_superior + 1 - limite_inferior);
        LL[i] = num;
        

    }

    for(int i = 0; i<10; i++){
        cout<<"LL["<<i<<"]"<<" = "<<LL[i]<<endl;
        

    }

     

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(LL[j] > LL[j+1]){
                d = LL[j],
                LL[j] = LL[j+1];
                LL[j+1] = d;


            }
        }
    }

    for(int i=0;i<10;i++){
        cout<<LL[i]<<" ";

    }




    return 0;

}
