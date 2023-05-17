#include <iostream>
#include <vector>

using namespace std;

class Circular
{
public:
    Circular(const double, const double, const double, const double, const double);
    ~Circular();

    void setRadio(double);
    double getRadio() const;

    void setFrecuencia(double);
    double getFrecuencia() const;

    void setDelta_t(double);
    double getDelta_t() const;

    void setTiempo(double);
    double getTiempo() const;

    void setN();
    int getN() const;

    void setFase(double);
    double getFase() const;

    void setT();
    double getT(int) const;
    void printT() const;
    void setX();
    double getX(int) const;
    void printX() const;
    void setY();
    double getY(int) const;
    void printY() const;

    double xpos(double);
    double ypos(double);

    void EscribirDocumento();

private:
    double radioCircular;
    double frecuenciaCircular;
    double delta_tCircular;
    double tiempo_totalCircular;
    int NCircular;
    double faseCircular;
    vector<double> *t;
    vector<double> *x;
    vector<double> *y;
};
