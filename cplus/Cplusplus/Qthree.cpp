#include <iostream>
#include <string>

using namespace std;

// Define the Student structure
struct Student {
    string name;
    int id;
    int credits;
    float gpa;
};

int main() {
    Student student;

    // Accept values from the keyboard
    cout << "Enter student's name: ";
    getline(cin, student.name);

    cout << "Enter student's identification number: ";
    cin >> student.id;

    cout << "Enter number of credits completed: ";
    cin >> student.credits;

    cout << "Enter cumulative grade point average: ";
    cin >> student.gpa;

    // Display the student information
    cout << "\nStudent Information:\n";
    cout << "Name: " << student.name << endl;
    cout << "Identification Number: " << student.id << endl;
    cout << "Credits Completed: " << student.credits << endl;
    cout << "Cumulative GPA: " << student.gpa << endl;

    return 0;
}
