#ifndef functions_hpp
#define functions_hpp
#include "person.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

void
show(vector<shared_ptr<Person>> m);

void
findPersonpesel(string peselNumber, vector<shared_ptr<Person>>& m);

void
findPersonsurname(string surname, vector<shared_ptr<Person>>& m);

void
deletePerson(string peselNumberofErase, vector<shared_ptr<Person>>& m);

void
save(vector<shared_ptr<Person>>& m);

#endif
