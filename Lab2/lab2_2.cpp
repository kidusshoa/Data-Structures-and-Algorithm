#include <iostream>
using namespace std;

// Union example
union MyUnion {
    int intValue;
    float floatValue;
    char charValue;
};

// Typedef example
typedef int MyInt;

// Enumeration example
enum Day { MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY };

int main() {
    // Union usage
    MyUnion u;
    u.intValue = 10;
    cout << "Value of intValue: " << u.intValue << endl;
    u.floatValue = 3.14;
    cout << "Value of floatValue: " << u.floatValue << endl;
    u.charValue = 'A';
    cout << "Value of charValue: " << u.charValue << endl;

    // Typedef usage
    MyInt x = 5;
    cout << "Value of x: " << x << endl;

    // Enumeration usage
    Day today = SATURDAY;
    cout << "Today is day number: " << today << endl;

    return 0;
}