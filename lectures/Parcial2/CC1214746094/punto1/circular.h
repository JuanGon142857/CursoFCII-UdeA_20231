#ifndef CIRC_H
#define CIRC_H

//#include<>

using namespace std;

class circular{
    public:
        circular(float,float,float,float,float); //constructor
        ~circular(); //destructor

        // funciones set y get para las variables:
        void set_radio(float);
        float get_radio() const;

        void set_omega(float);
        float get_omega() const;

        void set_intervalo(float);
        float get_intervalo() const;

        void set_tiempototal(float);
        float get_tiempototal() const;

        void set_numintervalos();
        float get_numintervalos() const;

        void set_fase(float);
        float get_fase() const;

        //coordenadas x e y:
        float xpos(float) const;
        float ypos(float) const;

        void imprimir() const;

        private:

        //variables:
        float radio; //radio
        float intervalo; //intervalo de tiempo
        float tiempototal; // tiempo total
        float numintervalos; // numero de intervalos
        float fase; //fase
        float omega; // frecuencia angular


        

};

#endif