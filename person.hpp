#ifndef person_hpp
#define person_hpp
#include <string>
#include <memory>

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
  virtual string occupation() = 0;
  virtual int number() = 0;
  bool validatePESEL();
  void show();

  string get_firstName() { return firstName;  }
  string get_name() { return name;  }
  string get_pesel() { return pesel;  }
  Sex get_sex() { return sex;  }
  string get_address() { return address;  }

private:
  string firstName;
  string name;
  string pesel;
  Sex sex;
  string address;

};

typedef shared_ptr<Person> pp;


#endif
