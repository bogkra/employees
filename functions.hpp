#ifndef functions_hpp
#define functions_hpp
#include "person.hpp"
#include "employee.hpp"
#include "student.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

void
downloadDatabase(vector<shared_ptr<Person>>& m);

void
show(vector<shared_ptr<Person>> m);

void
findPersonPesel(string peselNumber, vector<shared_ptr<Person>>& m);

void
findPersonSurname(string surname, vector<shared_ptr<Person>>& m);

void
deletePerson(string peselNumberofErase, vector<shared_ptr<Person>>& m);

void
save(vector<shared_ptr<Person>>& m);


#endif
