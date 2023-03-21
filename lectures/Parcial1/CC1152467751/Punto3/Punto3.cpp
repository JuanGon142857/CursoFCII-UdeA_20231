#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double t, double y)
{
    return y - pow(t, 2) + 1;
}

double fReal(double t)
{
    return pow(t + 1, 2) - 0.5 * exp(t);
}

void modEuler(double a, double b, int N, double alpha, double t_arr[], double w_arr[])
{
    double h = (b - a) / N;
    double t = a;
    double w = alpha;
    t_arr[0] = t;
    w_arr[0] = w;

    for (int i = 1; i < N; i++)
    {
        t_arr[i] = a + i * h;
        w_arr[i] = w_arr[i - 1] +
                   (h / 2) * (f(t_arr[i - 1], w_arr[i - 1]) +
                              f(t_arr[i], w_arr[i - 1] + h * f(t_arr[i - 1], w_arr[i - 1])));
    }
}

void rungeKutta4(double a, double b, int N, double alpha, double t[], double w[])
{
    t[0] = a;
    w[0] = alpha;
    double k1, k2, k3, k4;
    double h = (b - a) / N;

    for (int i = 1; i < N; i++)
    {
        t[i] = a + i * h;
        k1 = h * f(t[i - 1], w[i - 1]);
        k2 = h * f(t[i - 1] + h / 2, w[i - 1] + k1 / 2);
        k3 = h * f(t[i - 1] + h / 2, w[i - 1] + k2 / 2);
        k4 = h * f(t[i], w[i - 1] + k3);
        w[i] = w[i - 1] + (1 / 6) * (k1 + 2 * k2 + 2 * k3 + k4);
    }
}

int main()
{
    int N = 10;
    double t_arr_eu[N + 1];
    double w_arr_eu[N + 1];
    double t_arr_run[N + 1];
    double w_arr_run[N + 1];
    double real[N + 1];

    modEuler(0, 2, N, 0.5, t_arr_eu, w_arr_eu);
    rungeKutta4(0, 2, N, 0.5, t_arr_run, w_arr_run);

    for (int i = 0; i < (N + 1); i++)
    {
        real[i] = fReal(t_arr_eu[i]);
    }

    cout << "|" << setw(10) << "Time"
         << "|" << setw(10) << "Método Euler Rectificado"
         << "|" << setw(10) << "Método Runge-Kutta 4"
         << "|" << setw(10) << "Valor real"
         << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "|" << setw(10) << fixed << setprecision(1) << t_arr_eu[i]
             << "|" << setw(24) << fixed << setprecision(2) << w_arr_eu[i]
             << "|" << setw(19) << fixed << setprecision(3) << w_arr_run[i]
             << "|" << setw(7) << fixed << setprecision(1) << real[i]
             << endl;
    }
}