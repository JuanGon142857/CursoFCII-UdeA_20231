#pragma once
#include <vector>
#include <string>

using namespace std;

class Jacobi{
  public:
    Jacobi(vector <vector <float>>, vector <float>, vector <float>, float = 1e-3, int = 10000);

    vector <float> get_sol();
    vector <vector<float>> get_coeffs() const;
    vector <float> get_vec() const;
    vector <float> get_seed() const;
    float get_tol() const;
    int get_iterations() const;
    
    int get_total_iterations() const;
    bool get_status() const;
    void set_status(bool);

    void init_k();
    void update_k();

    void info() const;
    int n_eqs;

    
  private:

    vector <float> solution;
    void set_coeffs(vector <vector<float>>);
    void set_vec(vector <float>);
    void set_seed(vector <float>);
    void set_tol(float);
    void set_iterations(int);

    virtual vector <float> solve();
   
    vector<vector<float>> coeffs;
    vector <float> vec;
    vector <float> seed;
    
    string message;

    bool solved;
    float tol;
    int max_iterations;
    int k;

};
