using namespace std;

//typedef char Index[30];
typedef long int Index;

union ExtraData {
    Index index;
    float pay;
  };

enum Sex {female, male, mysterious };


class person
{
 public:
  string firstName;
  string name;
  char PESEL[11];
  Sex sex;
  string address;

  ExtraData extra;

  person(string firstName = "", string name = "");

};
