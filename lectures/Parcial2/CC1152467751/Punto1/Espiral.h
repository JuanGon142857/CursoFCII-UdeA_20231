#include "Circular.h"
#include <vector>

class Espiral : public Circular
{
public:
    Espiral(const double, const double, const double, const double, const double, const double, const double);
    ~Espiral();

    void setZ_Inicial(double);
    double getZ_Inicial() const;

    void setVelocidad_z(double);
    double getVelocidad_z() const;

    double zpos(double);

    void setZ();
    double getZ(int) const;
    void printZ() const;

    void EscribirDocumento();

private:
    double z_inicialEspiral;
    double velocidad_zEspiral;
    vector<double> *z;
};