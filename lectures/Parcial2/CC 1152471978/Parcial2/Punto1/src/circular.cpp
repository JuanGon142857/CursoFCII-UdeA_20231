#include "../include/punto1.h"
#include <vector>
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

Circular::Circular(float R, float w, float dt, float t, float alpha)
{
    this->R = R;
    this->w = w;
    this->dt = dt;
    this->t = t;
    N = t/dt;
    this->alpha = alpha;

    cout<<"Constructor Circular"<<endl;
    xpos();
    ypos();

}

Circular::~Circular()
{
    cout<<"Destructor Circular"<<endl;
}

vector<float> Circular::xpos()
{   cout<<N<<endl;
    for(int i = 0; i < N; i++)
    {
        x.push_back(R*cos(w*dt*i + alpha));
        
    }
    return x;
}

vector<float> Circular::ypos()
{
    for(int i = 0; i < N; i++)
    {
        y.push_back(R*sin(w*dt*i + alpha));
    }
    return y;
}

vector<float> Circular::get_xpos(){return x;}

vector<float> Circular::get_ypos(){return y;}

int Circular::get_N(){return N;}

float Circular::get_dt(){return dt;}


void Circular::save_data(string filename)
{
    ofstream outfile;
    outfile.open(filename);

    outfile << "x" << " " << "y" << endl;

    for(int i = 0; i < N; i++)
    {
        outfile << x[i] << " " << y[i] << endl;
    }
    outfile.close();
}
