#include <iostream>
#include "person.hpp"
using namespace std;


Person::Person(string firstName,
               string name,
               string pesel,
               Sex sex,
               string address)
  : firstName(firstName),
    name(name),
    pesel(pesel),
    sex(sex),
    address(address)
{
}

bool
Person::validatePESEL()
{
  bool result = true;

  // dodac wyjatki!
  int p[11];
  for (int i = 0; i < 11; i++) {
    result = (result && isdigit(pesel[i]));
    p[i] = pesel[i] - '0';
  }

  return result && (((9*p[0] + 7*p[1] + 3*p[2] + 1*p[3] + 9*p[4] + 7*p[5] + 3*p[6] + 1*p[7] + 9*p[8] + 7*p[9])   %  10 ==  p[10]) 
             &&  (p[9] % 2 == (sex == male ? 1 : 0)));

  // warning: possible more precise validations - day of month, month, date in
  // the future...
}

void 
Person::show()
{
    cout << occupation() << "  " << firstName << "  " << name  << "  " << pesel << "  " << ((sex)==male ? "male" : "female") << "  " << address
         << "  " << number() << endl;
}
