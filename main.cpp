#include "employee.hpp"
#include "functions.hpp"
#include "person.hpp"
#include "student.hpp"
#include <iostream>
#include <vector>
#include <memory>
//<<<<<<< HEAD
using namespace std;

int main()
{
  cout << "hello!  ";
  std::vector<shared_ptr<Person>> person;
  shared_ptr<Person> wsk =
    make_shared<Employee>("Roch", "Kowalski", "88032304776", male, "Wrocław", 2310);
    make_shared<Employee>("Siema", "Kowalski", "89000000", female, "Wrocław", 2310);
  shared_ptr<Person> wsk1 =
    make_shared<Student>("Wojtek", "Witkowik", "12345667", female, "Warszawa", 226);
  person.push_back(wsk);
  person.push_back(wsk1);
  show(person);
  deletePerson("123456", person);
  show(person);
  findPersonPesel("89000000", person);
  findPersonSurname("Witkowik", person);
  cout <<endl << "PESEL " << (person[0]->validatePESEL() ? "OK" : "KO") << " for: " << person[0]->firstName << " " << person[0]->name <<endl;
//  show(person[0]);
  save(person);
  downloadDatabase(person);
  cout << "After download";
  show(person);
  return 0;
}
