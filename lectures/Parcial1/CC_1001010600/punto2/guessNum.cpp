#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(){
  srand(time(NULL));
  unsigned int num = 1+rand()%1000, guess{0};
  
  cout << "JUEGO ADVINAR NUMERO" << endl;
  cout << "Ingrese un numero entre 1 y 1000: ";
  cin >> guess;

  while(true){
    if(guess == num){
      cout << "ADIVINASTE EL NUMERO" << endl;
      
      string SN{""}; //Variable para jugar nuevamente
      cout << "¿Desea jugar nuevamente S/N?: ";
      cin >> SN;
	if(SN == "S" || SN == "s"){
	  srand(time(NULL));
	  num = 1+rand()%10;
	  cout << endl << "Ingrese un numero entre 1 y 1000: ";
	  cin >> guess;
	}
	  else{
	    break; 
	  }
    }
	else if(guess > num){
	  cout << "El numero es menor" << endl;
	  cout << "Ingrese otro numero: ";
	  cin >> guess;
	}
	else{
	  cout << "El numero es mayor" << endl;
	  cout << "Ingrese otro numero: ";
	  cin >> guess;
	}
  }
    
      
  return 0;
}
