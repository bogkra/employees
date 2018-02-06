#include "main.h"
#include <iostream>
#include <vector>

int
main()
{
  vector<Person*> person;
  Worker w("Siema", "S", "i", "k", 120);
  Student s("Wojtek", "W", "l", "q", 226);
  Person* wsk;
  wsk = &w;
  person.push_back(wsk);
  cout << person[0]->number() << endl;
  return 0;
}
