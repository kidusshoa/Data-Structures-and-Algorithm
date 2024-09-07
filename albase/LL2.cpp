
#include <iostream>
#include <cstdlib>

using namespace std;

struct studentnode {
    string name;
    int id;
    double gpa;
    studentnode* next;
};

studentnode* startptr = NULL;

void displayll() {
    if (startptr == NULL) {
        cout << "SLL is empty" << endl;
    } else {
        studentnode* temp = startptr;
        cout << "startptr->";
        while (temp != NULL) {
            cout << "|" << temp->name << ":" << temp->id << ":" << temp->gpa << "|->";
            temp = temp->next;
        }
        cout << endl;
    }
}

void createnewnode() {
    studentnode* newnode = new studentnode;
    cout << "Enter name: ";
    cin >> newnode->name;
    cout << "Enter ID: ";
    cin >> newnode->id;
    cout << "Enter GPA: ";
    cin >> newnode->gpa;
    newnode->next = NULL;

    if (startptr == NULL) {
        startptr = newnode;
        cout << "New node is created successfully." << endl;
    } else {
        studentnode* temp = startptr;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
        cout << "New node is inserted successfully." << endl;
    }
}

void insertnewnodeathead() {
    studentnode* newnode = new studentnode;
    cout << "Enter name: ";
    cin >> newnode->name;
    cout << "Enter ID: ";
    cin >> newnode->id;
    cout << "Enter GPA: ";
    cin >> newnode->gpa;
    newnode->next = NULL;

    if (startptr == NULL) {
        startptr = newnode;
        cout << "New node is inserted at the head of SLL successfully." << endl;
    } else {
        newnode->next = startptr;
        startptr = newnode;
        cout << "New node is inserted at the head of SLL successfully." << endl;
    }
}

void insertnewnodeattail() {
    studentnode* newnode = new studentnode;
    cout << "Enter name: ";
    cin >> newnode->name;
    cout << "Enter ID: ";
    cin >> newnode->id;
    cout << "Enter GPA: ";
    cin >> newnode->gpa;
    newnode->next = NULL;
    if (startptr == NULL) {
        startptr = newnode;
        cout << "New node is inserted at the tail of SLL successfully." << endl;
    } else {
        studentnode* temp = startptr;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
        cout << "New node is inserted at the tail of SLL successfully." << endl;
    }
}

void insertnewnodeatanypos() {
    studentnode* newnode = new studentnode;
    cout << "Enter name: ";
    cin >> newnode->name;
    cout << "Enter ID: ";
    cin >> newnode->id;
    cout << "Enter GPA: ";
    cin >> newnode->gpa;
    newnode->next = NULL;

    if (startptr == NULL) {
        startptr = newnode;
        cout << "New node is inserted at the tail of SLL successfully." << endl;
    } else {
        studentnode* temp = startptr;
        int count = 0, pos;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        cout << "Enter position (1-" << count << "): ";
        cin >> pos;
        
        if (pos >= 1 && pos <= count) {
            studentnode* temp1 = startptr;
            studentnode* temp2;

            for (int i = 1; i < pos; i++) {
                temp1 = temp1->next;
            }
            
            temp2 = temp1->next;
            temp1->next = newnode;
            newnode->next = temp2;
            
            cout << "New node is inserted at position " << pos << " of SLL successfully." << endl;
        } else {
            cout << "Invalid position. Please enter a valid position." << endl;
        }
    }
}


void deletenode() {
    if (startptr == NULL) {
        cout << "SLL is empty. No nodes to delete." << endl;
    } else {
        int id;
        cout << "Enter ID of the node to be deleted: ";
        cin >> id;

        if (startptr->id == id) {
            studentnode* temp = startptr;
            startptr = startptr->next;
            delete temp;
            cout << "Node with ID " << id << " is deleted successfully." << endl;
        } else {
            studentnode* temp = startptr->next;
            studentnode* prev = startptr;
            while (temp != NULL) {
                if (temp->id == id) {
                    prev->next = temp->next;
                    delete temp;
                    cout << "Node with ID " << id << " is deleted successfully." << endl;
                    return;
                } else {
                    prev = temp;
                    temp = temp->next;
                }
            }
            cout << "Node with ID " << id << " does not exist in the SLL." << endl;
        }
    }
}

void deletenewnodefromtail(){
    if(startptr == NULL){
        cout<<"SLL is empty\n";
    }else{
        studentnode* temp = startptr, *temp2;
        if(startptr->next == NULL){
            startptr = NULL;
            delete temp;
            cout<<"Deleted node succesfully from tail"<< endl;
            displayll();
        }
    else{
        while(temp->next != NULL){
            temp2=temp;
            temp=temp->next;
        }
        temp2->next = NULL;
        delete temp;
        cout<<"Deleted node successfully from tail\n";
        displayll();
    }
}}

void deletenewnodefromanypos(){
    studentnode* current=startptr;
    int c=0, pos;
    while(current!=NULL){
        c++;
        current=current->next;
    }
    cout<<"which node do u want to delete = ";
    cin>>pos;
    if(pos>1&&pos<c){
        studentnode* temp1= startptr, *temp2=startptr, *temp3;
        for(int i=1; i<=pos; i++){
            temp3=temp2;
            temp2=temp1;
            temp1=temp1->next;
        }
        temp3->next=temp1;
        delete temp2;
        cout<<"deleted node successfully\n";
        displayll();
    }else{
        cout<<"few or out of range"<<endl;
    }
}
