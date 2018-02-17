#include "employee.hpp"
#include "functions.hpp"
#include "person.hpp"
#include "student.hpp"
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

int main()
{
  srand(time(0)); 

  std::vector<shared_ptr<Person>> persons;
  shared_ptr<Person> wsk =
    make_shared<Employee>("Roch", "Kowalski", "88032304776", male, "Wrocław", 2310);
  shared_ptr<Person> wsk2 =
    make_shared<Employee>("Siema", "Kowalski", "89000000", female, "Wrocław", 1234);
  shared_ptr<Person> wsk1 =
    make_shared<Student>("Wojtek", "Witkowik", "12345667", female, "Warszawa", 1996);
  persons.push_back(wsk);
  persons.push_back(wsk2);
  persons.push_back(wsk1);
  modify("89000000", 12543, "Głuchołazy", persons);
  show(persons);
  deletePerson("123456", persons);
  show(persons);
  findPersonPesel("89000000", persons);
  findPersonPesel("89040000", persons);
  findPersonSurname("Witkowik", persons);
  findPersonSurname("Sitkowik", persons);
  cout <<endl << "PESEL " << (persons[0]->validatePESEL() ? "OK" : "KO") << " for: " << persons[0]->firstName << " " << persons[0]->name <<endl;
//  show(person[0]);
  save(persons);
  downloadDatabase(persons);
  cout << "After download  "<< endl;
  show(persons);
  sortPay(persons);
  cout << "_________________" << endl;
  show(persons); 
/*
  fill(persons);
  cout << "................" << endl;
  show(persons);
  generate(persons);
  cout << "_________________" << endl;
  show(persons);
*/
  sortPESEL(persons);
  cout << "_________________" << endl;
  show(persons);
  sortName(persons);
  cout << "_________________" << endl;
  show(persons);
 
  return 0;
}

/*
Wymagania: 
1. Przechowywanie rekordów pracowników o strukturze: Imię, nazwisko, PESEL, płeć, adres, zarobki. Przechowywanie rekordów studentów o strukturze: Imię, nazwisko, PESEL, płeć, adres, nr indeksu. Wszystkie osoby niezależnie czy będą to pracownicy czy studenci mają być trzymani w jednej kolekcji. 
2. Wyszukiwanie po nazwisku i numerze PESEL (std::find) 
3. Wyświetlanie pełnej bazy danych 
4. Sortowanie po zarobkach, PESELu, nazwisku (std::sort) 
5. Wypełnianie bazy danych sztucznymi danymi (std::generate, std::fill) 
6. Wczytywanie z pliku i zapisywanie całej bazy w pliku 
7. Usuwanie po numerze PESEL (std::erase, std::remove) 
8. Modyfikacja zarobków i adresu po numerze PESEL 
9. Walidacja czy numer PESEL jest poprawny (std::isdigit) https://pl.wikipedia.org/wiki/PESEL#Cyfra_kontrolna_i_sprawdzanie_poprawno%C5%9Bci_numeru 
*/
