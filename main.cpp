#include <iostream>
#include <vector>
#include "main.h"


//person::person(string firstName = "", string name = "", string index = "")
Person::Person(const string inFirstName, const string inName) {
  firstName = inFirstName;
  name = inName;
}


bool compareInd(const Student& first, const Student& second) {
  return (first.index  < second.index);
}



void Persons::insert_(string firstName, string name) {
  Person aPerson(firstName, name);
  persons.push_back(aPerson);
}

void Persons::insert_() {
  Person aPerson;

  cout << "first name: ";
  cin >> aPerson.firstName;
  cout << "last name: ";
  cin >> aPerson.name;
  cout << endl;
  persons.push_back(aPerson);
}

void Persons::show() {
  for (it=persons.begin(); it!=persons.end(); ++it) {
    cout << it->firstName  << " " << it->name  << " PESEL:" << it->PESEL << (it->sex==male ? ", male" : ", female") << ", address: " << it->address;
    cout << endl;
  }

 // cout << endl;
}

void Persons::sort() {
//  sort(Persons, compare);
}

void Persons::deleteS() {

}

bool Person::validatePESEL() {
  int p[11];
  for (int i=0; i<11; i++)
    p[i] = PESEL[i] - '0';    
 
  return ( ( (9*p[0] + 7*p[1] + 3*p[2] + 1*p[3] + 9*p[4] + 7*p[5] + 3*p[6] + 1*p[7] + 9*p[8] + 7*p[9]  ) % 10 == p[10] )
           && (p[9] % 2 == (sex == male ? 1 : 0)) );

  // warning: possible more precise validations - day of month, month, date in the future...
}

int main () {
  Persons persons;

  persons.insert_("George", "Harrison");//, "144442");
  persons.insert_("Paul", "McCartney");// "131312");
  persons.insert_("Ringo", "Starr");//, "145965");
  persons.insert_("John", "Lennon");//, "140666");

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
