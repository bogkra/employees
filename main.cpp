#include "employee.hpp"
#include "person.hpp"
#include "persons.hpp"
#include "student.hpp"
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

int main()
{
  srand(time(0)); 
  const string file = "plik.txt";  

  Persons persons;
  shared_ptr<Person> wsk =
    make_shared<Employee>("Roch", "Kowalski", "88032304776", male, "Wrocław", 2310);
  shared_ptr<Person> wsk2 =
    make_shared<Employee>("Siema", "Kowalski", "89000000", female, "Wrocław", 1234);
  shared_ptr<Person> wsk1 =
    make_shared<Student>("Wojtek", "Witkowik", "12345667", female, "Warszawa", 1996);
  persons.m.push_back(wsk);
  persons.m.push_back(wsk2);
  persons.m.push_back(wsk1);
  persons.modify("89000000", 12543, "Głuchołazy");
  persons.show();
  persons.deletePerson("123456");
  persons.show();
  persons.findPersonPesel("89000000");
  persons.findPersonPesel("89040000");
  persons.findPersonSurname("Witkowik");
  persons.findPersonSurname("Sitkowik");

  cout <<endl << "PESEL " << (persons.m[0]->validatePESEL() ? "OK" : "KO") ;
  cout << " for: " << persons.m[0]->firstName << " " << persons.m[0]->name <<endl;

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
