#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){

  // grupos del 03 al 08
  
  srand( time( NULL ) );
  
  for ( int tiro = 1; tiro <= 20; tiro++ ){
    cout << 1 + rand() % 7 << endl; 
  }
  

  
return 0; 
}
