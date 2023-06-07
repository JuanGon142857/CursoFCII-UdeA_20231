#ifndef POISSON_H
#define POISSON_H
#include <vector>
#include<functional>

using namespace std;

class PoissonSolver {
private:
    double a, b, c, d;
    int m, n;
    double TOL;
    int N;
    double h, k;
    double lam, mu;

    vector<double> x;
    vector<double> y;
    vector<vector<double>> w;

    function<double(double, double)> f;
    function<double(double, double)> g;

public:
    PoissonSolver(double a, double b, double c, double d, int m, int n, double TOL, int N,function<double(double, double)> f, function<double(double, double)> g);
    void solve();
    //void printSolution();
    void guardarcvs();
};

#endif