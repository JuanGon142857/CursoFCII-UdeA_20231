class RK4{
    public:
        RK4(float (*)(float, float), float, float, float, int);
        float solve(float (*)(float, float));
        float solution;
    private:
        float k1, k2, k3, k4;    
        int n;
        float h;
        float t;
        float y;
};

class EulerMod{
    public:
        EulerMod(float (*)(float, float), float, float, float, int);
        float solve(float (*)(float, float));
        float solution;
    private: 
        int n;
        float h;
        float t;
        float y;
};