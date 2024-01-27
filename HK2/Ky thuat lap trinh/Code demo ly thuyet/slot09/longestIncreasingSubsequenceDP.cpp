#include <iostream>

using namespace std;

int longestIncreasingSubsequence(int* nums, int n) {
    int* dp = new int[n]; // Allocate dynamic array for dp
    for (int i = 0; i < n; i++) {
        dp[i] = 1; // Initialize dp array with 1, as a single element is always a valid LIS
    }
    int maxLen = 1; // Variable to store the maximum length of LIS

    // Iterate through the array
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1); // Update dp[i] if a longer increasing subsequence is found
            }
        }
        maxLen = max(maxLen, dp[i]); // Update maxLen with the maximum length of LIS so far
    }

    delete[] dp; // Deallocate dynamic array

    return maxLen;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int* nums = new int[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int maxLen = longestIncreasingSubsequence(nums, n);
    cout << "The length of the longest increasing subsequence is: " << maxLen << std::endl;

    delete[] nums; // Deallocate dynamic array

    return 0;
}

