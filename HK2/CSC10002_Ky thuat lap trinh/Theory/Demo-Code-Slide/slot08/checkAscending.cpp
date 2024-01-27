#include <iostream>

using namespace std;

bool isAscending(int arr[], int size) {
  // base case
  if (size <= 1) {
    return true;
  }

  // recursive case
  if (arr[size - 1] < arr[size - 2]) {
    return false;
  } else {
    return isAscending(arr, size - 1);
  }
}

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  int size = sizeof(arr) / sizeof(arr[0]);
  
  if (isAscending(arr, size)) {
    cout << "The elements in the array are in ascending order." << endl;
  } else {
    cout << "The elements in the array are not in ascending order." << endl;
  }
  
  return 0;
}
