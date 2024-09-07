// question-11 stack part 

const int MAX_SIZE = 5;

int arr[MAX_SIZE];
int top = -1;

// Function to check if the stack is empty
bool isEmpty() {
    return top == -1;
}

// Function to check if the stack is full
bool isFull() {
    return top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(int value) {
    if (isFull()) {
        throw overflow_error("Stack Overflow. Cannot push element onto a full stack.");
    } else {
        arr[++top] = value;
        cout << "Pushed " << value << " onto the stack.\n";
    }
}

// Function to pop an element from the stack
void pop() {
    if (isEmpty()) {
        throw underflow_error("Stack Underflow. Cannot pop element from an empty stack.");
    } else {
        cout << "Popped " << arr[top--] << " from the stack.\n";
    }
}

// Function to get the top element of the stack without popping
int peek() {
    if (isEmpty()) {
        throw underflow_error("Stack is empty. No element to peek.");
    } else {
        return arr[top];
    }
}

// Function to display the elements of the stack
void display() {
    if (isEmpty()) {
        cout << "Stack is empty.\n";
    } else {
        cout << "Stack elements: ";
        for (int i = 0; i <= top; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

void stack() {
    int choice, value;

    do {
        cout << "\nStack Menu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        try {
            switch (choice) {
                case 1:
                    cout << "Enter the value to push: ";
                    cin >> value;
                    push(value);
                    break;
                case 2:
                    pop();
                    break;
                case 3:
                    cout << "Top element: " << peek() << endl;
                    break;
                case 4:
                    display();
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

    
}
