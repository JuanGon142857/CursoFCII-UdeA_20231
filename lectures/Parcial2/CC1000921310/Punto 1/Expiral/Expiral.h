#ifndef EXPIRAL_H
#define EXPIRAL_H

#include "../Circular/Circular.h"

class Expiral : public Circular
{
    public:
        Expiral( float = 1, float = 1, float = 1, int = 5, float = 0, float = 0, float = 1); // constructor predeterminado
        ~Expiral();

        void Set_vz( float );
        float Get_vz() const;

        void Set_z0( float );
        float Get_z0() const;

        float zpos( float ) const;

        void Imprimir_coor() const;

    private:
        float vz;
        float z0;
};


#endif
