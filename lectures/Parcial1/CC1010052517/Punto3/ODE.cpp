#include "DiffEq.h"
#include <iostream>

using namespace std;

RK4::RK4(float (*function)(float, float), float a, float b, float y0, int number){
    
    n = number;
    h = (b-a)/n;
    t = a;
    y = y0;

    solve(function);
}

float RK4::solve(float (*function)(float, float)){
    for(int i = 0; i < n; i++){
        k1 = h * function(t, y);
        k2 = h * function(t + h/2, y + k1/2);
        k3 = h * function(t + h/2, y + k2/2);
        k4 = h * function(t + h, y + k3);
        
        // Para imprimir cada una de las iteraciones
        //cout << t << " " << y << endl;

        y = y + (k1 + 2*k2 + 2*k3 + k4)/6;
        t = t + h;

    }

    solution = y;
    return solution;
}


EulerMod::EulerMod(float (*function)(float, float), float a, float b, float y0, int number){
    
    n = number;
    h = (b-a)/n;
    t = a;
    y = y0;

    solve(function);
}

float EulerMod::solve(float (*function)(float, float)){
    for(int i = 0; i < n; i++){
        
        // Para imprimir cada una de las iteraciones
        //cout << t << " " << y << endl;

        y = y + h/2 * (function(t, y) + function(t + h, y + h * function(t, y)));
        t = t + h;

    }

    solution = y;
    return solution;
}
