#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <ctime>
#include <vector>
#include <iomanip>

using namespace std;

void fillArray(vector<int> &);
void swap(int *const, int *const);
void bubbleSort(vector<int> &);
void printArray(vector<int>);

int main()
{
    vector<int> nums(10, 0);
    vector<int> nums2 = {1, 3, 2, 4, 5, 6, 7, 8, 9, 10};
    vector<int> nums3 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    fillArray(nums);
    cout << "El arreglo 1, de número aleatorios queda inicializado como: " << endl;
    printArray(nums);
    bubbleSort(nums);
    cout << "Después del ordenamiento de burbuja, el arreglo ordenado es: " << endl;
    printArray(nums);
    cout << endl;
    cout << "El arreglo 2, que solo necesita un intercambio para ordenarse es: " << endl;
    printArray(nums2);
    bubbleSort(nums2);
    cout << "Después de aplicar el ordenamiento de burbuja: " << endl;
    printArray(nums2);
    cout << endl;
    cout << "El arreglo 3, que está completamente ordenado es: " << endl;
    printArray(nums3);
    bubbleSort(nums3);
    cout << "Después de aplicar el ordenamiento de burbuja: " << endl;
    printArray(nums3);

    return 0;
}

void fillArray(vector<int> &array)
{
    srand(time(NULL));
    for (int i = 0; i < array.size(); i++)
    {
        int num = 1 + rand() % (100 + 1 - 1);
        array.at(i) = num;
    }
}

void swap(int *const numero1, int *const numero2)
{
    int temporal = *numero1;
    *numero1 = *numero2;
    *numero2 = temporal;
}

void bubbleSort(vector<int> &array)
{

    unsigned int centinela = 0;
    for (unsigned int i = 0; i < array.size(); i++)
    {
        centinela = 0;
        unsigned int cont = 0;
        for (int j = 0; j < array.size() - 1 - i; j++)
        {
            if (array.at(j) > array.at(j + 1))
            {
                swap(&array[j], &array[j + 1]);
                centinela++;
            }
            cont++;
        }
        cout << "Para i=" << i << " se tienen " << cont << " iteraciones de j" << endl;
        if (centinela == 0)
        {
            cout << "El arreglo está completamente ordenado" << endl;
            break;
        }
    }
}

void printArray(vector<int> array)
{
    cout << "[";
    for (int i = 0; i < array.size(); i++)
    {
        cout << array.at(i) << setw(3);
    }
    cout << "]" << endl;
}