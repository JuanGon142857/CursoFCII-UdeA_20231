// Clase y herencia
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include "punto1.h"


using namespace std;

int main(){
    /*
    float re_X, re_Y,re_Z;
    Circular circulo1(10,2,0.3,2,100);
    Expiral expiral(10,2,0.3,2,100,3,1);
    re_X = circulo1.X_pos();
    re_Y = circulo1.Y_pos();
    re_Z = expiral.Z_pos();
     
    cout<<"Valor en X: "<<re_X<<endl;
    cout<<"Valor en Y: "<<re_Y<<endl;
    cout<<"Valor en z: "<<re_Z<<endl;
    */
    float re_X, re_Y,re_Z;
    cout<<'X'<<","<<'Y'<<", "<<'Z'<<endl;
    for(int i=0; i<100; i++){
        Circular circulo1(i,2,0.3,2,100);
        Expiral expiral(i,2,0.3,2,100,3,1);
        re_X = circulo1.X_pos();
        re_Y = circulo1.Y_pos();
        re_Z = expiral.Z_pos();
        cout<<re_X<<","<<re_Y<<", "<<re_Z<<endl;

    }
    
    
    return 0;
}
