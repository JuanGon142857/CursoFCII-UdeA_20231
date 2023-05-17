#include<iostream>
#include<cmath>
#include<string>
#include<iomanip>

#include "espiral.h"

using namespace std;

espiral :: espiral(float radio, float omega, float intervalo, float tiempototal, float fase, float z, float v):circular(radio,omega,intervalo,tiempototal,fase){
    z0=z;
    vz=v;
}

espiral :: ~espiral(){
    cout << "Aqui está el destructor de espiral \n";

}

void espiral :: set_zinicial(float z){
    z0=z;
}

float espiral:: get_zinicial() const{
    return z0;
}

void espiral:: set_zvelocidad(float vel){
    vz= vel;
}

float espiral::get_zvelocidad() const{
    return vz;
}

float espiral:: posz(float t) const{
    return (get_zinicial() + get_zvelocidad()*t);

}

void espiral:: imprimir() const{
    cout << setw(14) << fixed << "x" << setw(14) << fixed << "y" << setw(14) << fixed << "z \n"; 
    for(int k=0; k<get_numintervalos(); k++){
        cout << setw(14) << fixed << xpos(k*get_intervalo()) << setw(14) << fixed << ypos(k*get_intervalo()) << setw(14) << fixed << posz(k*get_intervalo())<<endl;
    }
}

