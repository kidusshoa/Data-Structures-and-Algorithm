// queue implemetation part

const int MAX_SIZE2 = 5;

struct ArtistArtwork3 {
    string artist;
    int muralArtCount;
    int portraitCount;
    int abstractArtCount;
};

ArtistArtwork3 queueArr[MAX_SIZE2];
int front2 = -1;
int rear2 = -1;

// Function to check if the queue is empty
bool qIsEmpty2() {
    return front2 == -1;
}

// Function to check if the queue is full
bool qIsFull2() {
    return (front2 == 0 && rear2 == MAX_SIZE2 - 1) || (front2 == rear2 + 1);
}// Add this line to consume the newline character

// Function to enqueue (insert) artist artwork information into the queue
void enqueue2(const ArtistArtwork3& value) {
    if (qIsFull2()) {
        throw overflow_error("Queue Overflow. Cannot enqueue element into a full queue.");
    } else {
        if (front2 == -1) {
            front2 = 0;
        }
        rear2 = (rear2 + 1) % MAX_SIZE2;
        queueArr[rear2] = value;
        cout << "Enqueued artist's artwork information for " << value.artist << " into the queue.\n";
    }
}

// Function to dequeue (remove) artist artwork information from the queue
void dequeue2() {
    if (qIsEmpty2()) {
        throw underflow_error("Queue Underflow. Cannot dequeue element from an empty queue.");
    } else {
        cout << "Dequeued artist's artwork information for " << queueArr[front2].artist << " from the queue.\n";
        if (front2 == rear2) {
            front2 = rear2 = -1;
        } else {
            front2 = (front2 + 1) % MAX_SIZE2;
        }
    }
}

// Function to get the front artist artwork information from the queue without dequeueing
ArtistArtwork3 qPeek2() {
    if (qIsEmpty2()) {
        throw underflow_error("Queue is empty. No element to peek.");
    } else {
        return queueArr[front2];
    }
}

// Function to display the artist artwork information in the queue
void qDisplay2() {
    if (qIsEmpty2()) {
        cout << "Queue is empty.\n";
    } else {
        cout << "Artist Artwork Information Queue:\n";
        int i = front2;
        do {
            cout << "Artist: " << queueArr[i].artist
                 << ", Mural Art Count: " << queueArr[i].muralArtCount
                 << ", Portrait Count: " << queueArr[i].portraitCount
                 << ", Abstract Art Count: " << queueArr[i].abstractArtCount << endl;
            i = (i + 1) % MAX_SIZE2;
        } while (i != (rear2 + 1) % MAX_SIZE2);
        cout << endl;
    }
}

void artistArtworkQueue() {
    int choice;
    ArtistArtwork3 artistArtwork3;

    do {
        cout << "\nArtist Artwork Information Queue Menu:\n";
        cout << "1. Enqueue Artist Artwork Information\n";
        cout << "2. Dequeue Artist Artwork Information\n";
        cout << "3. Peek Artist Artwork Information\n";
        cout << "4. Display Artist Artwork Information Queue\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        try {
            switch (choice) {
                case 1:
                    cin.ignore();
                    cout << "Enter Artist Name: ";
                    getline(cin, artistArtwork3.artist);
                    cout << "Enter Mural Art Count: ";
                    cin >> artistArtwork3.muralArtCount;
                    cout << "Enter Portrait Count: ";
                    cin >> artistArtwork3.portraitCount;
                    cout << "Enter Abstract Art Count: ";
                    cin >> artistArtwork3.abstractArtCount;
                    enqueue2(artistArtwork3);
                    break;
                case 2:
                    dequeue2();
                    break;
                case 3: {
                    ArtistArtwork3 frontArtistArtwork3 = qPeek2();
                    cout << "Front Artist Artwork Information: Artist: " << frontArtistArtwork3.artist
                         << ", Mural Art Count: " << frontArtistArtwork3.muralArtCount
                         << ", Portrait Count: " << frontArtistArtwork3.portraitCount
                         << ", Abstract Art Count: " << frontArtistArtwork3.abstractArtCount << endl;
                    break;
                }
                case 4:
                    qDisplay2();
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


