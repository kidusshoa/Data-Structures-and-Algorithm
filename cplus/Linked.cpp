#include <iostream>
#include <stdexcept>
#include <cstdlib>
using namespace std;
#include "stack.cpp"
#include "queue.cpp"

// question-1 declaring a node structure 
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// question-1 Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

// question-2 displaying forward
void displayForward(Node* head) {
    Node* current = head;
    cout << "Doubly Linked List (Forward): ";
    while (current != nullptr) {
        cout << current->data << " ";
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
    cout << "Doubly Linked List (Backward): ";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->prev;
    }
    cout << endl;
}

// question-3 insert a new node at the head
Node* insertAtHead(Node* head, int value) {
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
Node* insertAtTail(Node* head, int value) {
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
Node* insertAtNthPosition(Node* head, int value, int position) {
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

// question-9 search for a node by data value
void searchNodeByData(Node* head, int value) {
    Node* current = head;
    int position = 1;
    while (current != nullptr) {
        if (current->data == value) {
            cout << "Node found at position " << position << endl;
            return;
        }
        current = current->next;
        position++;
    }
    cout << "Node with data " << value << " not found." << endl;
}

// question-10 sort the Doubly Linked List
Node* sortDoublyLinkedList(Node* head) {
    if (head == nullptr) {
        cout << "List is empty. Nothing to sort." << endl;
        return head;
    }
    Node* i, *j;
    for (i = head; i != nullptr; i = i->next) {
        for (j = i->next; j != nullptr; j = j->next) {
            if (i->data > j->data) {
                swap(i->data, j->data);
            }
        }
    }
    displayForward(head);
    return head;
}

int main() {
    
    
    Node* myList = nullptr;

    int choice;
    do {
        cout << "\nDoubly Linked List Menu:\n";
        cout << "1. Display Forward\n";
        cout << "2. Display Backward\n";
        cout << "3. Insert at Head\n";
        cout << "4. Insert at Tail\n";
        cout << "5. Insert at Nth Position\n";
        cout << "6. Delete from Head\n";
        cout << "7. Delete from Tail\n";
        cout << "8. Delete from Nth Position\n";
        cout << "9. Search Node by Data\n";
        cout << "10. Sort Doubly Linked List\n";
        cout << "11. For Stack Operation\n";
        cout << "12. For Queue Operation\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        try {
            switch (choice) {
                case 1:
                    displayForward(myList);
                    break;
                case 2:
                    displayBackward(myList);
                    break;
                case 3: {
                    int value;
                    cout << "Enter the value to insert at head: ";
                    cin >> value;
                    myList = insertAtHead(myList, value);
                    break;
                }
                case 4: {
                    int value;
                    cout << "Enter the value to insert at tail: ";
                    cin >> value;
                    myList = insertAtTail(myList, value);
                    break;
                }
                case 5: {
                    int value, position;
                    cout << "Enter the value to insert: ";
                    cin >> value;
                    cout << "Enter the position to insert at: ";
                    cin >> position;
                    myList = insertAtNthPosition(myList, value, position);
                    break;
                }
                case 6:
                    myList = deleteFromHead(myList);
                    break;
                case 7:
                    myList = deleteFromTail(myList);
                    break;
                case 8: {
                    int position;
                    cout << "Enter the position to delete from: ";
                    cin >> position;
                    myList = deleteFromNthPosition(myList, position);
                    break;
                }
                case 9: {
                    int value;
                    cout << "Enter the value to search: ";
                    cin >> value;
                    searchNodeByData(myList, value);
                    break;
                }
                case 10:
                    myList = sortDoublyLinkedList(myList);
                    break;
                case 11:
                    stack();
                    break;
                case 12:
                    queue();
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
