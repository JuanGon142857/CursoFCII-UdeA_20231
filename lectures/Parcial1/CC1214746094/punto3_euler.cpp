#include <iostream>
 using namespace std;

 float f(float x, float y);

 int main(){
    float x0,y0, xf, y,h;
    cout<<"Ingresa el valor de x0:"<<endl;
    cin >> x0;
    cout<<"ingrese el valor de y0:"<<endl;
    cin >> y0;
    cout<<"Ingrese el valor de xf:"<<endl;
    cin >> xf;
    cout<<"Ingrese el paso"<<endl;
    cin >> h;

    cout<<"X"<< "\t\t" << "Y" << "\t\t" << "f(x,y)" << "\n"<<endl;
    cout<<"---------------------------------------------------------------------------\n"<<endl;
    cout<< xf << "\t\t" << f(x0,y0) << "\t\t" << y0 << "\n"<<endl;
    xf=xf;  

    while(x0 <= (xf-h)){
        y=y0+(f(x0,y0)*h);

        cout<< x0 << "\t\t" << y0 << "\t\t" << f(x0,y0) << "\n" <<endl;
        y0=y;
        x0=x0+h;

    }
    cout<< x0 << "\t\t" <<y0 << "\t\t" << f(x0,y0) << "\n"<< endl;

    return 0;

 }

 float f(float x, float y){
    return y - (x*x)+1;
 }