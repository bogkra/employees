#include <iostream>
#include <vector>
using namespace std;

union ExtraData {
    char index[30];
    float pay;
  };

class person
{
 public:
  string firstName;
  string name;
  char PESEL[11];
  char sex;
  string address;
  float pay;
  string index;

  ExtraData extraData;

  person(string firstName = "", string name = "", string index = "");

};

//person::person(string firstName = "", string name = "", string index = "")
person::person(string inFirstName, string inName, string inIndex)
{
  firstName = inFirstName;
  name = inName;

  index = inIndex;
}



bool compare(const person& first, const person& second)
{
  return (first.index  < second.index);
}

class persons
{
 public:
   void insert_(string firstName, string name, string index);
   void insert_();
   void show();
   void sort();
   void deleteS();

 private:
   vector<person> persons;
   vector<person>::iterator it;
};

void persons::insert_(string firstName, string name, string index)
{
  person aperson(firstName, name, index);
  persons.push_back(aperson);
}

void persons::insert_()
{
  person aperson;

  cout << "first name: ";
  cin >> aperson.firstName;
  cout << "last name: ";
  cin >> aperson.name;
  cout << "index: ";
  cin >> aperson.index;
  cout << endl;
  persons.push_back(aperson);
}

void persons::show()
{
  for (it=persons.begin(); it!=persons.end(); ++it)
    cout << it->firstName  << " " << it->name  << ", " << it->index << endl;
  cout << endl;
}

void persons::sort()
{
//  sort(persons, compare);
}

void persons::deleteS()
{

  cout << "index: ";
  string ind;
  cin >> ind;
  for (it=persons.begin(); it!=persons.end(); ++it)
    if (it->index==ind) {
      it = persons.erase(it);
      cout << "Record successfully deleted\n";
    }
}

int main ()
{
  persons persons;

  persons.insert_("George", "Harrison", "144442");
  persons.insert_("Paul", "McCartney", "131312");
  persons.insert_("Ringo", "Starr", "145965");
  persons.insert_("John", "Lennon", "140666");

  string answer = "";
  do {
      cout << "I=Insert new record  L=show the vector  S=Sort by index  D=Delete by index  Q=Quit" << endl;
      cin >> answer;

      if (answer== "I" || answer=="i")
          persons.insert_();
      else if (answer== "L" || answer=="l")
          persons.show();
      else if (answer== "S" || answer=="s")
          persons.sort();
      else if (answer== "D" || answer=="d")
          persons.deleteS();

  }  while (answer!="Q" && answer!="q") ;

  cout << "\nend of the program\n";
 // persons.erase();

  return 0;
}
