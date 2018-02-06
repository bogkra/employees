#ifndef main_h
#define main_h
#include <string>

using namespace std;

// typedef char Index[30];
// typedef long int Index;

/*union ExtraData {
    Index index;
    float pay;
  };
*/
enum Sex
{
  female,
  male,
  mysterious
};

class Person
{
public:
  Person(string firstName, string name, string pesel, Sex sex, string address)
    : firstName(firstName)
    , name(name)
    , pesel(pesel)
    , sex(sex)
    , address(address)
  {
  }
  string firstName;
  string name;
  string pesel;
  Sex sex;
  string address;
  virtual string occupation() = 0;
  virtual int number() = 0;
};

class Student : public Person
{
public:
  Student(string firstName,
          string name,
          string pesel,
          Sex sex,
          string address,
          int number_index)
    : Person(firstName, name, pesel, sex, address)
    , number_index(number_index)
  {
  }
  int number_index;
  string student = "Student";
  int number() { return number_index; }
  string occupation() { return student; }
};

class Worker : public Person
{
public:
  Worker(string firstName,
         string name,
         string pesel,
         Sex sex,
         string address,
         int pay)
    : Person(firstName, name, pesel, sex, address)
    , pay(pay)
  {
  }
  int pay;
  string worker = "Worker";
  int number() { return pay; }
  string occupation() { return worker; }
};

#endif
