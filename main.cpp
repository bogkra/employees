#include "employee.hpp"
#include "person.hpp"
#include "persons.hpp"
#include "student.hpp"
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

int main() {
  srand(time(0)); 
  const string file = "plik.txt";  

  Persons persons;
  shared_ptr<Person> wsk =
    make_shared<Employee>("Roch", "Kowalski", "88032304776", male, "Wrocław", 2310);
  shared_ptr<Person> wsk2 =
    make_shared<Employee>("Siema", "Kowalski", "89000000", female, "Wrocław", 1234);
  shared_ptr<Person> wsk1 =
    make_shared<Student>("Wojtek", "Witkowik", "12345667", female, "Warszawa", 1996);
  persons.getM().push_back(wsk);
  persons.getM().push_back(wsk2);
  persons.getM().push_back(wsk1);
  persons.modify("89000000", 12543, "Głuchołazy");
  persons.show();
  persons.deletePerson("123456");
  persons.show();
  persons.findPersonPesel("89000000");
  persons.findPersonPesel("89040000");
  persons.findPersonSurname("Witkowik");
  persons.findPersonSurname("Sitkowik");

  cout <<endl << "PESEL " << (persons.getM()[0]->validatePESEL() ? "OK" : "KO") << " for: ";
  persons.getM()[0]->show();

  persons.save(file);
  persons.downloadDatabase(file);
  cout << "After download  "<< endl;
  persons.show();
  persons.sortPay();
  cout << "_________________" << endl;
  persons.show(); 
  persons.sortPESEL();
  cout << "_________________" << endl;
  persons.show();
  persons.sortName();
  cout << "_________________" << endl;
  persons.show();

  return 0;
}


