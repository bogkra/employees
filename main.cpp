#include "main.h"
#include <iostream>
#include <vector>

int
main()
{
  vector<Person*> person;
  Worker w("Siema", "S", "i", female, "k", 120);
  Student s("Wojtek", "W", "l", female, "q", 226);
  Person* wsk;
  wsk = &w;
  person.push_back(wsk);
  wsk = &s;
  person.push_back(wsk);
  cout << person[0]->occupation() << person[0]->number() << person[0]->sex
       << endl;
  cout << person[1]->occupation() << person[1]->number() << endl;
  return 0;
}
