/*
An assert is a statement in C++ which tests for a condition. 
If the condition is true, the program continues normally 
and if the condition is false, the program is terminated and an error message is displayed.
*/

#include <iostream>
#include <iostream>
// uncomment to disable assert()
//#define NDEBUG
#include <cassert>  
using namespace std;

void display_number(int* myInt) {
  assert (myInt!=NULL);
  cout<<"myInt contains value" << " = "<<*myInt<<endl;
}

int main ()
{
  
  int myint=5;
  int * second_ptr = NULL;
  int * third_ptr = NULL;
  //int * third_ptr = nullptr;
  second_ptr=&myint;
  display_number (second_ptr);
  display_number (third_ptr);
  
  
  // CHEKING NDEBUG
  /*
  assert(2+2==3+1);
  cout << "Expression valid...Execution continues.\n";
  assert(2+2==1+1);
  cout << "Asset disabled...execution continuous with invalid expression\n";
  */

  //static_assert  performs compile-time assertion checking
  //static_assert (bool_constexpr, message)
  /*
  assert(2+2==3+1);
  static_assert(2+2==3+1, "2+2 = 3+1");
  cout << "Expression valid...Execution continues.\n";
  assert(2+2==1+1);
  static_assert(2+2==1+1, "2+2 != 1+1");
  cout << "Assert disabled...execution continuous with invalid expression\n";
  */
  return 0;
}
