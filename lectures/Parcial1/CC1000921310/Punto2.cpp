#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>

using namespace std;

class GenerarAleatorio {
public:
  GenerarAleatorio() {
    GenerateNumber();
    GuessNumber();
  }
  void GenerateNumber(){
    n = rand() % 1000 + 1;
    cout << endl << "Se ha generado un número secreto entre 1 y 1000" << endl;
    cout << "Trate de adivinar el número secreto " << endl;
  }
  
  void GuessNumber(){
    while (guess != n){
      cin >> guess; //Suposición del usuario
      
      if(guess < n){
        cout << "El número ingresado es MENOR al número secreto. Intente de nuevo" << endl;
      };
      
      if(guess > n){
        cout << "El número ingresado es MAYOR al número secreto. Intente de nuevo " << endl;
      };   
    };
    
    cout << "¡Felicitaciones!¡Ha acertado!"<< endl;
    cout << "Digite 1 para volver a jugar " << endl;
    cin >> repeat;
    if (repeat){ //Si el usuario quiere volver a jugar genera un nuevo número aleatorio y vuelve a iniciar el proceso
      GenerateNumber();
      GuessNumber();
        }
    else{
      cout << "Gracias por jugar" << endl;
      };
    }
  

  
private:
  unsigned int n;
  unsigned int guess;
  int repeat;
};

int main() {
  srand(time(NULL));
  GenerarAleatorio();

}
