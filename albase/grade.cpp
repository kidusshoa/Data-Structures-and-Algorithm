#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

double convertGradeToGPA(const string& grade) {
    if (grade == "A") return 4.0;
    if (grade == "A-") return 3.75;
    if (grade == "B+") return 3.5;
    if (grade == "B") return 3.0;
    if (grade == "B-") return 2.75;
    if (grade == "C+") return 2.5;
    if (grade == "C") return 2.0;
    if (grade == "C-") return 1.75;
    if (grade == "D") return 1.0;
    if (grade == "F") return 0.0;

    return -1.0; 
}

double calculateGPA(const vector<pair<string, int>>& subjects) {
    double totalGradePoints = 0.0;
    int totalCreditHours = 0;

    for (const auto& subject : subjects) {
        cout << "Enter the grade for " << subject.first << ": ";
        string grade;
        cin >> grade;

        double gradePoints = convertGradeToGPA(grade);

        if (gradePoints == -1.0) {
            cerr << "Invalid grade entered for " << subject.first << ". Please enter a valid letter grade.\n";
            return -1.0; 
        }

        totalGradePoints += gradePoints * subject.second;
        totalCreditHours += subject.second;
    }

    if (totalCreditHours == 0) {
        cerr << "Total credit hours cannot be zero.\n";
        return -1.0;  
    }

    return totalGradePoints / totalCreditHours;
}

int main() {
    vector<pair<string, int>> subjects = {
        {"Statistics", 4},
        {"OOP", 7},
        {"Database", 5},
        {"Accounting", 5},
        {"Global", 4},
        {"Data Structures", 5},
        {"COA", 5}
    };

    cout << "Welcome to the GPA Calculator!\n";
    cout << "Please enter the letter grades for the following subjects:\n";

    double gpa = calculateGPA(subjects);

    if (gpa != -1.0) {
        cout << fixed << setprecision(2);
        cout << "Your GPA is: " << gpa << endl;
    } else {
        cerr << "Error in input. Exiting program.\n";
    }

    return 0;
}
