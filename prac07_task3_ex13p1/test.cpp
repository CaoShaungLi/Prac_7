// import person;
// import <iostream>;
// import <format>;

#include "Person.h"
#include <iostream>
#include <format>

using namespace std;

int main()
{
	Person person { "John", "Doe" };
	cout << person << endl;

	Person person2 { "Marc", "Gregoire", "Mg" };
	cout << person2 << endl;

	Person persons[3];

	// Test copy constructor.
	Person copy { person };

	// Test assignment operator.
	Person otherPerson { "Jane", "Doe" };
	copy = otherPerson;

	// Test comparison operators.
	if (person < person2) { cout << "person < person2" << endl; }
	if (person > person2) { cout << "person > person2" << endl; }
	if (person <= person2) { cout << "person <= person2" << endl; }
	if (person >= person2) { cout << "person >= person2" << endl; }
	if (person == person2) { cout << "person == person2" << endl; }
	if (person != person2) { cout << "person != person2" << endl; }
}
