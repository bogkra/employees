#ifndef employee_hpp
#define employee_hpp
#include "person.hpp"
#include <string>

using namespace std;

class Employee : public Person {
public:
  Employee(string firstName,
           string name,
           string pesel,
           Sex sex,
           string address,
           int pay);
private:
  int pay;
  const string employee = "Employee";
  int number();
  string occupation();
};

#endif
