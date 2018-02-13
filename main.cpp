#include "employee.hpp"
#include "functions.hpp"
#include "person.hpp"
#include "student.hpp"
#include <iostream>
#include <vector>
//<<<<<<< HEAD
using namespace std;

int
main()
{
  std::vector<Person*> person;
  Person* wsk =
    new Employee("Siema", "Kowalski", "89000000", female, "Wrocław", 2310);
  Person* wsk1 =
    new Student("Wojtek", "Witkowik", "12345667", female, "Warszawa", 226);
  person.push_back(wsk);
  person.push_back(wsk1);
  show(person);
  deletePerson("12345667", person);
  show(person);
  findPersonpesel("89000000", person);
  findPersonsurname("Witkowik", person);
  save(person);
  delete wsk;
  delete wsk1;
  return 0;
}
