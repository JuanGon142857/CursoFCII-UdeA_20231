// Clase y herencia
#include<iostream>
#include<stdlib.h>
using std::string;

using namespace std;

    

    
// Clase Circular--------------------------------------------------------------
class Circular{
    private:
     float dt,R,alpha,w;
     int N,t;

    public:
        Circular(int,float,float,float,int); // constructor de la clase circular
        float X_pos();
        float Y_pos();
};


// Clase Expiral-------------------------------------------------------------
class Expiral : public Circular{
    private:
        float zo, vel_z;
        int t;
    public:
        Expiral(int,float,float,float,int,float,float); // Constructor de la clase Expiral
        float Z_pos();

};