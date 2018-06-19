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


class Persons {
public:

  void findPersonPesel(string peselNumber);
  void findPersonSurname(string surname);

  void downloadDatabase(const string fileName);
  void save(const string fileName);
  void show();

  void deletePerson(string peselNumberOfErase);
  void generate();
  void fill();
  void sortPESEL();
  void sortName();
  void sortPay();
  void modify(string pesel, int pay_, string address);
  vector<pp> & getM() {return m_;};

private:
  vector<pp> m_;

};

#endif
