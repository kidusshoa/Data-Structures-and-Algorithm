#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int STUDENTS = 5;
const int COLUMNS = 7;

void computeAverages(float grades[STUDENTS][COLUMNS]) {
    for (int i = 0; i < STUDENTS; ++i) {
        grades[i][5] = (grades[i][1] + grades[i][2] + grades[i][3] + grades[i][4]) / 4.0;
        grades[i][6] = 0.2 * grades[i][1] + 0.3 * grades[i][2] + 0.3 * grades[i][3] + 0.2 * grades[i][4];
    }
}

void printResults(string names[STUDENTS], float grades[STUDENTS][COLUMNS]) {
    cout << left << setw(15) << "Student" 
         << setw(8) << "Grade1" 
         << setw(8) << "Grade2" 
         << setw(8) << "Grade3" 
         << setw(8) << "Grade4" 
         << setw(8) << "Avg" 
         << setw(8) << "wtdAvg" 
         << endl;

    for (int i = 0; i < STUDENTS; ++i) {
        cout << left << setw(15) << names[i]
             << setw(8) << grades[i][1]
             << setw(8) << grades[i][2]
             << setw(8) << grades[i][3]
             << setw(8) << grades[i][4]
             << setw(8) << fixed << setprecision(2) << grades[i][5]
             << setw(8) << fixed << setprecision(2) << grades[i][6]
             << endl;
    }
}

int main() {
    string names[STUDENTS];
    float grades[STUDENTS][COLUMNS] = {0};

    cout << "Enter the names and grades for " << STUDENTS << " students." << endl;

    for (int i = 0; i < STUDENTS; ++i) {
        cout << "Enter the name of student " << i+1 << ": ";
        getline(cin, names[i]);

        for (int j = 1; j <= 4; ++j) {
            cout << "Enter grade " << j << " for " << names[i] << ": ";
            cin >> grades[i][j];
        }
        cin.ignore();  // to clear the newline character from the input buffer
    }

    computeAverages(grades);
    printResults(names, grades);

    return 0;
}

/*
# The program uses a 5-by-7 two-dimensional array to store the grades and the computed averages. Additionally, it uses a separate array to store student names.
# The program takes input for each student's name and their four grades.
# The simple average is calculated by summing the four grades and dividing by 4.
# The weighted average is calculated using the specified weights (0.2, 0.3, 0.3, 0.2).
# The results are formatted and printed in a tabular format.
*/