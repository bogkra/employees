#ifndef person_hpp
#define person_hpp
#include <string>

using namespace std;

enum Sex
{
  female,
  male
};

class Person
{
public:
  Person(string firstName, string name, string pesel, Sex sex, string address);
  string firstName;
  string name;
  string pesel;
  Sex sex;
  string address;
  virtual string occupation() = 0;
  virtual int number() = 0;
  bool validatePESEL();
  void show();

protected:
//  string firstName;
//  string name;


};

#endif
