#include <iostream>
#include <vector>

using namespace std;

class Circular
{
public:
    Circular(double, double, double, double, double);
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
    void setX();
    void getX() const;
    void setY();
    void getY() const;

    double xpos(double);
    double ypos(double);

    void EscribirDocumento();

private:
    double radio;
    double frecuencia;
    double delta_t;
    double tiempo_total;
    int N;
    double fase;
    vector<double> *t;
    vector<double> *x;
    vector<double> *y;
};

class Espiral : public Circular
{
public:
private:
    double z_inicial;
    double velocidad_z;
    vector<double> zpos;
};