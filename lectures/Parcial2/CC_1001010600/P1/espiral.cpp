#include "espiral.h"

espiral::espiral(double R, double z0, double v, double w, double a, double dt, double t)
:circular(R, w, a, dt, t){
    this->z0 = z0;
    this->v = v;
    this->t = t;
    this->dt = dt;
}

espiral::~espiral(){
    cout << "DESTRUCTOR LLAMADO" << endl;
}

vector<double> espiral::getXpos()
{
    vector<double> X = circular::getXpos();
    return X;
}

vector<double> espiral::getYpos()
{
    vector<double> Y = circular::getYpos();
    return Y;
}

vector<double> espiral::getZpos()
{
    double tt = 0;
    while(tt < t){
        z.push_back(z0 + v*tt);
        tt += dt;
    }
    return z;
}
