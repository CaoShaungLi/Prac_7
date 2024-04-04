#include "Person.h"
#include <string>

Person::Person(std::string firstName, std::string lastName)
    : Person{
          //  std::move(firstName), std::move(lastName),
          firstName, lastName,
          firstName.substr(0, 1) + lastName.substr(0, 1)
          // std::format("{}{}", firstName[0], lastName[0])
      }
{
}

Person::Person(std::string firstName, std::string lastName, std::string initials)
    : m_firstName{firstName}, m_lastName{lastName}, m_initials{initials}
{
}

const std::string &Person::getFirstName() const
{
    return m_firstName;
}
void Person::setFirstName(std::string firstName)
{
    m_firstName = firstName;
}

const std::string &Person::getLastName() const
{
    return m_lastName;
}
void Person::setLastName(std::string lastName)
{
    m_lastName = lastName;
}

const std::string &Person::getInitials() const
{
    return m_initials;
}

void Person::setInitials(std::string initials)
{
    m_initials = initials;
}


bool Person::operator >(const Person& person) const
{
    if (this->m_lastName > person.getLastName())
    {
        return true;
    }
    else if (this->m_lastName < person.getLastName())
    {
        return false;
    }
    else
    {
        return this->m_firstName > person.getFirstName();
    }
}

bool Person::operator < (const Person& person) const
{
    if (this->m_lastName < person.getLastName())
    {
        return true;
    }
    else if (this->m_lastName > person.getLastName())
    {
        return false;
    }
    else
    {
        return this->m_firstName < person.getFirstName();
    }
}

bool Person::operator <= (const Person& person) const
{
    if (this->m_lastName <= person.getLastName())
    {
        return true;
    }
    else if (this->m_lastName >= person.getLastName())
    {
        return false;
    }
    else
    {
        return this->m_firstName <= person.getFirstName();
    }
}

bool Person::operator >= (const Person& person) const
{
    if (this->m_lastName >= person.getLastName())
    {
        return true;
    }
    else if (this->m_lastName <= person.getLastName())
    {
        return false;
    }
    else
    {
        return this->m_firstName >= person.getFirstName();
    }
}

bool Person::operator == (const Person& person) const
{
    if (this->m_lastName == person.getLastName())
    {
        return true;
    }
    else if (this->m_lastName != person.getLastName())
    {
        return false;
    }
    else
    {
        return this->m_firstName == person.getFirstName();
    }
}

bool Person::operator != (const Person& person) const
{
    if (this->m_lastName != person.getLastName())
    {
        return true;
    }
    else if (this->m_lastName == person.getLastName())
    {
        return false;
    }
    else
    {
        return this->m_firstName != person.getFirstName();
    }
}

std::ostream& operator << (std::ostream& os, const Person& person)
{
    os << person.getFirstName()+" "+ person.getLastName()+" "+ person.getInitials();
    return os;
}
