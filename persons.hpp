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
  vector<pp> m;

  void downloadDatabase(const string fileName);
  void save(const string fileName);
  void show();
  pp findPersonPesel(string peselNumber);
  pp findPersonSurname(string surname);
  void deletePerson(string peselNumberOfErase);
  void generate();
  void fill();
  void sortPESEL();
  void sortName();
  void sortPay();
  void modify(string pesel, int pay_, string address);

private:

};

#endif
