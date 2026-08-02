// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
void readMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

void transpose(int matrix[10][10], int result[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

void addMatrices(int a[10][10], int b[10][10], int result[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiplyMatrices(int a[10][10], int b[10][10], int result[10][10], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            int total = 0;
            for (int k = 0; k < colsA; k++) {
                total += a[i][k] * b[k][j];
            }
            result[i][j] = total;
        }
    }
}

int main() {
    int matrixA[10][10], transposed[10][10];
    int m, n;

    cout << "PART A - Transpose a Matrix" << endl;
    cout << "Enter number of rows: ";
    cin >> m;
    cout << "Enter number of columns: ";
    cin >> n;
    readMatrix(matrixA, m, n);

    cout << "\nOriginal Matrix:" << endl;
    printMatrix(matrixA, m, n);

    transpose(matrixA, transposed, m, n);
    cout << "\nTransposed Matrix:" << endl;
    printMatrix(transposed, n, m);

    cout << "\nPART B - Add Two Matrices" << endl;
    int m2, n2;
    cout << "Enter number of rows: ";
    cin >> m2;
    cout << "Enter number of columns: ";
    cin >> n2;

    int matrixB1[10][10], matrixB2[10][10], sumResult[10][10];
    cout << "Matrix 1:" << endl;
    readMatrix(matrixB1, m2, n2);
    cout << "Matrix 2:" << endl;
    readMatrix(matrixB2, m2, n2);

    addMatrices(matrixB1, matrixB2, sumResult, m2, n2);
    cout << "\nSum:" << endl;
    printMatrix(sumResult, m2, n2);

    cout << "\nPART C - Multiply Two Matrices" << endl;
    int m3, n3, p3;
    cout << "Enter rows of Matrix A: ";
    cin >> m3;
    cout << "Enter columns of Matrix A (= rows of Matrix B): ";
    cin >> n3;
    cout << "Enter columns of Matrix B: ";
    cin >> p3;

    int matrixC1[10][10], matrixC2[10][10], productResult[10][10];
    cout << "Matrix A:" << endl;
    readMatrix(matrixC1, m3, n3);
    cout << "Matrix B:" << endl;
    readMatrix(matrixC2, n3, p3);

    multiplyMatrices(matrixC1, matrixC2, productResult, m3, n3, p3);
    cout << "\nProduct:" << endl;
    printMatrix(productResult, m3, p3);

    return 0;
}
