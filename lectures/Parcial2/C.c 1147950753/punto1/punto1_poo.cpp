// Clase y herencia
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include "punto1.h"

using namespace std;


// Constructor de la clase Circular
Circular::Circular(int _t_total, float _R, float _alpha, float _w, int _N){
    t = _t_total;
    //dt = _dt;
    R = _R;
    alpha = _alpha;
    w = _w;
    N = _N;
}

//Constructor case Expiral
Expiral::Expiral(int _t_total, float _R, float _alpha, float _w, int _N,float _zo,float _vel_z) : Circular(_t_total, _R, _alpha, _w, _N){
    t = _t_total;
    zo = _zo;
    vel_z = _vel_z*t;
}



// X_pos, me davuelve la posicion en X
float Circular::X_pos(){
    return R*cos(w*t + alpha);
    

}

// Y_pos, me davuelve la posicion en Y
float Circular::Y_pos(){
    return R*sin(w*t + alpha);

}

// Z_pos, me davuelve la posicion en Z
float Expiral::Z_pos(){
    return zo + vel_z;

}