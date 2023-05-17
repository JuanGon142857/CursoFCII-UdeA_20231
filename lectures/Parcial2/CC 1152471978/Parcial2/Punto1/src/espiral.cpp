#include "../include/punto1.h"
#include <iostream>
#include <fstream>

using namespace std;

Expiral::Expiral(float R, float w, float dt, float t, float alpha, float z0, float vz)
: Circular(R, w, dt, t, alpha)

{
    this->z0 = z0;
    this->vz = vz;
    N=get_N();
    cout<<"Constructor Expiral"<<endl;
    zpos();
}

Expiral::~Expiral()
{
    cout<<"Destructor Expiral"<<endl;
}

vector<float> Expiral::zpos()

{   float dt=get_dt();

    for(int i = 0; i < N; i++)
    {
        z.push_back(z0 + vz*dt*i);
    }
    return z;
}

vector<float> Expiral::get_zpos(){return z;}

void Expiral::save_data(string filename)
{
    ofstream outfile;
    outfile.open(filename);
    outfile << "x" << " " << "y" << " " << "z" << endl;
    for (int i = 0; i < N; i++) {
        outfile << get_xpos()[i] << " " << get_ypos()[i] << " " << get_zpos()[i] << endl;
    }
    outfile.close();
}


    
