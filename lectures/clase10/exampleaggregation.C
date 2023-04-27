#include <iostream>

using namespace std;

class A
{
public:
  A(int& thing)
  :
   m_thing(thing)
  {
    // cuerpo vacío
    //m_thing = thing;
  }
  void printit() { cout << m_thing << endl; }
  
  //protected:
private:
  const int& m_thing; // Esto podria ser un objeto mas complejo
};


int main(int argc, char* argv[])
{
  int myint = 5;
  A myA(myint);
  myA.printit();
  return 0;
}
