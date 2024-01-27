#include <iostream>

using namespace std;

// Function to solve 0-1 Knapsack problem
int knapsack(int capacity, int weights[], int values[], int n) {
    // Initialize a 2D dp array
    int** dp = new int*[n + 1];
    for (int i = 0; i <= n; ++i) {
        dp[i] = new int[capacity + 1];
    }

    // Initialize the first row and first column of the dp array to 0
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= capacity; ++j) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }
        }
    }

    // Populate the dp array using bottom-up approach
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= capacity; ++j) {
            if (weights[i - 1] <= j) {
                dp[i][j] = max(values[i - 1] + dp[i - 1][j - weights[i - 1]], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    int maxProfit = dp[n][capacity];

    // Free dynamically allocated memory
    for (int i = 0; i <= n; ++i) {
        delete[] dp[i];
    }
    delete[] dp;

    return maxProfit;
}

int main() {
    int capacity = 50; // Capacity of the knapsack
    int weights[] = {10, 20, 30}; // Array of weights
    int values[] = {60, 100, 120}; // Array of values
    int n = sizeof(weights) / sizeof(weights[0]); // Number of items

    int maxProfit = knapsack(capacity, weights, values, n);
    cout << "Maximum profit: " << maxProfit << endl;

    return 0;
}

