// Método de Jacobi

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void imprimirSistema(vector<vector<double>> A, vector<double> b);
//función del métdo de Jacobi
vector<double> jacobi(vector<vector<double>> A, vector<double> b, double tol, int maxiter);
//función del métdo de Gauss-siedel
vector<double> gaussSeidel(vector<vector<double>> A, vector<double> b, double tol, int maxiter);


int main() {
    
    cout<<"matriz de coeficientes y vector de términos independientes"<<endl;
    vector<vector<double>> A {{10,-1,2,0}, {-1,11,-1,3}, {2,-1,10,-1},{0,3,-1,-8}};
    vector<double> b {6,25,-11,15};

    // imprimo sistema de ecuaciones
    cout<<"imprimo sistema de ecuaciones"<<endl;
    imprimirSistema(A, b);
    
     cout<<" "<<endl;
    cout<<"------------------------------------------------------------"<<endl;
    cout<<" "<<endl;

    // solucion de las ecuaciones con Jacobi
    cout << "Solución método de Jacobi:" << endl;
    vector<double> x = jacobi(A, b, 1e-6, 100);
 
    cout<<"X = ["<<x[0]<<","<<x[1]<<","<<x[2]<<","<<x[3]<<"]"<<endl;

     cout<<" "<<endl;
    cout<<"------------------------------------------------------------"<<endl;
    cout<<" "<<endl;

    // Resolución del sistema de ecuaciones con el método de Gauss-Seidel
    cout << "Solución método de Gauss.siedel:" << endl;
    
    vector<double> x2 = gaussSeidel(A, b, 1e-6, 100);
   
    cout<<"X = ["<<x2[0]<<","<<x2[1]<<","<<x2[2]<<","<<x2[3]<<"]"<<endl;

    
    

    return 0;
}

// Función para calcular la norma euclidiana de un vector
double norm(vector<double> v) {
    double suma = 0.0;
    for (double x : v) {
        suma += x * x;
    }
    return sqrt(suma);
}

// imprimo  matriz y el vector de términos independientes
void imprimirSistema(vector<vector<double>> A, vector<double> b) {
    int n = A.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << "\t";
        }
        cout << "| " << b[i] << endl;
    }
    cout << endl;
}

// aplicacion del método de Jacobi
vector<double> jacobi(vector<vector<double>> A, vector<double> b, double tol, int maxiter) {
    int n = A.size();
    vector<double> x(n, 0.0);
    vector<double> x_new(n, 0.0);
    int iter = 0;
    double error = tol + 1.0;

    // itero hasta alcanzar error 
    while (error > tol && iter < maxiter) {
        // Calcular la nueva aproximación de la solución
        for (int i = 0; i < n; i++) {
            double suma = 0.0;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    suma += A[i][j] * x[j];
                }
            }
            x_new[i] = (b[i] - suma) / A[i][i];
        }

        // Calculo el error relativo
        error = norm(x_new) / norm(x) - 1.0;
        x = x_new;
        iter++;
    }

    // Imprimir el número de iteraciones y el error relativo final
    cout << "Número de iteraciones: " << iter << endl;
    cout << "Error relativo: " << error << endl;

    return x;
}


// aplicación  método de Gauss-Seidel
vector<double> gaussSeidel(vector<vector<double>> A, vector<double> b, double tol, int maxiter) {
    int n = A.size();
    vector<double> x(n, 0.0);
    int iter = 0;
    double error = tol + 1.0;

    // Iterar hasta que se alcance el número máximo de iteraciones o el error sea menor que la tolerancia
    while (error > tol && iter < maxiter) {
        // Calcular la nueva aproximación de la solución
        for (int i = 0; i < n; i++) {
            double suma = 0.0;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    suma += A[i][j] * x[j];
                }
            }
            x[i] = (b[i] - suma) / A[i][i];
        }

        // Calcular el error relativo
        error = norm(x) / norm(vector<double>(n, 1.0)) - 1.0;
        iter++;
    }

    // Imprimir el número de iteraciones y el error relativo final
    cout << "Número de iteraciones: " << iter << endl;
    cout << "Error relativo: " << error << endl;

    return x;
}