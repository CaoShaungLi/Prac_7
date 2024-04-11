// export module person;
#ifndef _PERSON_H
#define _PERSON_H

// import <string>;
// import <format>;
// import <compare>;
#include <string>
#include <format>
#include <compare>
#include <iostream>


class Person
{
public:
	// Two-parameter constructor automatically creates initials and
	// delegates the work to the three-parameter constructor.
	Person(std::string firstName, std::string lastName);

	Person() = default;

	Person(std::string firstName, std::string lastName, std::string initials);

	const std::string& getFirstName() const;
	void setFirstName(std::string firstName);

	const std::string& getLastName() const;
	void setLastName(std::string lastName);

	const std::string& getInitials() const;
	void setInitials(std::string initials);

	//// Only this single line of code is needed to add support
	//// for all six comparison operators.
	// [[nodiscard]] auto operator<=>(const Person&) const = default;
	bool operator > (const Person& person) const;
	bool operator < (const Person& person) const;
	bool operator <= (const Person& person) const;
	bool operator >= (const Person& person) const;
	bool operator != (const Person& person) const;
	bool operator == (const Person& person) const;

private:
	std::string m_firstName;
	std::string m_lastName;
	std::string m_initials;
};

std::ostream& operator << (std::ostream& os, const Person& person);

#endif