#include "punto3.h"


#include <iostream>
using namespace std;

int main(){

    int n = 4;
    std::vector<std::vector<float>> A = {{10,-1,2,0},{-1,11,-1,3},{2,-1,10,-1},{0,3,-1,8}};
    std::vector<float> b = {6,25,-11,15};
    float tol = 0.001;
    int max_iter = 100;

    Jacobi jacobi(n,A,b,tol,max_iter);
    std::vector<float> sol = jacobi.getSol();

    GaussSeidel gauss(n,A,b,tol,max_iter);
    std::vector<float> sol2 = gauss.getSol();



}