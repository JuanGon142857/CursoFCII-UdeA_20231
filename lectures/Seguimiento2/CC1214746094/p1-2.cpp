#include <iostream>
#include <iomanip>
//#include <time.h>

using namespace std; 

void ordenamientoSeleccion( int [], const int, bool (*)( int, int ) );
void intercambiar( int * const, int * const );
bool ascendente( int, int ); // implementa el orden ascendente
bool descendente( int, int ); // implementa el orden descendente
int main()
{
    srand(time(NULL));
    const int size = 10;
    int orden;
    int contador;
    int a[size];
    bool romper=false;

    for(int i=0;i<size;i++){
        int num= 1 + rand() % (100+1-1);
        a[i]=num;}
  
  cout << "Escriba 1 para orden ascendente,\n"
       << "Escriba 2 para orden descendente: ";
  cin >> orden;
  cout << "\nElementos de datos en el orden original\n";

  // imprime el arreglo original
  for ( contador = 0; contador < size; contador++ )
    cout << setw( 4 ) << a[ contador ];

  // ordena el arreglo en forma ascendente; pasa la función ascendente
  // como un argumento para especificar el orden ascendente
  if ( orden == 1 )
    {
      ordenamientoSeleccion( a, size, ascendente );
      cout << "\nElementos de datos en orden ascendente\n";
    }
  
  // ordena el arreglo en forma descendente; pasa la función descendente
  // como argumento para especificar el orden en forma descendente
  else
    {
      ordenamientoSeleccion( a, size, descendente );
      cout << "\nElementos de datos en orden descendente\n";
    } 
  
  // imprime el arreglo ordenado
  for ( contador = 0; contador < size; contador++ )
    cout << setw( 4 ) << a[ contador ];
  
  cout << endl;
  return 0; // indica que terminó correctamente
} 

void ordenamientoSeleccion( int gg[], const int sizegg, bool (*compara)( int, int ) )
{
  for(int j=1;j<sizegg;j++){
    int numnointercambios=9;
        for(int k=0; k<sizegg-j;k++){
            if(!(*compara)(gg[k],gg[k+1]))
            intercambiar(& gg[k], & gg[k+1]);
            else{
                numnointercambios--;
            }
        }
    if(numnointercambios==0){
        //cout << "a" << endl;
        break;
    }
    }
}

void intercambiar( int * const elemento1Ptr, int * const elemento2Ptr )
{
  int contenido = *elemento1Ptr;
  *elemento1Ptr = *elemento2Ptr;
  *elemento2Ptr = contenido;
}

bool ascendente( int a, int b )
{
return a < b; // devuelve true si a es menor que b
}

bool descendente( int a, int b )
{
return a > b; 
}