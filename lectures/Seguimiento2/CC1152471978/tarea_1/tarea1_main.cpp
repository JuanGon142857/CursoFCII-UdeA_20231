#include "tarea1.h"
#include <vector>
#include <iostream>
using namespace std;


int main(){
    //ponemos la semilla
    srand(time(NULL));
    
    const int size = 10;
    vector <int> a;
    for(int i = 0; i < size; i++){
        a.push_back(rand() % 100 + 1);
        cout << a[i] << " ";
    }
    cout << endl;


    bubble_sort_basic(a, size);
    bubble_sort_optimized(a, size);

    return 0;
}




