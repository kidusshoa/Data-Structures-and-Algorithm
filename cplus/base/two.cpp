// stack operation part

const int MAX_SIZE = 5;

struct Artwork2 {
    string artist;
    string title;
    bool has3DAnimation;
    bool hasGraphicsDesign;
    bool has2DAnimation;
};

Artwork2 arr[MAX_SIZE];
int top = -1;

// Function to check if the stack is empty
bool isEmpty() {
    return top == -1;
}

// Function to check if the stack is full
bool isFull() {
    return top == MAX_SIZE - 1;
}

// Function to push an artwork onto the stack
void push(const Artwork2& value) {
    if (isFull()) {
        throw overflow_error("Artwork Collection Overflow. Cannot add more artwork to a full collection.");
    } else {
        arr[++top] = value;
        cout << "Added artwork titled '" << value.title << "' by " << value.artist << " to the collection.\n";
    }
}

// Function to pop an artwork from the stack
void pop() {
    if (isEmpty()) {
        throw underflow_error("Artwork Collection Underflow. Cannot remove artwork from an empty collection.");
    } else {
        cout << "Removed artwork titled '" << arr[top].title << "' by " << arr[top].artist << " from the collection.\n";
        top--;
    }
}

// Function to get the top artwork of the stack without removing it
Artwork2 peek() {
    if (isEmpty()) {
        throw underflow_error("Artwork Collection is empty. No artwork to peek.");
    } else {
        return arr[top];
    }
}

// Function to display the artworks in the collection
void display() {
    if (isEmpty()) {
        cout << "Artwork Collection is empty.\n";
    } else {
        cout << "Artwork Collection:\n";
        for (int i = 0; i <= top; ++i) {
            cout << "Title: '" << arr[i].title << "', Artist: " << arr[i].artist
                 << ", 3D Animation: " << (arr[i].has3DAnimation ? "Yes" : "No")
                 << ", Graphics Design: " << (arr[i].hasGraphicsDesign ? "Yes" : "No")
                 << ", 2D Animation: " << (arr[i].has2DAnimation ? "Yes" : "No") << endl;
        }
        cout << endl;
    }
}

void digitalArtistArtworkCollection() {
    int choice;
    Artwork2 artwork2;

    do {
        cout << "\nDigital Artist Artwork Collection Menu:\n";
        cout << "1. Add Artwork\n";
        cout << "2. Remove Artwork\n";
        cout << "3. View Top Artwork\n";
        cout << "4. Display Artwork Collection\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        try {
            switch (choice) {
                case 1:
                    cin.ignore();
                    cout << "Enter Artist Name: ";
                    getline(cin, artwork2.artist);
                    cout << "Enter Artwork Title: ";
                    getline(cin, artwork2.title);
                    cout << "Does it have 3D Animation? (1 for Yes, 0 for No): ";
                    cin >> artwork2.has3DAnimation;
                    cout << "Does it have Graphics Design? (1 for Yes, 0 for No): ";
                    cin >> artwork2.hasGraphicsDesign;
                    cout << "Does it have 2D Animation? (1 for Yes, 0 for No): ";
                    cin >> artwork2.has2DAnimation;
                    push(artwork2);
                    break;
                case 2:
                    pop();
                    break;
                case 3: {
                    Artwork2 topArtwork2 = peek();
                    cout << "Top Artwork: Title: '" << topArtwork2.title << "', Artist: " << topArtwork2.artist
                         << ", 3D Animation: " << (topArtwork2.has3DAnimation ? "Yes" : "No")
                         << ", Graphics Design: " << (topArtwork2.hasGraphicsDesign ? "Yes" : "No")
                         << ", 2D Animation: " << (topArtwork2.has2DAnimation ? "Yes" : "No") << endl;
                    break;
                }
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


