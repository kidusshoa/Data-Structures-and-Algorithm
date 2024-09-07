#include <iostream>
#include <cstdlib>
#include "LL2.cpp"
//#include "LL1.cpp"
using namespace std;
int main() {
    while (true) {
        cout << "Menu for SLL basic operations" << endl;
        cout << "Press 1 to create a new node" << endl;
        cout << "Press 2 to display the SLL info" << endl;
        cout << "Press 3 to insert a newnode at the head of the SLL" << endl;
        cout << "Press 4 to insert a new node at the tail of the SLL" << endl;
        cout << "Press 5 to insert a new node at a specific position in the SLL" << endl;
        cout << "Press 6 to delete a node from the SLL" << endl;
        cout << "Press 7 to delete a node from the tail" << endl;
        cout << "Press 8 to delete a node from the any position" << endl;
        cout << "Press 0 to exit the program" << endl;
      
int ch;
        cout << "Enter your choice: ";
        cin >> ch;
switch (ch) {
    case 1:
        createnewnode();
        break;
    case 2:
        displayll();
        break;
    case 3:
        insertnewnodeathead();
        break;
    case 4:
        insertnewnodeattail();
        break;
    case 5:
        insertnewnodeatanypos();
        break;
    case 6:
        deletenode();
        break;
    case 7:
        deletenewnodefromtail();
        break;
    case 8:
        deletenewnodefromanypos();
        break;
    case 0:
        exit(0);
    default:
        cout << "Invalid choice. Please enter again." << endl;
}
        
    }
}