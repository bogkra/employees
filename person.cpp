#include "person.hpp"

Person::Person(string firstName,
               string name,
               string pesel,
               Sex sex,
               string address)
  : firstName(firstName)
  , name(name)
  , pesel(pesel)
  , sex(sex)
  , address(address)
{
}
