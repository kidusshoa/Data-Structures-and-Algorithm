#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    // Dynamically allocate memory for the array
    int* array = new int[n];

    // Accept values from the keyboard
    cout << "Enter " << n << " integer values:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Element " << i + 1 << ": ";
        cin >> *(array + i);
    }

    // Display the elements of the array
    cout << "The elements of the array are:\n";
    for (int i = 0; i < n; ++i) {
        cout << *(array + i) << " ";
    }
    cout << endl;

    // Free the dynamically allocated memory
    delete[] array;

    return 0;
}
