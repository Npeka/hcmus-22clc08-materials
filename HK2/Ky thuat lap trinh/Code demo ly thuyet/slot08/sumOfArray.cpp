#include <iostream>
using namespace std;

int sum(int arr[], int n) {
    if (n == 0) { // base case
        return 0;
    } else {
        return arr[n-1] + sum(arr, n-1); // recursive case
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int total = sum(arr, n);
    cout << "The sum of all elements in the array is: " << total << endl;
    return 0;
}
