#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <fstream>
#include "poisson.h"

using namespace std;

PoissonSolver :: PoissonSolver(double a, double b, double c, double d, int m, int n, double TOL, int N,function<double(double, double)> f, function<double(double, double)> g):
a(a), b(b), c(c), d(d), m(m), n(n), TOL(TOL), N(N), f(f),g(g) {
        
        h = (b - a) / n;
        k = (d - c) / m;
        lam = (h * h) / (k * k);
        mu = 2 * (1 + lam);

        x.resize(n + 1);
        y.resize(m + 1);
        w.resize(n + 1, vector<double>(m + 1, 0.0));

        for (int i = 1; i <= n-1; i++) {
            x[i] = a + i * h;
            for (int j = 1; j <= m-1; j++) {
                y[j] = c + j * k;
                w[i][j] = 0.0;
            }
        }
    }

//    double f(double x, double y) {
        // Definir la función f(x, y)
        // f(x, y) = x * exp(y)
 //       return x * exp(y);
   // }
    

   // double g(double x, double y) {
     //   if (x == 0.0 ) {
         // Borde izquierdo (x = 0.0)
     //       return 0.0; // u(0, y) = 0
       // } else if (x == 2.0) {
            // Borde derecho (x = 2.0)
         //   return 2.0 * exp(y); // u(2, y) = 2exp(y)
        // } else if (y == 0.0) {
            // Borde inferior (y = 0.0)
          //  return x; // u(x, 0) = x
        // } else if (y == 1.0 ) {
            // Borde superior (y = 1.0)
           // return exp(x); // u(x, 1) = ex
        // } else {
            // Puntos interiores
          //  return 0.0;
      //  }
    //}

    void PoissonSolver :: solve() {
        int l = 1;
        double norm;
        double z;

        while (l <= N) {
            z = (-h*h*f(x[1],y[m-1])+g(a,y[m-1])+lam*g(x[1],d)+lam*w[1][m-2]+w[2][m-1])/mu;
            norm = abs(z-w[1][m-1]);
            w[1][m-1]=z;

            for (int i = 2; i <= n-2; i++) {
                z = (-h * h * f(x[i], y[m-1]) + lam*g(x[i], d) + w[i - 1][m-1] + w[i + 1][m-1] + lam*w[i][m-2]) / mu;
                if (abs(w[i][m-1] - z) > norm) {
                        norm = abs(w[i][m-1] - z);
                    }
                w[i][m-1] = z;
                
            }

            z= (-h*h*f(x[n-1],y[m-1])+g(b,y[m-1])+lam*g(x[n-1],d)+w[n-2][m-1]+lam*w[n-1][m-2])/mu;
            if (abs(w[n-1][m-1]-z)>norm){
                norm=abs(w[n-1][m-1]-z);

            }
            
            w[n-1][m-1]=z;

            for(int j=m-2; j>=2;j--){
                z = (-h*h*f(x[1],y[j])+g(a,y[j])+lam*w[1][j+1]+lam*w[1][j-1]+w[2][j])/mu;
                if(abs(w[1][j]-z)>norm){
                    norm=abs(w[1][j]-z);
                }
                w[1][j]=z;

                for(int i=2; i<=n-2;i++){
                    z= (-h*h*f(x[i],y[j])+w[i-1][j]+lam*w[i][j+1]+w[i+1][j]+lam*w[i][j-1])/mu;
                    if(abs(w[i][j]-z)>norm){
                        norm=abs(w[i][j]-z);
                    }
                    w[i][j]=z;
                }
                z= (-h*h*f(x[n-1],y[j])+g(b,y[j])+w[n-2][j]+lam*w[n-1][j+1]+lam*w[n-1][j-1])/mu;
                if(abs(w[n-1][j]-z)>norm){
                    norm=abs(w[n-1][j]-z);

                }
                w[n-1][j]=z;

            }

            z= (-h*h*f(x[1],y[1])+g(a,y[1])+lam*g(x[1],c)+lam*w[1][2]+w[2][1])/mu;
            if(abs(w[1][1]-z)>norm){
                norm= w[1][1]-z;
            }

            w[1][1]=z;

            for(int i=2;i<=n-2;i++){
                z= (-h*h*f(x[i],y[1])+lam*g(x[i],c)+w[i-1][1]+lam*w[i][2]+w[i+1][1])/mu;
                if(abs(w[i][1]-z)>norm){
                    norm=abs(w[i][1]-z);

                }
                w[i][1]=z;
            }

            z= (-h*h*f(x[n-1],y[1])+g(b,y[1])+lam*g(x[n-1],c)+w[n-2][1]+lam*w[n-1][2])/mu;
            if(abs(w[n-1][1]-z)>norm){
                norm=abs(w[n-1][1]-z);
            }
            w[n-1][1]=z;





            if (norm < TOL) {
                cout << "Solution converged after " << l << " iterations." << endl;
                break;
            }

            l++;
        }

        if (l > N) {
            cout << "Solution did not converge." << endl;
        }
    }
/*
    void PoissonSolver :: printSolution() {
        cout << "w[i]" << setw(12) << "u(x,y)"<< setw(12) << "|w-u|" << endl;
        for (int i = 1; i <= n-1; i++) {
            for(int j=1; j<=m-1;j++){
                cout << setprecision(6) << w[i][j] << setw(12) << setprecision(6) << f(x[i],y[j])<<setw(12)<< setprecision(6) << abs(f(x[i],y[j])-w[i][j])<<endl;

            }
            
        }
    }*/

    void PoissonSolver :: guardarcvs(){
        ofstream file("data.csv");
        if (file.is_open()) {
            // Escribir los encabezados
            file << "x , y ,  w[i][j],  u(x,y), |w-u| \n";

            // Escribir los datos
            for (int i = 1; i <= n - 1; i++) {
                for (int j = 1; j <= m - 1; j++) {
                    file << x[i] <<","<< y[j] <<","<< w[i][j] << "," << ((x[i]-y[j])*(x[i]-y[j])) <<","<<abs(w[i][j]-((x[i]-y[j])*(x[i]-y[j])))<< "\n";
                }
            }

            file.close();
            cout << "Los datos se han guardado en el archivo data.csv." << endl;
        } else {
            cout << "No se pudo abrir el archivo data.csv." << endl;
        }
    

    }