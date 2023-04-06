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
    fillArray(nums);
    cout << "El arreglo queda inicializado como: " << endl;
    printArray(nums);
    bubbleSort(nums);
    cout << "Después del ordenamiento de burbuja, el arreglo ordenado es: " << endl;
    printArray(nums);

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
    for (int i = 0; i < array.size(); i++)
    {
        for (int j = 0; j < array.size() - 1; j++)
        {
            if (array.at(j) > array.at(j + 1))
            {
                swap(&array[j], &array[j + 1]);
            }
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