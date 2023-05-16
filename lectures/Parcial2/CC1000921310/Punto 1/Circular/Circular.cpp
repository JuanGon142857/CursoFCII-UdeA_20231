#include <iostream>
#include <iomanip>
#include <cmath>

#include "Circular.h"

using namespace std;

Circular :: Circular(float R, float omega, float tf, int N, float alpha){
    Set_R( R );
    Set_omega( omega );
    Set_tf( tf );
    Set_N( N );
    Set_alpha( alpha );
}

Circular :: ~Circular(){
    cout << "Se destruye la instancia de la clase Circular \n"; 
}

void Circular :: Set_R( float r ){
    R =  (r > 0) ? r : 0;
}

void Circular :: Set_omega( float o ){
    omega = o;
}

void Circular :: Set_tf( float t_f ){
    tf = (t_f > 0) ? t_f : 0;
}

void Circular :: Set_N( int n ){
    N = (n >= 1) ? n : 1;
    dt = tf / N;    
    //El tamaño de los intervalos de tiempo se relaciona con el tiempo total el numero de intervalos a considerar
}

void Circular :: Set_alpha( float a ){
    alpha = a;
}

float Circular :: Get_R() const{
    return R;
}

float Circular :: Get_omega() const{
    return omega;
}

float Circular :: Get_tf() const{
    return tf;
}

float Circular :: Get_dt() const{
    return dt;
}

int Circular :: Get_N() const{
    return N;
}

float Circular :: Get_alpha() const{
    return alpha;
}

float Circular :: xpos(float t) const{
    return R * cos(omega * t + alpha);
}

float Circular :: ypos(float t) const{
    return R * sin(omega * t + alpha);
}

void Circular :: Imprimir_coor() const{
    cout << setw(8) << fixed << "x" << setw(12) << fixed << "y \n";
    for (int i = 1; i <= Get_N(); i++){
        cout << setw(10) << setprecision(4) << fixed << xpos(i * Get_dt()) << setw(10) << setprecision(4) << fixed << ypos(i * Get_dt()) << "\n"; 
    }
}