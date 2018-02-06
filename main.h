using namespace std;

//typedef char Index[30];
typedef long int Index;
typedef char Pesel[11];

enum Sex {female, male}; // , mysterious }; ;)


class Person {
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


