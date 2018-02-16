#include "employee.hpp"

using namespace std;

Employee::Employee(string firstName,
                   string name,
                   string pesel,
                   Sex sex,
                   string address,
                   int pay)
  : Person(firstName, name, pesel, sex, address)
  , pay(pay)
{
}

string
Employee::occupation()
{
  return employee;
}

int
Employee::number()
{
  return pay;
}