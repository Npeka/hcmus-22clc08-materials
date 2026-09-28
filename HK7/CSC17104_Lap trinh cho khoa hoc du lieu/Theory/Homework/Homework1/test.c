#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void multiplyMatrices(int firstMatrix[10][10], int secondMatrix[10][10], int result[10][10], int rowFirst, int columnFirst, int rowSecond, int columnSecond) {
    for(int i = 0; i < rowFirst; ++i) {
        for(int j = 0; j < columnSecond; ++j) {
            result[i][j] = 0;
            for(int k = 0; k < columnFirst; ++k) {
                result[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            }
        }
    }
}

int main() {
    int firstMatrix[10][10], secondMatrix[10][10], result[10][10];
    int rowFirst, columnFirst, rowSecond, columnSecond;

    // Set the size of the matrices
    rowFirst = 500; // Adjust size for testing
    columnFirst = 500;
    rowSecond = columnFirst; // Must match
    columnSecond = 600; // Adjust size for testing

    // Initialize matrices with random values
    for (int i = 0; i < rowFirst; ++i)
        for (int j = 0; j < columnFirst; ++j)
            firstMatrix[i][j] = rand() % 10;

    for (int i = 0; i < rowSecond; ++i)
        for (int j = 0; j < columnSecond; ++j)
            secondMatrix[i][j] = rand() % 10;

    // Start the clock
    clock_t start = clock();
    multiplyMatrices(firstMatrix, secondMatrix, result, rowFirst, columnFirst, rowSecond, columnSecond);
    // End the clock
    clock_t end = clock();

    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken for matrix multiplication in C: %f seconds\n", time_spent);

    return 0;
}
