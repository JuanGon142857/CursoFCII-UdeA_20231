#include <iostream>

using namespace std;

void ProcessData() {
  throw new string("Oops, I found some bad data!");
}

int main() {
  try {
    ProcessData();
    cout << "No problems!" << endl;
  }
  catch (string *excep) {
    cout << "Found an error. Here's the message.";
    cout << endl;
    cout << *excep;
    cout << endl;
  }
  cout << "All finished." << endl;

  //string *mystrptr = new string;
  //*mystrptr = "my new string";
  //cout << *mystrptr << endl;
  
  //string *mystrptr = new string("my new string");
  //cout << *mystrptr << endl;
  
  return 0;
}
