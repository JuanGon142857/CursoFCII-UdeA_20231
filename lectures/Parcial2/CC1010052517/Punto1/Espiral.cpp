#include "Espiral.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <iterator>

expiral::expiral(float radio, float zin, float freq, float vel, float dt, float T, float phase) : circular(radio, freq, dt, T, phase){
    
    vz = vel;
    z0 = zin;
    z = std::vector<float>(expiral::get_N(), 0);
    zvec();
}

void expiral::imprimir(){
    std::cout << "Radio: " << get_radio() << std::endl;
    std::cout << "Frecuencia: " << get_freq() << std::endl;
    std::cout << "Velocidad en z: " << get_vz() << std::endl;
    std::cout << "Intervalo de tiempo: " << get_dt() << std::endl;
    std::cout << "Tiempo total: " << get_T() << std::endl;
    std::cout << "Fase: " << get_phase() << std::endl;
    std::cout << "Número de puntos: " << get_N() << std::endl;
}

expiral::~expiral(){
}

void expiral::set_vz(float velocidad){
    vz = velocidad;
}

float expiral::get_vz() const{
    return vz;
}

float expiral::zpos(float t){
    return z0 + vz*t;
}

void expiral::set_z0(float zin){
    z0 = zin;
}

float expiral::get_z0() const{
    return z0;
}

void expiral::zvec(){
    for(int i = 0; i < get_N(); i++){
        z.at(i) = zpos(i*get_dt());
    }
}

std::vector <float> expiral::get_zvec(){
    return z;
}

void expiral::savedata(std::string _path){
    std::ofstream outfile(_path);

    for(int i = 0; i < get_N(); i++){
        outfile << std::setprecision(6) << std::fixed << get_xvec().at(i) << ",";
        outfile << std::setprecision(6) << std::fixed << get_yvec().at(i) << ",";
        outfile << std::setprecision(6) << std::fixed << get_zvec().at(i) << std::endl;
    }
}

void expiral::graphdata(){
    savedata("./espiral.csv");
    std::string command = "python3 graph.py";
    system(command.c_str());
}