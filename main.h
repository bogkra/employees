using namespace std;

//typedef char Index[30];
typedef long int Index;


enum Sex {female, male, mysterious };


class Person {
 public:
  string firstName;
  string name;
  char PESEL[11];
  Sex sex;
  string address;

  Person(const string inFirstName = "", const string inName = "");
};

class Student : public Person {
 public:
  Index index;
};

class Employee : public Person {
 public:
  float salary;
};


class Persons
{
 public:
   void insert_(string firstName, string name);
   void insert_();
   void show();
   void sort();
   void deleteS();

 private:
   vector<Person> Persons;
   vector<Person>::iterator it;
};


