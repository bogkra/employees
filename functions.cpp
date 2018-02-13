#include "functions.hpp"

void
save(vector<shared_ptr<Person>>& m)
{
  fstream plik("plik.txt", ios::out);
  if (plik.good()) {
    plik << "Database:" << endl;
    int i = 0;
    for (auto it = m.begin(); it != m.end(); ++it) {
      plik << m[i]->occupation() << "  " << m[i]->firstName << "  "
           << m[i]->name << "  " << m[i]->pesel << "  " << m[i]->sex << "  "
           << m[i]->address << "  " << m[i]->number() << endl;
      i++;
      plik.flush();
    }
    plik.close();
  }
}

void
show(vector<shared_ptr<Person>> m)
{
  cout << "Database:" << endl;
  int i = 0;
  for (auto it = m.begin(); it != m.end(); ++it) {
    cout << m[i]->occupation() << "  " << m[i]->firstName << "  " << m[i]->name
         << "  " << m[i]->pesel << "  " << m[i]->sex << "  " << m[i]->address
         << "  " << m[i]->number() << endl;
    i++;
  }
  cout << endl;
}

void
findPersonpesel(string peselNumber, vector<shared_ptr<Person>>& m)
{
  auto it2 = m.begin();
  int i = 0;
  for (auto it = m.begin(); it != m.end(); it++) {
    if (peselNumber == m[i]->pesel) {
      cout << "Found Person:" << endl;
      cout << m[i]->occupation() << "  " << m[i]->firstName << "  "
           << m[i]->name << "  " << m[i]->pesel << "  " << m[i]->sex << "  "
           << m[i]->address << "  " << m[i]->number() << endl;
      return;
    }
    if (peselNumber != m[i]->pesel) {
      i++;
    }
  }
  cout << "Lack of pesel!" << endl;
}

void
findPersonsurname(string surname, vector<shared_ptr<Person>>& m)
{
  auto it2 = m.begin();
  int i = 0;
  for (auto it = m.begin(); it != m.end(); it++) {
    if (surname == m[i]->name) {
      cout << "Found Person:" << endl;
      cout << m[i]->occupation() << "  " << m[i]->firstName << "  "
           << m[i]->name << "  " << m[i]->pesel << "  " << m[i]->sex << "  "
           << m[i]->address << "  " << m[i]->number() << endl;
      return;
    }
    if (surname != m[i]->name) {
      i++;
    }
  }
  cout << "Lack of surname!" << endl;
}

void
deletePerson(string peselNumberofErase, vector<shared_ptr<Person>>& m)
{
  auto it2 = m.begin();
  int i = 0;
  for (auto it = m.begin(); it != m.end(); it++) {
    if (peselNumberofErase == m[i]->pesel) {
      m.erase(it2 + i);
      return;
    }
    if (peselNumberofErase != m[i]->pesel) {
      i++;
    }
  }
  cout << "Lack of pesel!" << endl;
}
