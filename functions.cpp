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
string 
randomString(int len)
{
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
   generate(v.begin(), v.end(), [] () { 
//          if ((rand() % 2) == 0)  
            return make_shared<Employee>(randomString(5), randomString(9), randomString(11), randomSex(), randomString(5), rand()); 
  //        else
    //        return make_shared<Student>(randomString(5), randomString(9), randomString(11), randomSex(), randomString(5), rand()); 
         } );

}

void
fill(vector<shared_ptr<Person>>& v)
{
   if ((rand() % 2) == 0)  
     fill(v.begin(), v.end(), make_shared<Employee>(randomString(5), randomString(9), randomString(11), randomSex(), randomString(5), rand()));
   else
     fill(v.begin(), v.end(), make_shared<Student>(randomString(5), randomString(9), randomString(11), randomSex(), randomString(5), rand()));
}

void
sortPESEL(vector<shared_ptr<Person>>& v) 
{
  sort(v.begin(), v.end(), [](shared_ptr<Person> p1, shared_ptr<Person> p2) {
        return p1->pesel < p2->pesel;   
    });
}

void
sortName(vector<shared_ptr<Person>>& v) 
{
  sort(v.begin(), v.end(), [](shared_ptr<Person> p1, shared_ptr<Person> p2) {
        return p1->name < p2->name;   
    });
}

void
sortPay(vector<shared_ptr<Person>>& v) 
{
//  sort(v.begin(), v.end(), [](shared_ptr<Person> p1, shared_ptr<Person> p2) {
//        return p1->pay < p2->pay;   
//    });
}

