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
    for (int i = 0; i < n / 2; ++i) {
        int temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
    cout << "Array after reversing elements:\n";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
