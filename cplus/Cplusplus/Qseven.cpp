#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

// Function to read a square matrix of size n x n
void readMatrix(int matrix[][MAX_SIZE], int n) {
    cout << "Enter elements of the " << n << "x" << n << " matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << "Matrix[" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// Function to calculate and display left diagonal sum
int leftDiagonalSum(int matrix[][MAX_SIZE], int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += matrix[i][i];
    }
    return sum;
}

// Function to calculate and display right diagonal sum
int rightDiagonalSum(int matrix[][MAX_SIZE], int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += matrix[i][n - 1 - i];
    }
    return sum;
}

int main() {
    int n;
    int matrix[MAX_SIZE][MAX_SIZE];

    cout << "Enter the size of the square matrix (max " << MAX_SIZE << "): ";
    cin >> n;

    if (n < 1 || n > MAX_SIZE) {
        cout << "Invalid matrix size!" << endl;
        return 1;
    }

    readMatrix(matrix, n);

    // Calculate and display left diagonal sum
    int leftSum = leftDiagonalSum(matrix, n);
    cout << "Left diagonal sum: " << leftSum << endl;

    // Calculate and display right diagonal sum
    int rightSum = rightDiagonalSum(matrix, n);
    cout << "Right diagonal sum: " << rightSum << endl;

    return 0;
}
