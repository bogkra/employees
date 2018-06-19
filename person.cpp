#include <iostream>
#include "person.hpp"
using namespace std;


Person::Person(string firstName,
               string name,
               string pesel,
               Sex sex,
               string address)
  : firstName(firstName),
    name(name),
    pesel(pesel),
    sex(sex),
    address(address) {
}

bool leapYear(int year) {
  if (year % 4 == 0 and year % 100 != 0)
    return true;
  else
    return year % 400 == 0;
}

int toint(const char ch) {
  return ch - '0';
}

void Person::getDate() {
  year  = 10 * toint(pesel[0]) + toint(pesel[1]);
  month = 10 * toint(pesel[2]) + toint(pesel[3]);
  day   = 10 * toint(pesel[4]) + toint(pesel[5]);
  if (month >= 80+1 and month <= 80+12) {
    year += 1800;
    month -= 80;
  }
  else if (month >= 1 and month < 12) {
    year += 1900;

  }
  else if (month >= 20+1 and month <= 20+12) {
    year += 2000;
    month -= 20;
  }
  else if (month >= 40+1 and month <= 40+12) {
    year += 2100;
    month -= 40;
  }
  else if (month >= 60+1 and month <= 60+12) {
    year += 2200;
    month -= 60;
  }
}


bool Person::checkMonth() {
  getDate();
  return month >= 1 and month <= 12;
}

bool Person::checkDay() {
  getDate();
  return
    (day >= 1 and day <= 31 and
        (   month == 1 
         or month == 3 
         or month == 5 
         or month == 7 
         or month == 8 
         or month == 10 
         or month == 12))
  or
    (day >= 1 and day <= 30 and
        (   month == 4 
         or month == 6 
         or month == 9  
         or month == 11))
  or
    (day >= 1 and day <= 29 and leapYear(year)) 
  or
    (day >= 1 and day <= 28 and !leapYear(year)) ;
}


bool Person::validatePESEL() {
  bool result = true;

  int p[11];
  for (int i = 0; i < 11; i++) {
    result = result and isdigit(pesel[i]);
    p[i] = pesel[i] - '0';
  }
  return     result 
         and (((9*p[0] + 7*p[1] + 3*p[2] + 1*p[3] + 9*p[4] + 7*p[5] + 3*p[6] + 1*p[7] + 9*p[8] + 7*p[9])   %  10 ==  p[10]) 
         and (p[9] % 2 == (sex == male ? 1 : 0)))
         and checkMonth()
         and checkDay();
}

void Person::show() {
  cout << occupation() << "  " 
       << firstName << "  " 
       << name  << "  " 
       << pesel << "  " 
       << (sex==male ? "male" : "female")  << "  " 
       << address  << "  " 
       << number() << endl;
}

