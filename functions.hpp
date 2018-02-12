#ifndef functions_hpp
#define functions_hpp
#include <iostream>
#include <string>
#include "person.hpp"
#include <vector>

using namespace std;

void
show(vector<Person*> m);

void
findPersonpesel(string peselNumber, vector<Person*>& m);

void
findPersonsurname(string surname, vector<Person*>& m);

void
deletePerson(string peselNumberofErase, vector<Person*>& m);

#endif
