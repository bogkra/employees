#include "person.hpp"
#include "persons.hpp"
#include <algorithm>

void Persons::downloadDatabase(const string fileName) {
  string occupation, firstName, name, pesel, address;
  int sex, number;
  ifstream file;
  file.open(fileName);
  if (file.good()) {
    while (file >> occupation >> firstName >> name >> pesel >> sex >> address >> number) {
      if (occupation == "Student") {
        pp ptr =  make_shared<Student>(firstName, name, pesel, Sex(sex), address, number);
        m_.push_back(ptr);
      }
      if (occupation == "Employee") {
        pp ptr = make_shared<Employee>(
          firstName, name, pesel, Sex(sex), address, number);
        m_.push_back(ptr);
      }
    }
    file.close();
  }
}

void Persons::save(const string fileName) {
  fstream file(fileName, ios::out);

  if (file.good()) {
    for (auto p : m_) {
      file << p->occupation() << "  " << p->getFirstName() << "  "  << p->getName()  << "  " 
           << p->getPesel() << "  " << p->getSex() << "  " << p->getAddress() << "  " << p->number() << endl;
      file.flush();
    };
    file.close();
  };
}

void Persons::show() {
  cout << "Database:" << endl;
  for (auto p : m_) 
    p->show();
  cout << endl;
}

void Persons::findPersonPesel(string peselNumber) {
  auto it = find_if(m_.begin(), m_.end(), [peselNumber] (const pp p) { 
    return p->getPesel() == peselNumber;
  });
  if (it != m_.end()) {
    cout << "Found Person:" << endl;
    (*it)->show();
  }
  else 
    cout << "PESEL not found!" << endl;
}

void Persons::findPersonSurname(string surname) {
  auto it = find_if(m_.begin(), m_.end(), [surname] (const pp p) { 
    return p->getName() == surname;
  });
  if (it != m_.end()) {
    cout << "Found Person:" << endl;
    (*it)->show();
  }
  else 
    cout << "Surname not found!" << endl;
}

void Persons::deletePerson(string peselNumberOfErase) {
  auto it = find_if(m_.begin(), m_.end(), [peselNumberOfErase] (const pp p) { 
    return p->getPesel() == peselNumberOfErase;
  });
  if (it != m_.end()) {
    m_.erase(it);
    cout << "A person deleted" << endl;
  }
  else 
    cout << "PESEL not found!" << endl;
}


//5. Wypełnianie bazy danych sztucznymi danymi (std::generate, std::fill) 
string randomString(const unsigned int len) {
  string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  string newstr;
  int pos;
  while(newstr.size() != len) {
     pos = ((rand() % (str.size() - 1)));
     newstr += str.substr(pos,1);
  }
  return newstr;
}

Sex randomSex() {
  return (((rand() % 2) == 0) ? male : female);
}
 

void Persons::generate() {
   std::generate(m_.begin(), m_.end(), [] () { 
     return make_shared<Student>(randomString(5), randomString(9), randomString(11), randomSex(), randomString(5), rand()); 
   } );
}

void Persons::fill() {
   if ((rand() % 2) == 0)  
     std::fill(m_.begin(), m_.end(), make_shared<Employee>(randomString(5), randomString(9), randomString(11), randomSex(), randomString(5), rand()));
   else
     std::fill(m_.begin(), m_.end(), make_shared<Student>(randomString(5), randomString(9), randomString(11), randomSex(), randomString(5), rand()));
}

void Persons::sortPESEL() {
  sort(m_.begin(), m_.end(), [](pp p1, pp p2) {
        return p1->getPesel() < p2->getPesel();   
  });
}

void Persons::sortName() {
  sort(m_.begin(), m_.end(), [](pp p1, pp p2) {
        return p1->getName() < p2->getName();   
  });
}

void Persons::sortPay() {
  sort(m_.begin(), m_.end(), [](pp p1, pp p2) {
 	if (p1->occupation() == "Student")
          return false;
        else if (p2->occupation() == "Student")
          return true;
        else
          return (p1->number() < p2->number());   
  });
}

//8. Modyfikacja zarobków i adresu po numerze PESEL 
void Persons::modify(string pesel, int pay_, string address) {
  auto it = find_if(m_.begin(), m_.end(), [pesel] (const pp p) { 
    return p->getPesel() == pesel;
  });
  if (it != m_.end()) {
    string firstName = (*it)->getFirstName();
    string name = (*it)->getName();
    Sex sex = (*it)->getSex();
    m_.erase(it);
    
    pp ptr = make_shared<Employee>(firstName, name, pesel, sex, address, pay_);
    m_.push_back(ptr);

    cout << "A person modified" << endl;
  }
}


