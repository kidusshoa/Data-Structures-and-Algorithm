#include <iostream>
using namespace std;

struct Address {
    string street;
    string city;
    string state;
    int zipCode;
};

struct Person {
    string name;
    int age;
    Address address;
};

int main() {
    Person person1;
    person1.name = "kidus";
    person1.age = 21;
    person1.address.street = "Sefer selam";
    person1.address.city = "Hawassa";
    person1.address.state = "Sidama Region";
    person1.address.zipCode = 1007;

    cout << "Person 1:" << endl;
    cout << "Name: " << person1.name << endl;
    cout << "Age: " << person1.age << endl;
    cout << "Address: " << endl;
    cout << "Street: " << person1.address.street << endl;
    cout << "City: " << person1.address.city << endl;
    cout << "State: " << person1.address.state << endl;
    cout << "Zip Code: " << person1.address.zipCode << endl;

    return 0;
}