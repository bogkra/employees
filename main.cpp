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
  std::vector<shared_ptr<Person>> persons;
  shared_ptr<Person> wsk =
    make_shared<Employee>("Roch", "Kowalski", "88032304776", male, "Wrocław", 2310);
  shared_ptr<Person> wsk2 =
    make_shared<Employee>("Siema", "Kowalski", "89000000", female, "Wrocław", 2310);
  shared_ptr<Person> wsk1 =
    make_shared<Student>("Wojtek", "Witkowik", "12345667", female, "Warszawa", 226);
  persons.push_back(wsk);
  persons.push_back(wsk2);
  persons.push_back(wsk1);
  show(persons);
  deletePerson("123456", persons);
  show(persons);
  findPersonPesel("89000000", persons);
  findPersonPesel("89040000", persons);
  findPersonSurname("Witkowik", persons);
  findPersonSurname("Sitkowik", persons);
  cout <<endl << "PESEL " << (persons[0]->validatePESEL() ? "OK" : "KO") << " for: " << persons[0]->firstName << " " << persons[0]->name <<endl;
//  show(person[0]);
  save(persons);
  downloadDatabase(persons);
  cout << "After download";
  show(persons);
  return 0;
}
