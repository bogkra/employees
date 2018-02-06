#ifndef main_h
#define main_h

using namespace std;

//typedef char Index[30];
//typedef long int Index;

/*union ExtraData {
    Index index;
    float pay;
  };
*/
//enum Sex {female, male, mysterious };


class Person
{
  public:
  Person(string firstName, string name, string pesel, string address) :
	  firstName(firstName),
	  name(name),
	  pesel(pesel),
	  address(address) 
  {}
  string firstName;
  string name;
  string pesel;
  //Sex sex;
  string address;
  virtual int number()=0;
};

class Student : public Person
{
	public:
 Student(string firstName, string name, string pesel, string address, int number_index) :
	 Person(firstName,name,pesel,address),
	 number_index(number_index)
 {}
 int number_index;
 int number()
 {
	return number_index;	
 }
};

class Worker : public Person
{
	public:
	Worker(string firstName, string name, string pesel, string address, int pay) :
	 Person(firstName,name,pesel,address),
	 pay(pay)
 {}
	int pay;
 int number()
 {
	return pay;
 }
};

#endif
