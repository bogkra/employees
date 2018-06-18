#ifndef person_hpp
#define person_hpp
#include <string>
#include <memory>

using namespace std;

enum Sex {
  female,
  male
};

class Person {
public:
  Person(string firstName, string name, string pesel, Sex sex, string address);
  virtual string occupation() = 0;
  virtual int number() = 0;
  bool validatePESEL();
  void show();

  string get_firstName() const { return firstName; }
  string get_name() const { return name; }
  string get_pesel() const { return pesel; }
  Sex get_sex() const { return sex; }
  string get_address() const { return address; }

private:
  string firstName;
  string name;
  string pesel;
  Sex sex;
  string address;

  void getDate();
  bool checkMonth();
  bool checkDay();
 
  int year, month, day;
};

typedef shared_ptr<Person> pp;


#endif
