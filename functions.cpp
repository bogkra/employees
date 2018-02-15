#include "functions.hpp"

void
downloadDatabase(vector<shared_ptr<Person>>& m)
{
  string occupation, firstname, name, pesel, address;
  int sex;
  int number;
  ifstream plik;
  string wiersz;
  int nr_wiersza = 0;
  plik.open("plik.txt");
  if (plik.good()) {
    while (plik >> occupation >> firstname >> name >> pesel >> sex >> address >>
           number) {
      if (occupation == "Student") {
        shared_ptr<Person> wsk =
          make_shared<Student>(firstname, name, pesel, female, address, number);
        m.push_back(wsk);
      }
      if (occupation == "Employee") {
        shared_ptr<Person> wsk = make_shared<Employee>(
          firstname, name, pesel, female, address, number);
        m.push_back(wsk);
      }
    }
    plik.close();
  }
}

void
save(vector<shared_ptr<Person>>& m)
{
  fstream plik("plik.txt", ios::out);
  if (plik.good()) {
    // plik << "Database:" << endl;
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
show(shared_ptr<Person> p)
{
    cout << p->occupation() << "  " << p->firstName << "  " << p->name
         << "  " << p->pesel << "  " << ((p->sex)==male ? "male" : "female") << "  " << p->address
         << "  " << p->number() << endl;
}




void
show(vector<shared_ptr<Person>> m)
{
  cout << "Database:" << endl;
  int i = 0;
  for (auto it = m.begin(); it != m.end(); ++it){
    show(m[i]);
    i++;
  }
  cout << endl;
}

void
findPersonPesel(string peselNumber, vector<shared_ptr<Person>>& m)
{
  auto it2 = m.begin();
  int i = 0;
  for (auto it = m.begin(); it != m.end(); it++) {
    if (peselNumber == m[i]->pesel) {
      cout << "Found Person:" << endl;
      show(m[i]);
      return;
    }
    if (peselNumber != m[i]->pesel) {
      i++;
    }
  }
  cout << "Lack of pesel!" << endl;
}

void
findPersonSurname(string surname, vector<shared_ptr<Person>>& m)
{
  auto it2 = m.begin();
  int i = 0;
  for (auto it = m.begin(); it != m.end(); it++) {
    if (surname == m[i]->name) {
      cout << "Found Person:" << endl;
      show(m[i]);
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


