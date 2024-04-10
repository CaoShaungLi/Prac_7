#include <iostream>
#include <fstream>
#include <string>
#include <string_view>

using namespace std;

// Returns false on error
void changeNumberForID(string_view filename, int id, string_view newNumber);

int main()
{
	try
	{
		changeNumberForID("data.txt", 263, "415-555-3333");
	}
	catch (const exception& e) 
		{
			cerr << "Exception occured: " << e.what() << endl;
		}
	return 0;
}

void changeNumberForID(string_view filename, int id, string_view newNumber)
{
	fstream ioData{filename.data()};
	if (!ioData)
	{
		throw runtime_error ("Error while opening file " + string(filename));
	}
	// {
	// 	cerr << "Error while opening file " << filename << endl;
	// 	return false;
	// }

	// Loop until the end of file
	while (ioData)
	{
		// Read the next ID.
		int idRead;
		ioData >> idRead;
		if (!ioData)
			break;

		// Check to see if the current record is the one being changed.
		if (idRead == id)
		{
			// Seek the write position to the current read position.
			// ioData.seekp(ioData.tellg());
			ioData.seekp(-1, ios::beg);
			if (!ioData)
			{
				throw runtime_error ("Unable to seek write position to current read position ");
			}
		
			// Output a space, then the new number.
			ioData << " " << newNumber;
			if (!ioData)
			{
				throw runtime_error ("Unable to write " + string(newNumber));
			}
			break;
		}

		// Read the current number to advance the stream.
		string number;
		ioData >> number;
		if (!ioData) {
			throw runtime_error{ "Unable to read next number from the input stream." };
		}
	}
}