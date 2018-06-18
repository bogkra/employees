#include "student.hpp"

using namespace std;

Student::Student(string firstName,
                 string name,
                 string pesel,
                 Sex sex,
                 string address,
                 int number_index)
  : Person(firstName, name, pesel, sex, address)
  , number_index(number_index) {
}

string Student::occupation() {
  return student;
}

int Student::number() {
  return number_index;
}
