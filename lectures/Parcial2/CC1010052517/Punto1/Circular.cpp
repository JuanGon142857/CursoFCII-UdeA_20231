#include <iostream>
#include <cmath>
#include "Circular.h"

constexpr double pi = 3.14159265358979323846;

circular::circular(float radio, float freq, float dt, float T, float phase){
    
    set_radio(radio);
    set_dt(dt);
    set_T(T);
    set_freq(freq);
    set_phase(phase);

    set_N();

    x = std::vector<float>(N, 0);
    y = std::vector<float>(N, 0);

    xvec();
    yvec();
}

void circular::imprimir(){
    std::cout << "Radio: " << get_radio() << std::endl;
    std::cout << "Frecuencia: " << get_freq() << std::endl;
    std::cout << "Intervalo de tiempo: " << get_dt() << std::endl;
    std::cout << "Tiempo total: " << get_T() << std::endl;
    std::cout << "Fase: " << get_phase() << std::endl;
    std::cout << "Número de puntos: " << get_N() << std::endl;
}

circular::~circular(){
}

void circular::set_radio(float r){
    radio = (r > 0) ? r : 0;
    if(radio == 0){
        std::cout << "El radio no puede ser negativo. Se asignó el valor 0." << std::endl;
    }
}

float circular::get_radio() const{
    return radio;
}

void circular::set_freq(float f){
    freq = 2 * pi * f;
}

float circular::get_freq() const{
    return freq;
}

void circular::set_dt(float difft){
    dt = (difft > 0) ? difft : 0.1;
    if(dt == 0){
        std::cout << "El intervalo de tiempo no puede ser negativo. Se asignó el valor 0.1." << std::endl;
    }
}

float circular::get_dt() const{
    return dt;
}

void circular::set_T(float Total){
    T = (Total > 0) ? Total : 1;
    if(T == 0){
        std::cout << "El tiempo total no puede ser negativo. Se asignó el valor 1." << std::endl;
    }
}

float circular::get_T() const{
    return T;
}

void circular::set_N(){
    N = get_T() / get_dt();
}

int circular::get_N() const{
    return N;
}

void circular::set_phase(float phi){
    phase = phi * pi / 180;
}

float circular::get_phase() const{
    return phase;
}

float circular::xpos(float t){
    return radio * std::cos(freq*t + phase);
}

float circular::ypos(float t){
    return radio * std::sin(freq*t + phase);
}

void circular::xvec(){
    for(int i = 0; i < N; i++){
        x.at(i) = xpos(i*dt);
    }
}

void circular::yvec(){
    for(int i = 0; i < N; i++){
        y.at(i) = ypos(i*dt);
    }
}

std::vector <float> circular::get_xvec(){
    return x;
}

std::vector <float> circular::get_yvec(){
    return y;
}