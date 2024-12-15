#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int maxRow = 10;

struct Student {
    string name;
    string id;
};

Student* StudentList[maxRow] = {nullptr};

void OpenFile() {
    string line;
    ifstream myfile("students.txt");
    if (myfile.is_open()) {
        int x = 0;
        while (getline(myfile, line) && x < maxRow) {
            Student* stu = new Student;
            size_t commaPos = line.find(',');
            if (commaPos != string::npos) {
                stu->id = line.substr(0, commaPos);
                stu->name = line.substr(commaPos + 1);
                StudentList[x] = stu;
                x++;
            }
        }
        myfile.close();
    } else {
        cout << "Unable to open file" << endl;
    }
}

void listStudents() {
    cout << "Current Student(s)" << endl;
    cout << "===================================" << endl;

    int counter = 0;
    cout << " No. |  ID  |     Name    |" << endl;
    cout << "-------------------------------" << endl;
    for (int x = 0; x < maxRow; x++) {
        if (StudentList[x] != nullptr) {
            counter++;
            cout << " " << counter << "    " << StudentList[x]->id << "      " << StudentList[x]->name << endl;
        }
    }
    if (counter == 0) {
        cout << "No Record found!" << endl;
    }
    cout << "=====================================" << endl;
}

void addStudent() {
    string name;
    string id;

    cout << "Student ID: ";
    getline(cin, id);
    cout << "Student Name: ";
    getline(cin, name);

    for (int x = 0; x < maxRow; x++) {
        if (StudentList[x] == nullptr) {
            Student* stu = new Student;
            stu->id = id;
            stu->name = name;
            StudentList[x] = stu;
            cout << "Student added successfully!" << endl;
            return; 
        }
    }
    cout << "Cannot add more students. Maximum limit reached." << endl;
}

void SaveToFile() {
    ofstream myfile("students.txt");
    if (!myfile) {
        cout << "Unable to open file for writing" << endl;
        return;
    }

    for (int x = 0; x < maxRow; x++) {
        if (StudentList[x] != nullptr) {
            myfile << StudentList[x]->id << "," << StudentList[x]->name << endl;
        }
    }
    myfile.close();
    cout << "Students saved to file successfully!" << endl;
}



int main() {
    OpenFile();
    // listStudents();
    addStudent();
    SaveToFile();
   
    return 0;
}