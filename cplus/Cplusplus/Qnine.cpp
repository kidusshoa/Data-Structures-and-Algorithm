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

    if (n >= 2) {
        int temp = arr[0];
        arr[0] = arr[n - 1];
        arr[n - 1] = temp;
    }

    cout << "Array after swapping first and last elements:\n";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
