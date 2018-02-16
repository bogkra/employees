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

bool
findPersonPesel(string peselNumber, vector<shared_ptr<Person>>& m);

bool
findPersonSurname(string surname, vector<shared_ptr<Person>>& m);

void
deletePerson(string peselNumberOfErase, vector<shared_ptr<Person>>& m);

void
save(vector<shared_ptr<Person>>& m);

//5. Wypełnianie bazy danych sztucznymi danymi (std::generate, std::fill) 
void 
generate(vector<shared_ptr<Person>>& m);

void
fill(vector<shared_ptr<Person>>& v);

#endif
