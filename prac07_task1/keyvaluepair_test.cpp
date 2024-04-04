#include <iostream>
#include <string>
#include "KeyValuePair.h"

using namespace std;

int main()
{
    KeyValuePair<string, int> namePhonenum("Katie", 123456);
    cout << "Name: " << namePhonenum.getKey() << endl;
    cout << "Phone Num: " << namePhonenum.getValue() << endl;
    namePhonenum.setKey("Mary");
    cout << "Name modified: " << namePhonenum.getKey() << endl;
    namePhonenum.setValue(78910);
    cout << "Phone num modified: " << namePhonenum.getValue() << endl;
    return 0;
}
