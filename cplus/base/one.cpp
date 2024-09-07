#include <iostream>
#include <stdexcept>
#include <string>
#include <cstdlib>
using namespace std;

#include "two.cpp"
#include "three.cpp"

// Artwork structure
struct Artwork {
    string artist;
    string nationality;
    int age;
};

// question-1 declaring a node structure 
struct Node {
    Artwork data;
    Node* prev;
    Node* next;
};

// question-1 Function to create a new node
Node* createNode(const Artwork& value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

// question-2 displaying forward
void displayForward(Node* head) {
    Node* current = head;
    cout << "Art Collection (Forward):\n";
    while (current != nullptr) {
        cout << "Artist: " << current->data.artist << ", Nationality: " << current->data.nationality
             << ", Age: " << current->data.age << endl;
        current = current->next;
    }
    cout << endl;
}

// question-2 displaying backward
void displayBackward(Node* head) {
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    cout << "Art Collection (Backward):\n";
    while (current != nullptr) {
        cout << "Artist: " << current->data.artist << ", Nationality: " << current->data.nationality
             << ", Age: " << current->data.age << endl;
        current = current->prev;
    }
    cout << endl;
}

// question-3 insert a new node at the head
Node* insertAtHead(Node* head, const Artwork& value) {
    Node* newNode = createNode(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    displayForward(head);
    return head;
}

// question-4 insert a new node at the tail
Node* insertAtTail(Node* head, const Artwork& value) {
    Node* newNode = createNode(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
    displayForward(head);
    return head;
}

// question-5 insert a new node at nth position
Node* insertAtNthPosition(Node* head, const Artwork& value, int position) {
    if (position <= 0) {
        throw invalid_argument("Invalid position. Position should be a positive integer.");
    }

    Node* newNode = createNode(value);
    if (position == 1) {
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
    } else {
        Node* current = head;
        for (int i = 1; i < position - 1 && current != nullptr; ++i) {
            current = current->next;
        }
        if (current == nullptr) {
            throw out_of_range("Invalid position. Position exceeds the size of the list.");
        }
        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != nullptr) {
            current->next->prev = newNode;
        }
        current->next = newNode;
    }
    displayForward(head);
    return head;
}

// question-6 delete a node from the head
Node* deleteFromHead(Node* head) {
    if (head == nullptr) {
        throw underflow_error("List is empty. Nothing to delete.");
    }
    Node* temp = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    }
    delete temp;
    displayForward(head);
    return head;
}

// question-7 delete a node from the tail
Node* deleteFromTail(Node* head) {
    if (head == nullptr) {
        throw underflow_error("List is empty. Nothing to delete.");
    }
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    if (current->prev != nullptr) {
        current->prev->next = nullptr;
    } else {
        head = nullptr;
    }
    delete current;
    displayForward(head);
    return head;
}

// question-8 delete a node from nth position
Node* deleteFromNthPosition(Node* head, int position) {
    if (head == nullptr || position <= 0) {
        throw underflow_error("List is empty or invalid position.");
    }
    Node* current = head;
    for (int i = 1; i < position && current != nullptr; ++i) {
        current = current->next;
    }
    if (current == nullptr) {
        throw out_of_range("Invalid position. Position exceeds the size of the list.");
    }
    if (current->prev != nullptr) {
        current->prev->next = current->next;
    } else {
        head = current->next;
    }
    if (current->next != nullptr) {
        current->next->prev = current->prev;
    }
    delete current;
    displayForward(head);
    return head;
}

// question-9 search for a node by artist
void searchNodeByArtist(Node* head, const string& artist) {
    Node* current = head;
    int position = 1;
    while (current != nullptr) {
        if (current->data.artist == artist) {
            cout << "Artwork found at position " << position << endl;
            return;
        }
        current = current->next;
        position++;
    }
    cout << "Artwork by artist " << artist << " not found." << endl;
}

// Bubble Sort function by artist name
Node* sortArtCollection(Node* head) {
    if (head == nullptr) {
        cout << "Art collection is empty. Nothing to sort." << endl;
        return head;
    }

    Node* i, *j;
    for (i = head; i != nullptr; i = i->next) {
        for (j = i->next; j != nullptr; j = j->next) {
            if (i->data.artist > j->data.artist) {
                swap(i->data, j->data);
            }
        }
    }
    displayForward(head);
    return head;
}

int main() {
    Node* artCollection = nullptr;

    int choice;
    do {
        cout << "\nArt Collection Management Menu:\n";
        cout << "1. Display Art Collection Forward\n";
        cout << "2. Display Art Collection Backward\n";
        cout << "3. Add Artwork at the Beginning\n";
        cout << "4. Add Artwork at the End\n";
        cout << "5. Add Artwork at Nth Position\n";
        cout << "6. Delete Artwork from Beginning\n";
        cout << "7. Delete Artwork from End\n";
        cout << "8. Delete Artwork from Nth Position\n";
        cout << "9. Search Artwork by Artist Name\n";
        cout << "10. Sort Art Collection by Artist Name\n";
        cout << "11. For Stack - Digital Artwork Collection\n";
        cout << "12. For Queue - Artwork Collection\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        try {
            switch (choice) {
                case 1:
                    displayForward(artCollection);
                    break;
                case 2:
                    displayBackward(artCollection);
                    break;
                case 3: {
                    cin.ignore();  
                    string artist, nationality;
                    int age;
                    cout << "Enter Artist Name: ";
                    getline(cin, artist);
                    cout << "Enter Nationality: ";
                    getline(cin, nationality);
                    cout << "Enter Age: ";
                    cin >> age;
                    artCollection = insertAtHead(artCollection, { artist, nationality, age });
                    break;
                }
                case 4: {
                    cin.ignore();  
                    string artist, nationality;
                    int age;
                    cout << "Enter Artist Name: ";
                    getline(cin, artist);
                    cout << "Enter Nationality: ";
                    getline(cin, nationality);
                    cout << "Enter Age: ";
                    cin >> age;
                    artCollection = insertAtTail(artCollection, { artist, nationality, age });
                    break;
                }
                case 5: {
                    cin.ignore();  
                    int position;
                    string artist, nationality;
                    int age;
                    cout << "Enter Artist Name: ";
                    getline(cin, artist);
                    cout << "Enter Nationality: ";
                    getline(cin, nationality);
                    cout << "Enter Age: ";
                    cin >> age;
                    cout << "Enter the position to insert at: ";
                    cin >> position;
                    artCollection = insertAtNthPosition(artCollection, { artist, nationality, age }, position);
                    break;
                }
                case 6:
                    artCollection = deleteFromHead(artCollection);
                    break;
                case 7:
                    artCollection = deleteFromTail(artCollection);
                    break;
                case 8: {
                    int position;
                    cout << "Enter the position to delete from: ";
                    cin >> position;
                    artCollection = deleteFromNthPosition(artCollection, position);
                    break;
                }
                case 9: {
                    cin.ignore();  
                    string artist;
                    cout << "Enter Artist Name to search: ";
                    getline(cin, artist);
                    searchNodeByArtist(artCollection, artist);
                    break;
                }
                case 10:
                    artCollection = sortArtCollection(artCollection);
                    break;
                case 11:
                    digitalArtistArtworkCollection();
                    break;
                case 12:
                    artistArtworkQueue();
                    break;
                case 0:
                    cout << "Exiting program.\n";
                    break;
                default:
                    cout << "Invalid choice. Please enter a valid option.\n";
            }
        } catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
        }

    } while (choice != 0);

    return 0;
}
