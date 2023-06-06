#include "Jacobi.h"
#include "Gauss.h"
#include <iostream>
#include <cmath>


using namespace std;

int main(){
	// El sistema de ecuaciones se introduce como una matriz y un vector. Ax = b
	// Es necesario un vector semilla.
	vector <vector <float>> A({{10,-1,2,0},
							   {-1,11,-1,3},
							   {2,-1,10,-1},
							   {0,3,-1,8}});
				   
	vector <float> B({6,25,-11,15});
	vector <float> S({0,0,0,0});
	
	vector <float> sol_exacta({1,2,-1,1});

	// SISTEMAS DE PRUEBAS

	// CONVERGE
	//vector <vector <float>> A({{3,1},{2,-1}});
	//vector <float> B({10,5});
	
	//vector <float> S({0,0});
	
	// DIVERGE
	//vector <vector <float>> A({{1,1},{1,-1}});
	//vector <float> B({3,-1});

	// Matriz, vector, semilla, tolerancia y número de iteraciones.
	Jacobi sistema(A, B, S, 1e-3);
	Gauss sistema2(A, B, S, 1e-3);

	vector <float> solucion = sistema.get_sol();
	sistema2.get_sol();


	cout << "\033[38;5;48m" << "Jacobi" << "\033[0m" << endl;
	sistema.info();
	cout << endl;

	cout << "El sistema ejecutó " << sistema.get_total_iterations() << " iteraciones." << endl;
	cout << "El error en la solución |x - x_exacto| respecto al valor exacto es";

	float error = 0;

	for(int i = 0; i < solucion.size(); i++){
      error += pow(sol_exacta.at(i) - sistema.get_sol().at(i) ,2);
    }

	cout << " " << sqrt(error) << endl << endl;

	cout << "\033[38;5;48m" << "Gauss-Seidel" << "\033[0m" << endl;

	sistema2.info();
	cout << endl;

	cout << "El sistema se resolvió en " << sistema2.get_total_iterations() << " iteraciones." << endl;
	cout << "El error en la solución |x - x_exacto| respecto al valor exacto es";

	error = 0;

	for(int i = 0; i < solucion.size(); i++){
      error += pow(sol_exacta.at(i) - sistema2.get_sol().at(i) ,2);
    }

	cout << " " << sqrt(error) << endl;

	cout << "Para este sistema de ecuaciones, el método de Gauss-Seidel converge más rápido que el método de Jacobi y da una mayor precisión.";

	return 0;
}
