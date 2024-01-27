#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str, int start, int end) {
   // Base case: If there is only one character
   if (start == end) {
      return true;
   }
   // If the first and last characters don't match
   if (str[start] != str[end]) {
      return false;
   }
   // Recursively check if the remaining substring is a palindrome
   if (start < end + 1) {
      return isPalindrome(str, start + 1, end - 1);
   }
   return true;
}

int main() {
   string str = "racecar";
   int start = 0;
   int end = str.length() - 1;
   
   if (isPalindrome(str, start, end)) {
      cout << "The string is a palindrome." << endl;
   } else {
      cout << "The string is not a palindrome." << endl;
   }
   
   return 0;
}

