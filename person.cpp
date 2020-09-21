#include"Person.h"
Person &Person::operator=(Person &person)
{
    name = person.name;
    phone = person.phone;
    return *this;
}

bool Person :: operator==(Person &person)
{
    if (this->name == person.name&&this->phone == person.phone)
    {
        return true;
    }
    return false;
}

 ostream &operator<<(ostream &out, Person &person)
{
     out << person.name << "---------" << person.phone << endl;
     return out;
}
