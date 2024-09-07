#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int maxrow = 10;

string EmpName[maxrow] = {};
string EmpID[maxrow] = {};

void OpenFile(){
    string line;
    ifstream myfile("test.txt");
    if(myfile.is_open()){
        int x = 0;
        while (getline(myfile, line)){
            int l = line.length();
            EmpID[x]=line.substr(0, 3);
            EmpName[x]=line.substr(4, 1-4);
            x++;
    }
}
else{
    cout << "Unable to open file"<<endl;
}}

void AddRecord(){
    char name[50];
    char empno[5];

    cin.ignore();
    cout << "Employee ID. ";
    cin.getline(empno, 5);
    cout << "Employee Name. ";
    cin.getline(name, 50);

    for (int x = 0; x < maxrow; x++){
        if(EmpID[x] == "\0"){
            EmpID[x] = empno;
            EmpName[x] = name;

            break;
        }
    }
}

void ListRecord(){
    cout << "Current Record(s)"<< endl;
    cout << "==================================="<< endl;

    int counter = 0;
    cout << " No. |  ID  |     Name    | "<<endl;
    cout << "-------------------------------\n";
    for (int x = 0; x < maxrow; x++){
        if (EmpID[x] != "\0"){
            counter++;
            cout << " "<<counter<<"    "<<EmpID[x]<<"      "<<EmpName[x]<<endl;  
    }
    }
    if (counter == 0){
        cout<< "No Record found!"<<endl;
    }
     cout<<"====================================="<<endl;
}

void SearchRecord( string search){
    cout << "Current Record(s)"<< endl;
    cout << "==================================="<< endl;   
    int counter = 0;
    for (int x = 0; x < maxrow; x++){
        
        if (EmpID[x] == search){
            counter++;
            cout << " "<<counter<<"    "<<EmpID[x]<<"      "<<EmpName[x]<<endl;
            break;  
    }
}
if (counter == 0){
        cout<< "No Record found!"<<endl;
    }

    cout<<"====================================="<<endl;
}

void UpdateRecord(string search){
    char name[50];
    char empno[5];

    int counter = 0;

    for (int x = 0; x < maxrow; x++){
        if (EmpID[x] == search){
            counter++;
            cout << "Employee Name. ";
            cin.getline(name, 50);
            
            EmpName[x] = name;

            cout<<"Updated Successfully!"<<endl;

            break;
    
    }
}
if (counter == 0){
    cout<< "No Record found!"<<endl;
}
}

void DeleteRecord(string search){
    int counter = 0;

    for (int x = 0; x < maxrow; x++){
        if (EmpID[x] == search){
            counter++;
            EmpID[x] = "";
            EmpName[x] = "";

            cout<<"Deleted Successfully!"<<endl;

            break;
    
    }
    
    if(counter == 0){
        cout<<"ID Number Does Not Exist!"<<endl;
    }
} 
cout<<"================================"<<endl;
}

void SaveToFile(){
    ofstream myfile;
    myfile.open("test.txt");
    
        for (int x = 0; x < maxrow; x++){
            if(EmpID[x] == "\0"){
                break;
        }
    
    else{
        myfile << EmpID[x] + "," + EmpName[x] <<endl;
    }}
}


int main(){
    cout<<"Menu\n";
    int option;
    string empID;
    OpenFile();
    cout<<"--------------------------\n";
    do {
        cout<<"1-Create Records"<<endl;
        cout<<"2-Update Records"<<endl;
        cout<<"3-Delete Records"<<endl;
        cout<<"4-Search Records"<<endl;
        cout<<"5-Display all Records"<<endl;
        cout<<"6-Save and Exit"<<endl;
        cout<<"==============================="<<endl;

        cout<<"Select option >> ";
        cin>>option;

        switch (option){
            case 1: AddRecord();

            break;

            case 2:
            cin.ignore();
            cout << "Search by ID >> ";
            getline(cin, empID);
            UpdateRecord(empID);
            break;

            case 3:
            cin.ignore();
            cout<< "Delete by ID >> ";
            getline(cin, empID);
            DeleteRecord(empID);
    
            break;

            case 4:
            cin.ignore();
            cout << "Search by ID >> ";
            getline(cin, empID);
            SearchRecord(empID);
            break;

            case 5: ListRecord();

            break;
        }
    }while (option !=6);
    SaveToFile();
    cout<<"Existing and Saving records..."<<endl;
    return 0;

}