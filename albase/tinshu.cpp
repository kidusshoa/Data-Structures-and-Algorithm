#include <iostream>

using namespace std;

struct Student {
    int studentID;
    string studentName;
    string studentAddress;
    char gender;
    int age;
};

void displayGrade(int total) {
    switch (total) {
        case 90 ... 100:
            cout << "A+";
            break;
        case 85 ... 89:
            cout << "A";
            break;
        case 80 ... 84:
            cout << "A-";
            break;
        case 70 ... 79:
            cout << "B+";
            break;
        case 65 ... 69:
            cout << "B";
            break;
        case 60 ... 64:
            cout << "B-";
            break;
        case 55 ... 59:
            cout << "C+";
            break;
        case 50 ... 54:
            cout << "C";
            break;
        case 45 ... 49:
            cout << "C-";
            break;
        case 40 ... 44:
            cout << "D";
            break;
        case 30 ... 39:
            cout << "F";
            break;
        default:
            cout << "Score too low";
            break;
    }
    cout << endl;
}
void display2DArray() {
    int abc=0;
    int arr[1][5];
    cout << "\t\t\t\t\tEnter 5 numbers \n";
    for (int i = 0; i < 5; i++) {
      cout << "\t\t\t\t\tPlease the numbers: ";
        cout << "";
         
        cin >> arr[abc][i] ;
        
    }
    cout <<"\n";
    cout << "\t\t\t\t\t**************************\n\n";
    cout << "\t\t\t\t\t2D Array:\n";
    for (int i = 0; i < 5; i++) {
        cout << "\t\t\t\t\t"; 
        cout << arr[abc][i] << "\n";
    }
}


void displayStudentInfo() {
    Student student;

    cout << "\t\t\t\t\tEnter Student ID: ";
    cin >> student.studentID;
    cout << "\t\t\t\t\tEnter Student Name: ";
    cin >> student.studentName;
    cout << "\t\t\t\t\tEnter Gender: ";
    cin >> student.gender;
    cout << "\t\t\t\t\tEnter Student Address: ";
    cin >> student.studentAddress;
    cout << "\t\t\t\t\tEnter Age: ";
    cin >> student.age;
    
    
    cout << "\t\t\t\t\t\n";
    cout << "\t\t\t\t\t************************\n";
    cout << "\t\t\t\t\tStudent Information:\n";
    cout << "\t\t\t\t\t************************\n\n";
    cout << "\t\t\t\t\tStudent ID: " << student.studentID << "\n";
    cout << "\t\t\t\t\tStudent Name: " << student.studentName << "\n";
    cout << "\t\t\t\t\tGender: " << student.gender << "\n";
    cout << "\t\t\t\t\tStudent Address: " << student.studentAddress << "\n";
    cout << "\t\t\t\t\tAge: " << student.age << "\n";
}


int main() {
  int total;
    char choice;
    do {
      cout << "\n\n\t\t\t\t\t\t---------------------------\n";
        cout << "\t\t\t\t\t\t\t   Menu\n";
        cout << "\t\t\t\t\t\t---------------------------\n\n";
        cout << "\t\t\t\t\t\ta: Display Grade Level\n";
        cout << "\t\t\t\t\t\tb: Display 2D Array\n";
        cout << "\t\t\t\t\t\tc: Display Student Information\n";
        cout << "\t\t\t\t\t\td: Close Program\n\n";
        cout << "\t\t\t\t\t\tEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 'a':
                cout << "\t\t\t\t\t\tEnter total marks: ";
                cin >> total;
                cout << "\t\t\t\t\t\tGrade: "<< endl;
                 displayGrade( total);
                break;
            case 'b':
                display2DArray();
                break;       
        case 'c':
                displayStudentInfo();
                break;
            case 'd':
                cout << "\t\t\t\t\tClosing Program...\n";
                break;
            default:
                cout << "\t\t\t\t\tInvalid choice. Please try again.\n";
        }
    } while (choice != 'd');
    system ("pause>0");
   return 0;
}