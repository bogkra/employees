#include "employee.hpp"
#include "functions.hpp"
#include "person.hpp"
#include "student.hpp"
#include <iostream>
#include <vector>
#include <memory>
//<<<<<<< HEAD
using namespace std;

int
main()
{
  std::vector<shared_ptr<Person>> person;
  shared_ptr<Person> wsk =
    make_shared<Employee>("Siema", "Kowalski", "89000000", female, "Wrocław", 2310);
  shared_ptr<Person> wsk1 =
    make_shared<Student>("Wojtek", "Witkowik", "12345667", female, "Warszawa", 226);
  person.push_back(wsk);
  person.push_back(wsk1);
  show(person);
  deletePerson("12345667", person);
  show(person);
  findPersonpesel("89000000", person);
  findPersonsurname("Witkowik", person);
  save(person);
  return 0;
}
