#include "person.hpp"
#include "persons.hpp"
#include <algorithm>

void
Persons::downloadDatabase(const string fileName)
{
  string occupation, firstName, name, pesel, address;
  int sex, number;
  ifstream file;
  file.open(fileName);
  if (file.good()) {
    while (file >> occupation >> firstName >> name >> pesel >> sex >> address >> number) {
      if (occupation == "Student") {
        shared_ptr<Person> ptr =
          make_shared<Student>(firstName, name, pesel, Sex(sex), address, number);
        m.push_back(ptr);
      }
      if (occupation == "Employee") {
        shared_ptr<Person> ptr = make_shared<Employee>(
          firstName, name, pesel, Sex(sex), address, number);
        m.push_back(ptr);
      }
    }
    file.close();
  }
}

void
Persons::save(const string fileName)
{
  fstream file(fileName, ios::out);
  if (file.good()) {
    for (auto it = m.begin(); it != m.end(); ++it) {
      file << (*it)->occupation() << "  " << (*it)->firstName << "  "
           << (*it)->name << "  " << (*it)->pesel << "  " << (*it)->sex << "  "
           << (*it)->address << "  " << (*it)->number() << endl;
      file.flush();
    }
    file.close();
  }
}

void
Persons::show()
{
  cout << "Database:" << endl;
  for (auto it = m.begin(); it != m.end(); ++it){
    (*it)->show();
  }
  cout << endl;
}

shared_ptr<Person>
Persons::findPersonPesel(string peselNumber)
{
  auto it = find_if(m.begin(), m.end(), [peselNumber] (const shared_ptr<Person> p) { return p->pesel == peselNumber;});
  if (it != m.end()) {
    cout << "Found Person:" << endl;
    (*it)->show();
  }
  else 
    cout << "PESEL not found!" << endl;
  return *it;
}

shared_ptr<Person>
Persons::findPersonSurname(string surname)
{
  auto it = find_if(m.begin(), m.end(), [surname] (const shared_ptr<Person> p) { return p->name == surname;});
  if (it != m.end()) {
    cout << "Found Person:" << endl;
    (*it)->show();
  }
  else 
    cout << "Surname not found!" << endl;
  return *it;
}

void
Persons::deletePerson(string peselNumberOfErase)
{
  auto it = find_if(m.begin(), m.end(), [peselNumberOfErase] (const shared_ptr<Person> p) { return p->pesel == peselNumberOfErase;});
  if (it != m.end()) {
    m.erase(it);
    cout << "A person deleted" << endl;
  }
  else 
    cout << "PESEL not found!" << endl;
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
Persons::generate()
{
   std::generate(m.begin(), m.end(), [] () { 
            return make_shared<Employee>(randomString(5), randomString(9), randomString(11), randomSex(), randomString(5), rand()); 
   } );
}

void
Persons::fill()
{
   if ((rand() % 2) == 0)  
     std::fill(m.begin(), m.end(), make_shared<Employee>(randomString(5), randomString(9), randomString(11), randomSex(), randomString(5), rand()));
   else
     std::fill(m.begin(), m.end(), make_shared<Student>(randomString(5), randomString(9), randomString(11), randomSex(), randomString(5), rand()));
}

void
Persons::sortPESEL() 
{
  sort(m.begin(), m.end(), [](shared_ptr<Person> p1, shared_ptr<Person> p2) {
        return p1->pesel < p2->pesel;   
  });
}

void
Persons::sortName() 
{
  sort(m.begin(), m.end(), [](shared_ptr<Person> p1, shared_ptr<Person> p2) {
        return p1->name < p2->name;   
  });
}

void
Persons::sortPay() 
{
  sort(m.begin(), m.end(), [](shared_ptr<Person> p1, shared_ptr<Person> p2) {
 	if (p1->occupation() == "Student")
          return false;
        else if (p2->occupation() == "Student")
          return true;
        else
          return (p1->number() < p2->number());   
  });
}

//8. Modyfikacja zarobków i adresu po numerze PESEL 
void
Persons::modify(string pesel, int pay_, string address)
{
  auto it = find_if(m.begin(), m.end(), [pesel] (const shared_ptr<Person> p) { return p->pesel == pesel;});
  if (it != m.end()) {
    string firstName = (*it)->firstName;
    string name = (*it)->name;
    Sex sex = (*it)->sex;
    m.erase(it);
    
    shared_ptr<Person> ptr = make_shared<Employee>(firstName, name, pesel, sex, address, pay_);
    m.push_back(ptr);

    cout << "A person modified" << endl;
  }
}


