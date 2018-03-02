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
        pp ptr =
          make_shared<Student>(firstName, name, pesel, Sex(sex), address, number);
        m.push_back(ptr);
      }
      if (occupation == "Employee") {
        pp ptr = make_shared<Employee>(
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
    for (auto p : m) {
      file << p->occupation() << "  " << p->get_firstName() << "  "  << p->get_name()  << "  " 
           << p->get_pesel() << "  " << p->get_sex() << "  " << p->get_address() << "  " << p->number() << endl;
      file.flush();
    };
    file.close();
  };
}

void
Persons::show()
{
  cout << "Database:" << endl;
  for (auto p : m) 
    p->show();
  cout << endl;
}

pp
Persons::findPersonPesel(string peselNumber)
{
  auto it = find_if(m.begin(), m.end(), [peselNumber] (const pp p) { return p->get_pesel() == peselNumber;});
  if (it != m.end()) {
    cout << "Found Person:" << endl;
    (*it)->show();
  }
  else 
    cout << "PESEL not found!" << endl;
  return *it;
}

pp
Persons::findPersonSurname(string surname)
{
  auto it = find_if(m.begin(), m.end(), [surname] (const pp p) { return p->get_name() == surname;});
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
  auto it = find_if(m.begin(), m.end(), [peselNumberOfErase] (const pp p) { return p->get_pesel() == peselNumberOfErase;});
  if (it != m.end()) {
    m.erase(it);
    cout << "A person deleted" << endl;
  }
  else 
    cout << "PESEL not found!" << endl;
}


//5. Wypełnianie bazy danych sztucznymi danymi (std::generate, std::fill) 
string 
randomString(const unsigned int len)
{
   string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
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
            return make_shared<Student>(randomString(5), randomString(9), randomString(11), randomSex(), randomString(5), rand()); 
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
  sort(m.begin(), m.end(), [](pp p1, pp p2) {
        return p1->get_pesel() < p2->get_pesel();   
  });
}

void
Persons::sortName() 
{
  sort(m.begin(), m.end(), [](pp p1, pp p2) {
        return p1->get_name() < p2->get_name();   
  });
}

void
Persons::sortPay() 
{
  sort(m.begin(), m.end(), [](pp p1, pp p2) {
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
  auto it = find_if(m.begin(), m.end(), [pesel] (const pp p) { return p->get_pesel() == pesel;});
  if (it != m.end()) {
    string firstName = (*it)->get_firstName();
    string name = (*it)->get_name();
    Sex sex = (*it)->get_sex();
    m.erase(it);
    
    pp ptr = make_shared<Employee>(firstName, name, pesel, sex, address, pay_);
    m.push_back(ptr);

    cout << "A person modified" << endl;
  }
}


