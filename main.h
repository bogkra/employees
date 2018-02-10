#ifndef main_h
#define main_h
#include <string>

using namespace std;

//<<<<<<< HEAD
//typedef char Index[30];
typedef long int Index;
//typedef char Pesel[11];

enum Sex {female, male};


/*class Person {
  public:
    string firstName;
    string name;
    Pesel PESEL;
    Sex sex; // warning: sex depends on PESEL (!)
    string address;

    Person(const string inFirstName = "", const string inName = "");
    bool validatePESEL();

};

class Student : public Person {
  public:
    Index index;
};

class Employee : public Person {
  public:
    float salary;
};


class Persons {
  public:
    void insert_(string firstName, string name);
    void insert_();
    void show();
    void sort();
    void deleteS();

    bool find(Pesel p);
    bool find(string name);

  private:
    vector<Person> persons;
    vector<Person>::iterator it;
};

*/
//=======

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

  bool validatePESEL();

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
  string student;// = "Student";
  int number() { return number_index; }
  string occupation() { return student; }
};

class Employee : public Person
{
public:
  Employee(string firstName,
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
  string employee;// = "Worker";
  int number() { return pay; }
  string occupation() { return employee; }
};

#endif

