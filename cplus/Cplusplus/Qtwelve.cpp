#include <iostream>
using namespace std;

// Function to calculate power of x raised to p
int power(int x, int p = 2) {
    int result = 1;
    for (int i = 0; i < p; ++i) {
        result *= x;
    }
    return result;
}

int main() {
    int x, p;
    cout << "Enter a base number (x): ";
    cin >> x;
    cout << "Enter a power (p, default is 2): ";
    cin >> p;
    
    // Calculate the power using the power function
    int result = power(x, p);
 
    cout << x << " raised to the power of " << p << " is: " << result << endl;
    
    return 0;
}
