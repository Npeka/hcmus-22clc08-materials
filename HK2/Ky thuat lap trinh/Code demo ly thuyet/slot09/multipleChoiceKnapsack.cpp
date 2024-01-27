#include <iostream>

using namespace std;

// Function to solve Multiple Choice Knapsack problem
int multipleChoiceKnapsack(int capacity, int numItems, int numChoices, int* itemWeights, int** itemValues) {
    // Initialize a 2D dp array
    int** dp = new int*[numItems + 1];
    for (int i = 0; i <= numItems; ++i) {
        dp[i] = new int[capacity + 1];
    }

    // Initialize the first row and first column of the dp array to 0
    for (int i = 0; i <= numItems; ++i) {
        for (int j = 0; j <= capacity; ++j) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }
        }
    }

    // Populate the dp array using bottom-up approach
    for (int i = 1; i <= numItems; ++i) {
        for (int j = 1; j <= capacity; ++j) {
            int maxVal = dp[i - 1][j]; // Maximum value without picking item i

            // Iterate over all choices for item i
            for (int k = 0; k < numChoices; ++k) {
                if (itemWeights[i - 1][k] <= j) {
                    // Update maxVal if picking item i with choice k gives higher value
                    maxVal = max(maxVal, itemValues[i - 1][k] + dp[i - 1][j - itemWeights[i - 1][k]]);
                }
            }

            dp[i][j] = maxVal;
        }
    }

    int maxProfit = dp[numItems][capacity];

    // Free dynamically allocated memory
    for (int i = 0; i <= numItems; ++i) {
        delete[] dp[i];
    }
    delete[] dp;

    return maxProfit;
}

int main() {
    int capacity = 50; // Capacity of the knapsack
    int numItems = 3; // Number of items
    int numChoices = 2; // Number of choices for each item

    // Arrays of weights and values for each item's choices
    int itemWeights[][2] = {{10, 20}, {20, 30}, {30, 40}};
    int itemValues[][2] = {{60, 100}, {100, 120}, {120, 140}};

    int maxProfit = multipleChoiceKnapsack(capacity, numItems, numChoices, *itemWeights, *itemValues);
    cout << "Maximum profit: " << maxProfit << endl;

    return 0;
}

