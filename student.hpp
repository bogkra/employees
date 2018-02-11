#ifndef student_hpp
#define student_hpp
#include "person.hpp"
#include <string>

using namespace std;

class Student : public Person
{
public:
  Student(string firstName,
          string name,
          string pesel,
          Sex sex,
          string address,
          int number_index);
  int number_index;
  string student = "Student";
  int number();
  string occupation();
};

#endif
