#include "tarea1.h"
#include <vector>
#include <iostream>

using namespace std;

void bubble_sort_basic(vector <int> a, const int size){
  for (int j = 0; j < size; j++){
    for(int i = 0; i < size-1; i++){
        if (a[i] > a[i+1]){
            int temp = a[i];
            a[i] = a[i+1];
            a[i+1] = temp;}
    }
  }
    //print the array
    for(int i = 0; i < a.size(); i++){
        cout << a[i] << " ";
            }
    cout << endl;
          }

  void bubble_sort_optimized(vector<int> a, int size){

    while (size>1)
    {
     bool bol = true;
      for(int i = 0; i < size; i++){
        if (a[i] > a[i+1]){
          int temp = a[i];
          bol = false;
          a[i] = a[i+1];
          a[i+1] = temp;}
      
      }
      if (bol == true){
        break;
      }
      size--;
    }
    //print the array
  
    for(int i = 0; i < a.size(); i++){
      cout << a[i] << " ";
    }
  cout << endl;
  }
