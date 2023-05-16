/*
Técnicas interactivas en álgebra matricial.
Proyecto asociado al parcial dos. Investigue en que consisten los metodos “Jacobi" y “Gauss-
Seidel". Cree un programa en c++ para resolver sistemas de ecuaciones lineales usando estos
métodos y compare los resultados. example:
10x 1 − x 2 + 2x 3 = 6
−x 1 + 11x 2 − x 3 + 3x 4 = 252x 1 − x 2 + 10x 3 − x 4 = −11
3x 2 − x 3 + 8x 4 = 15
*/

#pragma once
#include <vector>

class Jacobi
{
    public:

    Jacobi(int,std::vector<std::vector<float>>,std::vector<float>,float,int);
    ~Jacobi();

    int get_n();
    float get_tol();
    float get_max_iter();
    
    std::vector<float> get_b();
    std::vector<float> getSol();
    std::vector<std::vector<float>> get_A();
    

    private:

    int n;
    float tol;
    int max_iter;
    std::vector<float> b;
    std::vector<std::vector<float>> A;
    virtual std::vector<float> solve();
    
    protected:
    int iterador;
    void print_sol();
    std::vector<float> sol;
    
    
};

class GaussSeidel: public Jacobi
{
    public:

    GaussSeidel(int,std::vector<std::vector<float>>,std::vector<float>,float,int);
    ~GaussSeidel();
    
    private:

    std::vector<float> solve();

};

    