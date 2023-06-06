#include "punto3.h"

#include <iostream>
using namespace std;

Jacobi::Jacobi(int n,std::vector<std::vector<float>> A,std::vector<float> b,float tol,int max_iter)
{
    this->n = n;
    this->A = A;
    this->b = b;
    this->tol = tol;
    this->max_iter = max_iter;
    this->sol ;
    this->iterador;
}

Jacobi::~Jacobi(){}


int Jacobi::get_n(){return this->n;}
float Jacobi::get_tol(){return this->tol;}
std::vector<float> Jacobi::get_b(){return this->b;}
float Jacobi::get_max_iter(){return this->max_iter;}
std::vector<std::vector<float>> Jacobi::get_A(){return this->A;}


std::vector<float> Jacobi::solve()
{
    cout<<"Jacobi solver"<<endl;
    //cout<<endl;

    std::vector<float> x(n,0);
    std::vector<float> x_new(n,0);

    float sum;
    int iter = 0;
    float error = tol + 1;

    while (error > tol && iter < max_iter)
    {
        for (int i = 0; i < n; i++)
        {
            sum = 0;
            for (int j = 0; j < n; j++)
            {if (j != i) sum += A.at(i).at(j) * x.at(j);}

            x_new.at(i) = (b.at(i) - sum) / A.at(i).at(i);
        }

        error = 0;
        for (int i = 0; i < n; i++)
        {error += abs(x_new.at(i) - x.at(i))/abs(x_new.at(i));}

        x = x_new;

        /*
        cout<<"step "<< iter <<" : "; 
        for (float i:x){cout<<i<<" ";}
        cout<<endl;
        */
    
        iter++;
    }
    iterador=iter;
    return x;
}

std::vector<float> Jacobi::getSol()
{
    sol=solve();
    print_sol();
    return this->sol;
}

void Jacobi::print_sol()
{
    cout << "Solucion aproximada:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "x" << i+1 << " = " << sol[i] << endl;
    }
    cout<<"Tolerancia : "<<tol<<endl;
    cout <<"Convergió en " << iterador << " pasos"<< endl;
    cout<<endl;
}