#ifndef ESPIRAL_H
#define ESPIRAL_H

#include "circular.h"
#include<string>

using namespace std;

class espiral : public circular{
    public:
    espiral(float,float,float,float,float,float,float);
    ~espiral();

    void set_zinicial(float);
    float get_zinicial() const;

    void set_zvelocidad(float);
    float get_zvelocidad() const;

    float posz(float) const;

    void imprimir() const;

    private:

    float z0; // Valor inicial de z.
    float vz; // Velocidad en z.

};
#endif