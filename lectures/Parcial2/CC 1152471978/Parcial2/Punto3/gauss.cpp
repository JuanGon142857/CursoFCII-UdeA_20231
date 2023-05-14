#include "punto3.h"

#include <iostream>
using namespace std;

GaussSeidel::GaussSeidel(int n, std::vector<std::vector<float>> A, std::vector<float> b, float tol, int max_iter):Jacobi(n,A,b,tol,max_iter){}

GaussSeidel::~GaussSeidel(){}

std::vector<float> GaussSeidel::solve()

{   cout<<"GaussSeidel solver "<<endl;
    //cout<<endl;


    std::vector<float> x(get_n(),0);
    std::vector<float> x_old(get_n(),0);

    float sum;
    int iter = 0;
    float error = get_tol() + 1;

    while (error > get_tol() && iter < get_max_iter())

    {  
        for (int i = 0; i < get_n(); i++)
        {
            sum = 0;
            for (int j = 0; j < i; j++)
            {sum += get_A().at(i).at(j) * x.at(j);}

            for (int j = i+1; j < get_n(); j++)
            {sum += get_A().at(i).at(j)* x_old.at(j);}


            x.at(i) = (get_b().at(i) - sum) /get_A().at(i).at(i);

        }

        /*
        cout<<"iter "<< iter <<" : "; 
        for (float i:x){cout<<i<<" ";}
        cout<<endl;
        */
        error = 0;

        for (int i = 0; i < get_n(); i++)
        {
            error += abs(x.at(i) - x_old.at(i))/abs(x.at(i));
        }

        x_old= x;
        iter++;

    }
    iterador = iter;
    return x;
}


