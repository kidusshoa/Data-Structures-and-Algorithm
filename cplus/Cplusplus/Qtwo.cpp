#include <iostream>
#include <cmath>

using namespace std;

float calculateBill(int calls) {
    float bill = 200.0; // Minimum charge for up to 100 calls

    if (calls > 100) {
        int additionalCalls = calls - 100;
        if (additionalCalls <= 50) {
            bill += additionalCalls * 0.60;
        } else {
            bill += 50 * 0.60; // Charges for next 50 calls
            additionalCalls -= 50;
            if (additionalCalls <= 50) {
                bill += additionalCalls * 0.50;
            } else {
                bill += 50 * 0.50; // Charges for next 50 calls
                additionalCalls -= 50;
                bill += additionalCalls * 0.40; // Charges for calls beyond 200
            }
        }
    }

    return bill;
}

int main() {
    int calls;
    cout << "Enter number of calls: ";
    cin >> calls;

    float bill = calculateBill(calls);

    // To format the bill to 2 decimal places without <iomanip>
    cout << "Your bill is $" << round(bill * 100) / 100 << endl;

    return 0;
}
