#include "Gauss.h"
#include <cmath>
#include <iostream>

Gauss::Gauss(vector <vector<float>> _coeffs, vector <float> _vec, vector <float> _seed, float _tol, int nmax):Jacobi(_coeffs, _vec, _seed, _tol, nmax){
}

vector <float> Gauss::solve(){
  init_k();
  float precision = 1000;
  vector <float> sol = get_seed();

  while(get_total_iterations() < get_iterations() and precision > get_tol()){
    vector <float> prev_sol = sol;

      for (int i = 0; i < n_eqs; i++){

        float suma = 0;
        float suma2 = 0;

        for(int j = 0; j < i; j++){
            suma += get_coeffs().at(i).at(j) * sol.at(j);
        }

        for (int j = i+1; j < n_eqs; j++){
            suma2 += get_coeffs().at(i).at(j) * prev_sol.at(j);
        }

        sol.at(i) = 1 / get_coeffs().at(i).at(i) * (-suma - suma2 + get_vec().at(i));
    }

    float tmp = 0;
    float tmp_sol = 0;
    //cout << "Iteracion " << get_total_iterations() << ": ";
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
  if (precision < get_tol()) set_status(true);
  else{
    cout << "No se pudo resolver el sistema en " << get_iterations() << " iteraciones." << endl;
    set_status(false);}

  return sol;
}