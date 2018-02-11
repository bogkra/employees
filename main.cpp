#include "main.h"
#include <iostream>
#include <vector>
//<<<<<<< HEAD
using namespace std;

/*
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
*/
void show(vector<Person*> m) {
	int i=0;
  for (auto it=m.begin(); it!=m.end(); ++it) {
    cout << m[i]->occupation() << "  " << m[i]->firstName << "  " << m[i]->name << "  " << m[i]->pesel << "  " << m[i]->sex << "  " << m[i]->address << "  " << m[i]->number()<<endl;
   i++; 
  }
}
/*
void Persons::sort() {
//  sort(Persons, compare);
}
*/
void deletePerson(string peselNumberofErase,vector<Person*> &m) {
	auto it2=m.begin();
	int i=0;
  for (auto it=m.begin(); it!=m.end(); it++) {
  if( peselNumberofErase == m[i]->pesel)
  {
  	m.erase(it2+i);
	return;
  }
   if( peselNumberofErase != m[i]->pesel)
   {
	   i++;
   }
}
cout << "Lack of pesel!" <<endl;
}



bool Person::validatePESEL() {
 // dodac wyjatki!
  int p[11];
  for (int i=0; i<11; i++)
    p[i] = pesel[i] - '0';
 
  return ( ( (9*p[0] + 7*p[1] + 3*p[2] + 1*p[3] + 9*p[4] + 7*p[5] + 3*p[6] + 1*p[7] + 9*p[8] + 7*p[9]  ) % 10 == p[10] )
           && (p[9] % 2 == (sex == male ? 1 : 0)) );

  // warning: possible more precise validations - day of month, month, date in the future...
}

/*
 MENU
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
*/

int main()
{
  std::vector<Person*> person;
  Person* wsk = new Employee("Siema", "Kowalski", "89000000", female, "Wrocław", 2310);
  Person* wsk1 = new Student("Wojtek", "Witkowik", "12345667", female, "Warszawa", 226);
  person.push_back(wsk);
  person.push_back(wsk1);
  show(person);
  deletePerson("12345667",person);
  show(person);
  delete wsk;
  delete wsk1;
  return 0;
}
