#include <iostream>
#include <vector>

using namespace std;
int main()
{
    vector<int> values{2, 5};

    values.insert(begin(values) + 1, 3);
    values.insert(begin(values) + 2, 4);

    for (const int& value : values)
    {
        cout << value << " ";
    }
    cout << endl;



    vector<int> secondVector{0, 1};
    values.insert(begin(values), cbegin(secondVector), cend(secondVector));

     for (const int& value : values)
    {
        cout << value << " ";
    }
    cout << endl;



    vector<int> thirdVector;
    for (vector<int>::const_reverse_iterator i{crbegin(values)}; i != crend(values); ++i)
    {
        thirdVector.push_back(*i);
    }

    for (const int& value : thirdVector)
    {
        cout << value << " ";
    }
    cout << endl;

    

    return 0;
}