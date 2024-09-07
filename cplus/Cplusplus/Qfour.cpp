#include <iostream>

using namespace std;

const int ROWS = 3;
const int COLS = 3;

void inputMatrix(int matrix[ROWS][COLS], const string& name) {
    cout << "Enter elements for " << name << " matrix:\n";
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << name << "[" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void multiplyMatrices(const int matrix1[ROWS][COLS], const int matrix2[ROWS][COLS], int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            result[i][j] = matrix1[i][j] * matrix2[i][j];
        }
    }
}

void displayMatrix(const int matrix[ROWS][COLS], const string& name) {
    cout << "\n" << name << " matrix:\n";
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int matrix1[ROWS][COLS];
    int matrix2[ROWS][COLS];
    int result[ROWS][COLS];

    // Input matrices
    inputMatrix(matrix1, "Matrix1");
    inputMatrix(matrix2, "Matrix2");

    // Multiply matrices
    multiplyMatrices(matrix1, matrix2, result);

    // Display result
    displayMatrix(result, "Result");

    return 0;
}
