#include <cmath>
#include <iostream>
using namespace std;

int main(){

    unsigned int n = 4; //numero de ecuaciones
    unsigned int N = 100; //Maximo numero de iteraciones
    int A[n][n] = {{10,-1,2,0}, {-1,11,-1,3}, {2,-1,10,-1}, {0,3,-1,8}};   //Matriz de entradas A
    int b[n] = {6, 25, -11, 15};      //Vector de entradas b
    double x[n] = {0, 0, 0, 0};   //Vector de soluciones x
    double XO[n] = {1, 1, 1, 1};  //Vector de aproximación inicial
    double tol{1e-6};   //Tolerancia

    unsigned int k = 1;
    while(k<=N){
        for(unsigned int i=0; i<n; i++){
            //Calculamos el valor de xi
            double sum1{0};
            for(unsigned int j=i+1; j<n; j++){
                if(j != i)
                sum1 += A[i][j] * XO[j];
                else
                    continue;
            }

            double sum2{0};
            for(unsigned int j=0; j<i; j++){
                if(j != i)
                sum2 += A[i][j] * XO[j];
                else
                    continue;
            }

            x[i] = (-sum2 -sum1 + b[i]) / (double) A[i][i];
        }

        //Comparamos la diferencia entre el valor de xi y el valor de la aporximación inicial
        unsigned int c = 0;
        for(unsigned int i = 0; i<n; i++){
            if(abs(x[i] - XO[i]) < tol)
                c++;
        }

        //Si la diferencia de los valores es menor a la tolerancia entonces ya está solucionado el sistema
        if(c==n){
                cout << "Soluciones" << endl;
                for(unsigned int i = 0; i<n; i++){
                    cout << "x" << i << " = " << x[i] << endl;
                }
                cout << "Numero de iteraciones " << k << endl;
                exit(0);
            }

        k++;

        for(unsigned int i = 0; i<n; i++){
            XO[i] = x[i];
        }

    }

    cout << "Numero maximo de iteraciones" << endl;
    for(unsigned int i = 0; i<n; i++){
        cout << "x" << i << " = " << x[i] << endl;
    }
    

    return 0;
}