#include "circular.h"

circular::circular(double R, double w, double a, double dt, double t){
    this->R = R;
    this->w = w;
    this->a = a;
    this->dt = dt;
    this->t = t;
}

circular::~circular(){
    cout << "DESTRUCTOR LLAMADO" << endl;
}

vector<double> circular::getXpos(){
    double tt = 0;
    while(tt < t){
        x.push_back(R*cos(w*tt + a));
        tt += dt;
    }
    return x;
}

vector<double> circular::getYpos(){
    double tt = 0;
    while(tt < t){
        y.push_back(R*sin(w*tt + a));
        tt += dt;
    }
    return y;
}
