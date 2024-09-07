#include <iostream>
#include <string>

using namespace std;

// Structure for date of birth
struct Date {
    int day;
    int month;
    int year;
};

// Structure for student information
struct Student {
    string name;
    int id;
    int credits_completed;
    float gpa;
    Date dob; // Nested structure for date of birth
};

int main() {
    Student student;

    // Accept values from the keyboard
    cout << "Enter student's name: ";
    getline(cin, student.name);

    cout << "Enter student's identification number: ";
    cin >> student.id;

    cout << "Enter number of credits completed: ";
    cin >> student.credits_completed;

    cout << "Enter cumulative grade point average: ";
    cin >> student.gpa;

    cout << "Enter date of birth (DD MM YYYY): ";
    cin >> student.dob.day >> student.dob.month >> student.dob.year;

    // Display the student information
    cout << "\nStudent Information:\n";
    cout << "Name: " << student.name << endl;
    cout << "Identification Number: " << student.id << endl;
    cout << "Credits Completed: " << student.credits_completed << endl;
    cout << "Cumulative GPA: " << student.gpa << endl;
    cout << "Date of Birth: " << student.dob.day << "/" << student.dob.month << "/" << student.dob.year << endl;

    return 0;
}
