#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void printArray(int *, int);
void bubbleSort(int *, int);
void improvedBubbleSort(int *, int);

int main(){
  srand(time(NULL));

  //Define the array
  const size_t arrayLength = 10;
  int arreglo[10] = {0,0,0,0,0,0,0,0,0,0};
  
  //Filling array
  for(int i=0; i<arrayLength; i++){
    arreglo[i] = 1+rand()%100;
  }

  cout << "\nArreglo original" << endl;
  printArray(arreglo, arrayLength);

  /*
  bubbleSort(arreglo, arrayLength);
  cout << "\nArreglo ordenado con bubbleSort" << endl;
  printArray(arreglo, arrayLength);
  */

  improvedBubbleSort(arreglo, arrayLength);
  cout << "\nArreglo ordenado con improvedBubbleSort" << endl;
  printArray(arreglo, arrayLength);

  return 0;
}

void printArray(int *array, int arrayLength){
  for(int i=0; i<arrayLength; i++){
    cout << array[i] << " ";
  }
  cout << endl;
}

void bubbleSort(int *array, const int arrayLength){
  for(int j=0; j<arrayLength; j++){
    for(int i=0; i<arrayLength-1; i++){
      //Comparation between elements
      if(array[i]>array[i+1]){
	int temp = array[i+1];
	array[i+1] = array[i];
	array[i] = temp;
      }
    }
  }
}
    
void improvedBubbleSort(int *array, const int arrayLength){
  int loopRed = 1; //Decreases loop iterations
  
  for(int j=10; j>1; j--){
    int changes = 0; //Detects changes between elements
    for(int i=0; i<arrayLength-loopRed; i++){
      //Comparation between elements
      if(array[i]>array[i+1]){
	int temp = array[i+1];
	array[i+1] = array[i];
	array[i] = temp;
	changes++;
      }
    }
    //If it does not detects any changes it breaks the loop because the array is sorted
    if(changes == 0){
      break;
    }
    else{
      loopRed++;
    }
  }
}
