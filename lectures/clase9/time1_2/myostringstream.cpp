/*
std::ws
Extracts as many whitespace characters as possible from the current position in the input sequence. 
The extraction stops as soon as a non-whitespace character is found. 
These extracted whitespace characters are discarded.
 */

#include <iostream>
#include <sstream>
#include <string>
using namespace std;
 
int main() {
  cout << "type an int, a float and a string: ";
  int i;
  float f;
  cin >> i >> f;
  cin >> ws; // Throw away white space
  string stuff;
  getline(cin, stuff); // Get rest of the line
  ostringstream os;
  os << "integer = " << i << endl;
  os << "float = " << f << endl;
  os << "string = " << stuff << endl;
  string result = os.str();
  cout << result << endl;
} 
