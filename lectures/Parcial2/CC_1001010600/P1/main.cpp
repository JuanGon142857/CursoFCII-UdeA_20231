//#include "circular.h"
#include "espiral.h"
#include <fstream>

int main(){

    //MOVIMIENTO CIRCULAR

    // circular movXY(1, 2, 3.1415*0.5, 0.05, 20); //double R, double w, double a, double dt, double t

    // vector<double> x = movXY.getXpos();
    // vector<double> y = movXY.getYpos();

    // ofstream posicionesXY("posicionesXY.csv");
    // if ( !posicionesXY ) 
    // {
    //   cerr << "No se pudo abrir el archivo" << endl;
    //   exit( 1 );
    // }

    // posicionesXY << "x, y" << endl;
    // for(int i = 0; i<x.size(); i++){
    //     posicionesXY << x.at(i) << "," << y.at(i) << endl;
    // }

    //MOVIMIENTO EN ESPIRAL

    espiral movXYZ(1, 0, 5, 2, 3.1415*0.5, 0.05, 20); //double R, double z0, double v, double w, double a, double dt, double t
    vector<double> X = movXYZ.getXpos();
    vector<double> Y = movXYZ.getYpos();
    vector<double> Z = movXYZ.getZpos();

    ofstream posicionesXYZ("posicionesXYZ.csv");
    if ( !posicionesXYZ ) 
    {
      cerr << "No se pudo abrir el archivo" << endl;
      exit( 1 );
    }

    posicionesXYZ << "x,y,z" << endl;
    for(int i = 0; i<Z.size(); i++){
        posicionesXYZ << X.at(i) << "," << Y.at(i) << "," << Z.at(i) << endl;
    }
    return 0;
}