#include "Jacobi.h"
#include <cmath>
#include <iostream>

Jacobi::Jacobi(vector <vector<float>> _coeffs, vector <float> _vec, vector <float> _seed, float _tol, int nmax){
  
  set_coeffs(_coeffs);
  set_vec(_vec);
  set_seed(_seed);
  set_tol(_tol);
  set_iterations(nmax);
  solution = _seed;

  n_eqs = vec.size();
  solved = false;
}

// Ejecuta el método de Jacobi
vector <float> Jacobi::solve(){
  init_k();
  vector <float> sol = get_seed();
  float precision = 1000;

  while(k < max_iterations and precision > tol){
    vector <float> prev_sol = sol;

      for (int i = 0; i < n_eqs; i++){

      float suma = 0;
      for(int j = 0; j < n_eqs; j++){
        if(i!=j){
          suma += coeffs.at(i).at(j) * prev_sol.at(j);
        }
      }

      sol.at(i) = 1 / coeffs.at(i).at(i) * (-suma + vec.at(i));
    }

    if (sol == seed){
      cout << "El sistema no converge." << endl;
      set_status(false);
      break;
    }

    float tmp = 0;
    float tmp_sol = 0;
    //cout << "Iteracion " << k << ": ";
    for(int i = 0; i < n_eqs; i++){
      //cout << solution.at(i) << " ";
      tmp += pow(prev_sol.at(i) - sol.at(i) ,2);
      tmp_sol += pow(sol.at(i) ,2);
    }
    //cout << endl;
  precision = sqrt(tmp) / sqrt(tmp_sol);	
  update_k();
  prev_sol = sol;
  }
  if (precision < tol)  set_status(true);
  else {cout << "No se pudo resolver el sistema." << endl;
        set_status(false);}
  return sol;
}


// Setters. Solo para uso interno en el construstor.
void Jacobi::set_coeffs(vector <vector<float>> _coeffs){
  coeffs = _coeffs;
}

void Jacobi::set_vec(vector <float> _vec){
  vec = _vec;
}

// Seed se declara para mostrarlo al final
void Jacobi::set_seed(vector <float> _seed){
  seed = _seed;
}

void Jacobi::set_tol(float _tol){
  tol = _tol;
}

void Jacobi::set_iterations(int nmax){
  max_iterations = nmax;
}

// Devuelve la solución. Si el sistema ya fue resuelto, no lo resuelve de nuevo.
vector <float> Jacobi::get_sol(){
  if(solved){
    return solution;
  }
  else{
    solution = solve();
    if(solved){
      message = "Sistema resuelto con exito.";
    }
    else{
      message = "No se pudo resolver el sistema en el número de iteraciones indicado.";
    }
    return solution;
  }
}
vector <vector<float>> Jacobi::get_coeffs() const{
  return coeffs;
}

vector <float> Jacobi::get_vec() const{
  return vec;
}

vector <float> Jacobi::get_seed() const{
  return seed;
}

float Jacobi::get_tol() const{
  return tol;
}

int Jacobi::get_iterations() const{
  return max_iterations;
}

void Jacobi::init_k(){
  k = 0;
}

void Jacobi::update_k(){
  k++;
}

int Jacobi::get_total_iterations() const{
  return k;
}

void Jacobi::set_status(bool _solved){
  solved = _solved;
}

void Jacobi::info() const{
  cout << "Solved: " << boolalpha << solved << endl;
  cout << "Seed: ";
  for(float s:get_seed()){
    cout << s << " ";
  }
  cout << endl;
  cout << "Tolerance: " << get_tol() << endl;
  cout << "Max iterations: " << get_iterations() << endl;
  cout << "Executed Iterations: " << get_total_iterations() << endl;
  cout << "Solution: ";
  for(float s:solution){
    cout << s << " ";
  }
  cout << endl;

}
