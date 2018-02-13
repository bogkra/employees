#ifndef functions_hpp
#define functions_hpp
#include "person.hpp"
#include <fstream>
#include <iostream>
#include <string>
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

void
save(vector<Person*>& m);

#endif
