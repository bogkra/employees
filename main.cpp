#include <iostream>
#include <vector>
#include "main.h"


//person::person(string firstName = "", string name = "", string index = "")
Person::Person(const string inFirstName, const string inName)
{
  firstName = inFirstName;
  name = inName;
}


bool compareInd(const Student& first, const Student& second)
{
  return (first.index  < second.index);
}



void Persons::insert_(string firstName, string name)
{
  Person aPerson(firstName, name);
  Persons.push_back(aPerson);
}

void Persons::insert_()
{
  Person aPerson;

  cout << "first name: ";
  cin >> aPerson.firstName;
  cout << "last name: ";
  cin >> aPerson.name;
  cout << endl;
  Persons.push_back(aPerson);
}

void Persons::show()
{
  for (it=Persons.begin(); it!=Persons.end(); ++it)
    cout << it->firstName  << " " << it->name  << endl ; //<< ", " << it->extra.index << endl;
  cout << endl;
}

void Persons::sort()
{
//  sort(Persons, compare);
}

void Persons::deleteS()
{

//  cout << "index: ";
//  Index ind;
//  cin >> ind;
 // for (it=Persons.begin(); it!=Persons.end(); ++it)
  //  if (it->extra.index==ind) {
 //     it = Persons.erase(it);
  //    cout << "Record successfully deleted\n";
  //  }
}

int main ()
{
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
