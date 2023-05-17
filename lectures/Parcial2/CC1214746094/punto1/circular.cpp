#include<iostream>
#include<cmath>
#include<iomanip>
#include "circular.h"

using namespace std;

circular :: circular(float radio, float omega, float intervalo, float tiempototal, float fase){


set_radio(radio);
set_omega(omega);
set_intervalo(intervalo);
set_tiempototal(tiempototal);
set_fase(fase);
set_numintervalos();
    
}

circular :: ~circular(){
    cout << "Aqui esta el destructor de circular \n";
}

void circular :: set_radio(float r){
    radio = (r>0) ? r :0;
}

float circular:: get_radio() const{
    return radio;
}

void circular :: set_omega(float fr){
    omega = fr;
}

float circular :: get_omega() const{
    return omega;
}

void circular :: set_intervalo(float dt){
    intervalo = (dt>0) ? dt : 0.1;
}

float circular :: get_intervalo() const{
    return intervalo;
}

void circular :: set_tiempototal(float tt){
    tiempototal = (tt>0) ? tt :1;
}

float circular :: get_tiempototal() const{
    return tiempototal;
}

void circular :: set_numintervalos(){
    numintervalos = get_tiempototal()/get_intervalo();
}

float circular :: get_numintervalos() const{
    return numintervalos;
}

void circular :: set_fase(float phi){
    fase = phi;
}

float circular :: get_fase() const{
    return fase;
}

float circular :: xpos(float t) const{
    return (radio*cos(omega*t+fase));
}

float circular :: ypos(float t) const{
    return (radio*sin(omega*t+fase));
}

void circular :: imprimir() const{
    cout << setw(10) << fixed << "x" << setw(10) << fixed << "y \n"; 
    for(int j=0; j < get_numintervalos();j++){
        cout << setw(10) << fixed << xpos(j*get_intervalo()) << setw(10) << fixed << ypos(j*get_intervalo()) <<endl;
        
    }
    
}