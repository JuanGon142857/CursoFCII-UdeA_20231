#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

class circular{
    public:
        circular(double, double, double, double, double);
        ~circular();
        vector<double> getXpos();
        vector<double> getYpos();
    private:
        double R{0}; //Radio
        double w{0}; //Frecuencia angular
        double a{0}; //Desfase
        double dt{0}, t{0}; //Paso de tiempo y tiempo total

        //Vectores de posicion
        vector<double> x;
        vector<double> y;

};