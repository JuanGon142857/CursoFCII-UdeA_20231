#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

void printVector(const vector<double> &vector)
{
    cout << "[";
    for (int i = 0; i < vector.size(); i++)
    {
        cout << vector.at(i) << " ";
    }
    cout << "]" << endl
         << endl;
}

double error(const vector<double> &vector1, const vector<double> *vector2)
{
    vector<double> diff;
    for (int i = 0; i < vector1.size(); i++)
    {
        diff.push_back(vector1.at(i) - vector2->at(i));
    }
    double num = sqrt(accumulate(diff.begin(), diff.end(), 0.0, [](double acc, double x)
                                 { return acc + x * x; }));
    double den = sqrt(accumulate(vector1.begin(), vector1.end(), 0.0, [](double acc, double x)
                                 { return acc + x * x; }));
    return num / den;
}

void Jacobi(const vector<vector<double>> &matrix, vector<double> &vector_b, vector<double> &approx, double TOL, int N_max)
{
    int n = matrix.size();
    int k = 1;
    while (k <= N_max)
    {
        vector<double> *copy_vector = new vector<double>(approx);
        for (int i = 0; i < n; i++)
        {
            double suma = 0;
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {
                    continue;
                }
                else
                {
                    suma += -matrix.at(i).at(j) * copy_vector->at(j);
                }
            }
            approx.at(i) = (suma + vector_b.at(i)) / matrix.at(i).at(i);
        }
        if (error(approx, copy_vector) < TOL)
        {
            delete copy_vector;
            copy_vector = 0;
            break;
        }
        k++;
    }
};

void Gauss_Seidel(const vector<vector<double>> &matrix, vector<double> &vector_b, vector<double> &approx, double TOL, int N_max)
{
    int n = matrix.size();
    int k = 1;
    while (k <= N_max)
    {
        vector<double> *copy_vector = new vector<double>(approx);
        for (int i = 0; i < n; i++)
        {
            double suma = 0;
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {
                    continue;
                }
                else if (j < i)
                {
                    suma += -matrix.at(i).at(j) * approx.at(j);
                }
                else if (j > i)
                {
                    suma += -matrix.at(i).at(j) * copy_vector->at(j);
                }
            }
            approx.at(i) = (suma + vector_b.at(i)) / matrix.at(i).at(i);
        }
        if (error(approx, copy_vector) < TOL)
        {
            delete copy_vector;
            copy_vector = 0;
            break;
        }
        k++;
    }
};

int main()
{
    vector<vector<double>> matrix = {{10, -1, 2, 0}, {-1, 11, -1, 3}, {2, -1, 10, -1}, {0, 3, -1, 8}};
    vector<double> b = {6, 25, -11, 15};
    vector<double> approx_jacobi = {0, 0, 0, 0};
    vector<double> approx_seidel = {0, 0, 0, 0};
    Jacobi(matrix, b, approx_jacobi, 0.0001, 500);
    cout << "Solución con el método de Jacobi: " << endl;
    printVector(approx_jacobi);
    Gauss_Seidel(matrix, b, approx_seidel, 0.0001, 500);
    cout << "Solución con el método de Seidel: " << endl;
    printVector(approx_seidel);
}