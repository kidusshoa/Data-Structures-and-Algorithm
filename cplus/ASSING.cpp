#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int maxrow = 10;

struct Employee {
    string EmpName;
    string EmpID;
};

Employee* EmpRecords[maxrow];

void OpenFile() {
    string line;
    ifstream myfile("data.txt");
    if (myfile.is_open()) {
        int x = 0;
        while (getline(myfile, line)) {
            int l = line.length();
            Employee* emp = new Employee;
            emp->EmpID = line.substr(0, 3);
            emp->EmpName = line.substr(4, l - 4);
            EmpRecords[x] = emp;
            x++;
        }
    }
    else {
        cout << "Unable to open file" << endl;
    }
}

void AddRecord() {
    string name;
    string empno;

    cin.ignore();
    cout << "Employee ID: ";
    getline(cin, empno);
    cout << "Employee Name: ";
    getline(cin, name);

    for (int x = 0; x < maxrow; x++) {
        if (EmpRecords[x] == nullptr) {
            Employee* emp = new Employee;
            emp->EmpID = empno;
            emp->EmpName = name;
            EmpRecords[x] = emp;
            break;
        }
    }
}

void ListRecord() {
    cout << "Current Record(s)" << endl;
    cout << "===================================" << endl;

    int counter = 0;
    cout << " No. |  ID  |     Name    | " << endl;
    cout << "-------------------------------\n";
    for (int x = 0; x < maxrow; x++) {
        if (EmpRecords[x] != nullptr) {
            counter++;
            cout << " " << counter << "    " << EmpRecords[x]->EmpID << "      " << EmpRecords[x]->EmpName << endl;
        }
    }
    if (counter == 0) {
        cout << "No Record found!" << endl;
    }
    cout << "=====================================" << endl;
}

void SearchRecord(string search) {
    cout << "Current Record(s)" << endl;
    cout << "===================================" << endl;
    int counter = 0;
    for (int x = 0; x < maxrow; x++) {
        if (EmpRecords[x] != nullptr && EmpRecords[x]->EmpID == search) {
            counter++;
            cout << " " << counter << "    " << EmpRecords[x]->EmpID << "      " << EmpRecords[x]->EmpName << endl;
            break;
        }
    }
    if (counter == 0) {
        cout << "No Record found!" << endl;
    }
    cout << "=====================================" << endl;
}

void UpdateRecord(string search) {
    string name;

    int counter = 0;

    for (int x = 0; x < maxrow; x++) {
        if (EmpRecords[x] != nullptr && EmpRecords[x]->EmpID == search) {
            counter++;
            cout << "Employee Name: ";
            getline(cin, name);

            EmpRecords[x]->EmpName = name;

            cout << "Updated Successfully!" << endl;

            break;
        }
    }
    if (counter == 0) {
        cout << "No Record found!" << endl;
    }
}

void DeleteRecord(string search) {
    int counter = 0;

    for (int x = 0; x < maxrow; x++) {
        if (EmpRecords[x] != nullptr && EmpRecords[x]->EmpID == search) {
            counter++;
            delete EmpRecords[x];
            EmpRecords[x] = nullptr;

            cout << "Deleted Successfully!" << endl;

            break;
        }
    }
    if (counter == 0) {
        cout << "ID Number Does Not Exist!" << endl;
    }
}

void SaveToFile() {
    ofstream myfile;
    myfile.open("data.txt");

    for (int x = 0; x < maxrow; x++) {
        if (EmpRecords[x] == nullptr) {
            break;
        }
        else {
            myfile << EmpRecords[x]->EmpID + "," + EmpRecords[x]->EmpName << endl;
        }
    }
    myfile.close();
}

int main() {
    cout << "Employee Management System\n";
    int option;
    string empID;
    OpenFile();
    cout << "--------------------------\n";
    do {
        cout << "1-Create Records" << endl;
        cout << "2-Update Records" << endl;
        cout << "3-Delete Records" << endl;
        cout << "4-Search Records" << endl;
        cout << "5-Display all Records" << endl;
        cout << "6-Save and Exit" << endl;
        cout << "===============================" << endl;

        cout << "Select option >> ";
        cin >> option;

        switch (option) {
        case 1:
            AddRecord();

            break;

        case 2:
            cin.ignore();
            cout << "Search by ID >> ";
            getline(cin, empID);
            UpdateRecord(empID);
            break;

        case 3:
            cin.ignore();
            cout << "Delete by ID >> ";
            getline(cin, empID);
            DeleteRecord(empID);

            break;

        case 4:
            cin.ignore();
            cout << "Search by ID >> ";
            getline(cin, empID);
            SearchRecord(empID);
            break;

        case 5:
            ListRecord();

            break;
        }
    } while (option != 6);
    SaveToFile();
    cout << "Existing and Saving records..." << endl;
    return 0;
}