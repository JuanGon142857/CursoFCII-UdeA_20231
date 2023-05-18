#ifndef CIRCULAR_H
#define CIRCULAR_H

#include <vector>

class circular{
    public:
        circular(float, float, float, float, float);
        ~circular();

        void set_radio(float);
        float get_radio() const;

        void set_freq(float);
        float get_freq() const;

        // Time interval
        void set_dt(float);
        float get_dt() const;

        // Total time
        void set_T(float);
        float get_T() const;

        // Interval number
        void set_N();
        int get_N() const;

        void set_phase(float);
        float get_phase() const;
    
        float xpos(float);
        float ypos(float);

        void xvec();
        void yvec();

        std::vector<float> get_xvec();
        std::vector<float> get_yvec();

        void imprimir();

    private:
        float radio;
        float freq;
        float dt;
        float T;
        int N;
        float phase;
        std::vector <float> x;
        std::vector <float> y;
};

#endif