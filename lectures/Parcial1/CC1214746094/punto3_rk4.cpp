#include <iostream>

using namespace std;

#define f(x,y) (y-(x*x)+1)



int main(){
    float x0,y0,y1,xf,k1,k2,k3,k4;
    int n;

    cout<<"Ingrese la condicion inicial para y0:"<<endl;
    cin >> y0;

    cout <<"Ingrese la condicion inicial para x0:"<<endl;
    cin >> x0;

    cout<<"Ingrese el valor superior de xf:"<<endl;
    cin >> xf;

    cout<<"Ingrese el valor del contador n:"<<endl;
    cin >> n;
    
    float h=(xf-x0)/n;
    cout<<h<<endl;

    for(int i=0;i<=n;i++){
        k1 = f(x0,y0);
        k2 = f((x0+h/2),(y0+h*(k1/2)));
        k3 = f((x0+h/2),(y0+h*(k2/2)));
        k4 = f((x0+h),(y0+h*k3));

        y1=y0 +((h/6)*(k1+2*k2+2*k3+k4));
        x0= x0+ h;

        cout <<"El valor de x es:"<< x0 <<"y el de y:"<< y1 <<endl;

        y0=y1;

    }

return 0;
}