#include <iostream>
#include <iomanip>
#include <cmath>

#include "Expiral.h"

using namespace std;

Expiral :: Expiral(float R, float omega, float tf, int N, float alpha, float z0, float vz)
: Circular(R, omega, tf, N, alpha){
    Set_z0( z0 );
    Set_vz( vz );

}

Expiral :: ~Expiral(){
    std :: cout << "Se destruye la instancia de la clase Expiral \n";
}

void Expiral :: Set_vz( float v){
    vz = v;
}

float Expiral :: Get_vz() const{
    return vz;
}

void Expiral :: Set_z0( float z){
    z0 = z;
}

float Expiral :: Get_z0() const{
    return z0;
}

float Expiral :: zpos(float t) const{
    return z0 + vz * t;
}

void Expiral :: Imprimir_coor() const{
    cout << setw(8) << fixed << "x" << setw(10) << fixed << "y" << setw(12) << fixed << "z \n";
    for (int i = 1; i <= Get_N(); i++){
        cout << setw(10) << setprecision(4) << fixed << xpos(i * Get_dt()) << setw(10) << setprecision(4) << fixed << ypos(i *Get_dt()) << setw(10) << setprecision(4) << fixed << zpos(i *Get_dt()) << "\n"; 
    }
}