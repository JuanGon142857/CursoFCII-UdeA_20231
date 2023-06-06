#ifndef ESPIRAL_H
#define ESPIRAL_H

#include "Circular.h"
#include <string>

class expiral : public circular{
    public:
        expiral(float, float, float, float, float, float , float);
        ~expiral();

        void set_vz(float);
        float get_vz() const;

        float zpos(float);

        void set_z0(float);
        float get_z0() const;

        void zvec();
        std::vector<float> get_zvec();

        void savedata(std::string);
        void graphdata();
        void imprimir();
    private:
        float vz;
        std::vector <float> z;
        float z0;
};

#endif