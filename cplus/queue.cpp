// question-12 queue part

const int MAX_SIZE2 = 5;

int queueArr[MAX_SIZE];
int front = -1;
int rear = -1;

// Function to check if the queue is empty
bool qIsEmpty() {
    return front == -1;
}

// Function to check if the queue is full
bool qIsFull() {
    return (front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1);
}

// Function to enqueue (insert) an element into the queue
void enqueue(int value) {
    if (qIsFull()) {
        throw overflow_error("Queue Overflow. Cannot enqueue element into a full queue.");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % MAX_SIZE;
        queueArr[rear] = value;
        cout << "Enqueued " << value << " into the queue.\n";
    }
}

// Function to dequeue (remove) an element from the queue
void dequeue() {
    if (qIsEmpty()) {
        throw underflow_error("Queue Underflow. Cannot dequeue element from an empty queue.");
    } else {
        cout << "Dequeued " << queueArr[front] << " from the queue.\n";
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
    }
}

// Function to get the front element of the queue without dequeueing
int qPeek() {
    if (isEmpty()) {
        throw underflow_error("Queue is empty. No element to peek.");
    } else {
        return queueArr[front];
    }
}

// Function to display the elements of the queue
void qDisplay() {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
    } else {
        cout << "Queue elements: ";
        int i = front;
        do {
            cout << queueArr[i] << " ";
            i = (i + 1) % MAX_SIZE;
        } while (i != (rear + 1) % MAX_SIZE);
        cout << endl;
    }
}

void queue() {
    int choice, value;

    do {
        cout << "\nQueue Menu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        try {
            switch (choice) {
                case 1:
                    cout << "Enter the value to enqueue: ";
                    cin >> value;
                    enqueue(value);
                    break;
                case 2:
                    dequeue();
                    break;
                case 3:
                    cout << "Front element: " << qPeek() << endl;
                    break;
                case 4:
                    qDisplay();
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
