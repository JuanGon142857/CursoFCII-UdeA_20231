
#include <iostream>
#include <sstream>
#include "Employee.h" 
#include "Date.h" 
using namespace std;

// constructor uses member initializer list to pass initializer 
// values to constructors of member objects 
Employee::Employee(const string& first, const string& last,
   const Date &dateOfBirth, const Date &dateOfHire)
   : firstName{first},       
   lastName{last},          
   birthDate{dateOfBirth}, 
   hireDate{dateOfHire} {    
   // output Employee object to show when constructor is called
   cout << "Employee object constructor: "
      << firstName << ' ' << lastName << endl;
}

// print Employee object
string Employee::toString() const {
   ostringstream output;
   output << lastName << ", " << firstName << "  Hired: "
      << hireDate.toString() << "  Birthday: " << birthDate.toString();
   return output.str();
}

// output Employee object to show when its destructor is called
Employee::~Employee() {
   cout << "Employee object destructor: "
      << lastName << ", " << firstName << endl;
} 

