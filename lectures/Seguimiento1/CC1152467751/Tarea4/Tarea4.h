#include <iostream>

class Quadratic
{

private:
    float a, b, c, disc;

public:
    Quadratic();
    void getCoeff();
    void setA(float);
    void setB(float);
    void setC(float);
    void setDisc();
    void typeSol();
    void solQuad();
};