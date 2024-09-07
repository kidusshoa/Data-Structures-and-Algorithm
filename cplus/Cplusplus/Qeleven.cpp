#include <iostream>
using namespace std;

const int MAX_SIZE = 100; 

int main() {
    int arr[MAX_SIZE];
    int n;

    cout << "Enter the size of the array (max " << MAX_SIZE << "): ";
    cin >> n;

    if (n < 1 || n > MAX_SIZE) {
        cout << "Invalid array size!" << endl;
        return 1;
    }
    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    // Initialize variables to store max and min values
    int maxElement = arr[0];
    int minElement = arr[0];

    // Find the largest and smallest elements in the array
    for (int i = 1; i < n; ++i) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
        if (arr[i] < minElement) {
            minElement = arr[i];
        }
    }
    cout << "Largest element in the array: " << maxElement << endl;
    cout << "Smallest element in the array: " << minElement << endl;

    return 0;
}
