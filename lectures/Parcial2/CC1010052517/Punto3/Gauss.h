#pragma once
#include <vector>
#include "Jacobi.h"

using namespace std;

class Gauss : public Jacobi
{
  public:
    Gauss(vector <vector <float>>, vector <float>, vector <float>, float = 1e-3, int = 10000);

  private:
    vector <float> solve();
};
