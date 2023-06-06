#include "poisson.h"
#include <cmath>

using namespace std;


int main() {
    //double x, y;
    double a = 0.0, b = 1.0, c = 0.0, d = 2.0; // Límites del dominio
    int m = 4, n = 4; // Número de puntos en cada dirección
    double TOL = 1e-10; // Tolerancia
    int N = 100; // Número máximo de iteraciones

    auto f = [](double x, double y) { return 4; };
    auto g = [](double x, double y) {
        if (x == 0.0 && y >= 0.0 && y <= 2.0) {
        return y*y;
    } else if (x == 1.0 && y >= 0.0 && y <= 2.0) {
        return (y-1.0)*(y-1.0);
    } else if (y == 0.0 && x >= 0.0 && x <= 1.0) {
        return x*x;
    } else if (y == 2.0 && x >= 0.0 && x <= 1.0) {
        return (x-2.0)*(x-2.0);
    } else {
        return 0.0;
    }
};

    PoissonSolver solver(a, b, c, d, m, n, TOL, N, f, g);
    solver.solve();
    //solver.printSolution();
    solver.guardarcvs();
    

    return 0;

    
}