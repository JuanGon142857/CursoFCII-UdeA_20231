#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <chrono>

using namespace std;

int Jacobi(vector<float> &, vector <vector <float>> &, vector <float> &, float = 1e-5);
int Gauss_Seidel(vector<float> &, vector <vector <float>> &, vector <float> &, float = 1e-5);

int main() {

    vector <vector <float>> A{
        {1, -2, 2, 0},
        {-1, 11, -1, 3},
        {2, -1, 10, -4},
        {0, 3, -1, 8}
    };

    vector <float> b{6, 25, -11, 15};
   
    vector <float> x {1, 1, 1, 1};

    vector <float> error (x.size());    
    
    cout << "Jacobi:" << endl;
    auto started = chrono::high_resolution_clock::now();
    int iter = Jacobi(x, A, b);
    auto finished = chrono::high_resolution_clock::now();



    cout << "El algoritmo alcanzo convergencia en " << iter << " iteraciones. \n";
    cout << "El tiempo de ejecución fue: " << chrono::duration_cast<std::chrono::nanoseconds>(finished-started).count() << "ns \n";
    cout << "El error en cada componente de la solucion obtenida para Ax = b es: \n[";
    for (int i = 0; i < x.size(); i++){
        float b_metodo = 0;
        for (int j = 0; j < x.size(); j++){
            b_metodo = b_metodo + A[i][j] * x[j];
        }
        cout << "\n" << setw(9) << setprecision(8) << fixed << abs(b_metodo - b[i]);
    }
    cout << "] \n \n";

    x =  {1, 1, 1, 1};
    cout << "Gauss-Seidel: \n";

    started = chrono::high_resolution_clock::now();
    iter = Gauss_Seidel(x, A, b);
    finished = chrono::high_resolution_clock::now();

    cout << "El algoritmo alcanzo convergencia en " << iter << " iteraciones. \n";
    cout << "El tiempo de ejecución fue: " << chrono::duration_cast<std::chrono::nanoseconds>(finished-started).count() << "ns \n";
    cout << "El error en cada componente de la solucion obtenida para Ax = b es: \n[";
    for (int i = 0; i < x.size(); i++){
        float b_metodo = 0;
        for (int j = 0; j < x.size(); j++){
            b_metodo = b_metodo + A[i][j] * x[j];
        }
        cout << "\n" << setw(9) << setprecision(8) << fixed <<  abs(b_metodo - b[i]);
    }
    cout << "] \n \n";

    cout << "Conclusion: El metodo de Gauss-Seidel requiere menos iteraciones, y por tanto menos tiempo de ejecucion para alcanzar un mismo nivel de precision respecto al algoritmo de Jacobi. \n";
}

int Jacobi(vector<float> &x, vector <vector <float>> &A, vector <float> &b, float TOL){

    vector<float> new_x (x.size());
    float Diferencia = 10;

    int k = 0;
    while(Diferencia > TOL){
        Diferencia = 0;
        
        for (int i = 0; i < x.size(); i++){
            float sigma = 0;
            for (int j = 0; j < x.size(); j++){
                if (j != i){
                    sigma = sigma + A[i][j] * x[j];
                }
            }
            new_x[i] = ((b[i] - sigma) / A[i][i]);
            Diferencia = Diferencia + pow(abs(new_x[i] - x[i]), 2);
        }
        
        Diferencia = sqrt(Diferencia);
        x = new_x;
        k = k + 1;
    }
    return k;
}

int Gauss_Seidel(vector<float> &x, vector <vector <float>> &A, vector <float> &b, float TOL){
    
    float Diferencia = 10;
    float temp;
    int k = 0;
    while(Diferencia > TOL){
        Diferencia = 0;

        for (int i = 0; i < x.size(); i++){
            float sigma = 0;
            for (int j = 0; j < x.size(); j++){
                if (j != i){
                    sigma = sigma + A[i][j] * x[j];
                }
            }
            temp = (b[i] - sigma) / A[i][i];
            Diferencia = Diferencia + pow(abs(temp - x[i]), 2);
            x[i] = temp;
        }
        Diferencia = sqrt(Diferencia);
        k = k + 1;
    }
    return k;
}