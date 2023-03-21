#include "DiffEq.h"

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

float function(float t, float y){
    cout << setprecision(1) << t << " " << setprecision(5) << fixed << y << endl;
    return y - pow(t, 2) + 1;
}

int main(){

    cout << "\033[1;31mEuler Modificado\033[0m" << endl;
    EulerMod sol2(function, 0, 2, 0.5, 10);
    cout << "\033[1;31mRunge Kutta\033[0m" << endl;
    RK4 sol1(function, 0, 2, 0.5, 10);
    cout << "Solución final:\n";
    cout << setw(7) << left << "RK4: " << sol1.solution << endl;
    cout << "Euler: "<< sol2.solution << endl;

    return 0;
}