#include "circular.h"
class espiral: private circular{
    public:

        espiral(double R, double z0, double v, double w, double a, double dt, double t);
        ~espiral();
        vector<double> getXpos();
        vector<double> getYpos();
        vector<double> getZpos();

    private:
        vector<double> z;
        double z0{0};
        double v{0};
        double dt{0}, t{0};
};