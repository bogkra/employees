#include "functions.hpp"
#include <algorithm>

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

bool 
comparePesels(shared_ptr<Person> p, string pesel)
{
  return p->pesel == pesel;
}

bool
findPersonPesel(string peselNumber, vector<shared_ptr<Person>>& m)
{
  auto it = find_if(m.begin(), m.end(), bind(comparePesels, placeholders::_1, peselNumber));
  if (it != m.end()) {
    cout << "Found Person:" << endl;
    show(*it);
    return true;
  }
  else {
    cout << "Lack of PESEL!" << endl;
    return false;
  }
}

bool 
compareNames(shared_ptr<Person> p, string name)
{
  return p->name == name;
}

bool
findPersonSurname(string surname, vector<shared_ptr<Person>>& m)
{
  auto it = find_if(m.begin(), m.end(), bind(compareNames, placeholders::_1, surname));
  if (it != m.end()) {
    cout << "Found Person:" << endl;
    show(*it);
    return true; 
  }
  else {
    cout << "Lack of surname!" << endl;
    return false;
  }
}

void
deletePerson(string peselNumberOfErase, vector<shared_ptr<Person>>& m)
{
  auto it = find_if(m.begin(), m.end(), bind(comparePesels, placeholders::_1, peselNumberOfErase));
  if (it != m.end()) {
    m.erase(it);
    cout << "A person deleted" << endl;
  }
  else {
    cout << "Lack of PESEL!" << endl;
  }
}


//5. Wypełnianie bazy danych sztucznymi danymi (std::generate, std::fill) 
string randomString(int len)
{
   srand(time(0));
   string str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
   string newstr;
   int pos;
   while(newstr.size() != len) {
     pos = ((rand() % (str.size() - 1)));
     newstr += str.substr(pos,1);
   }
   return newstr;
}

Sex 
randomSex()
{
 return (((rand() % 2) == 0) ? male : female);
}
 

void
generate(vector<shared_ptr<Person>>& v)
{
//   srand(time(0));
//   generate(v.begin(), v.end(), make_shared<Employee>(randomString(5), "Kowalski", "88032304776", male, "Wrocław", 2310));
  generate(v.begin(), v.end(), [] () {    srand(time(0)); return make_shared<Employee>(randomString(5), randomString(9), randomString(11), randomSex(), randomString(5), rand()); } );

}

void
fill(vector<shared_ptr<Person>>& v)
{
   srand(time(0));
   fill(v.begin(), v.end(), make_shared<Employee>(randomString(5), randomString(9), randomString(11), randomSex(), randomString(5), rand()));
}


