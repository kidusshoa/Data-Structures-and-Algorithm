#include <iostream>
#include <limits>

using namespace std;

int main() {
    int number;
    char choice;
    int maxNumber = numeric_limits<int>::min(); // Initialize to smallest integer
    int minNumber = numeric_limits<int>::max(); // Initialize to largest integer

    do {
        cout << "Enter an integer number: ";
        cin >> number;

        if (number > maxNumber) {
            maxNumber = number;
        }
        if (number < minNumber) {
            minNumber = number;
        }

        cout << "Do you want to enter another number? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "\nMaximum number entered: " << maxNumber << endl;
    cout << "Minimum number entered: " << minNumber << endl;

    return 0;
}
