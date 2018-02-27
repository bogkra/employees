#ifndef persons_hpp
#define persons_hpp
#include "person.hpp"
#include "employee.hpp"
#include "student.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Persons
{
public:
  vector<shared_ptr<Person>> m;

  void downloadDatabase();
  void save();
  void show();
  bool findPersonPesel(string peselNumber);
  bool findPersonSurname(string surname);
  void deletePerson(string peselNumberOfErase);
  void generate();
  void fill();
  void sortPESEL();
  void sortName();
  void sortPay();
  void modify(string pesel, int pay_, string address);
};

#endif
