#include <iostream>
#include <cassert>
#include <sstream>
#include <string>
using namespace std;
 
int main() {
  string text = "We will hook no fish";
  stringstream ss(text);
  std::cout << ss.str() << std::endl;

  ss.seekp(0, ios::end);
  ss << " before its time.";
  assert(ss.str() == "We will hook no fish before its time.");
  std::cout << ss.str() << std::endl;

  // Change "hook" to "ship"
  ss.seekg(8, ios::beg);
  string word;
  ss >> word;
  assert(word == "hook");
  ss.seekp(8, ios::beg);
  ss << "ship";
  std::cout << ss.str() << std::endl;

  // Change "fish" to "code"
  ss.seekg(16, ios::beg);
  ss >> word;
  assert(word == "fish");
  ss.seekp(16, ios::beg);
  ss << "code";
  assert(ss.str() == "We will ship no code before its time.");
  std::cout << ss.str() << std::endl;

  ss.str("A horse of a different color.");
  std::cout << ss.str() << std::endl;

  assert(ss.str() == "A horse of a different color.");
  std::cout << ss.str() << std::endl;
}
 
