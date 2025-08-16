#include <bits/stdc++.h>
using namespace std;

// Problem: Replace the first '6' with '9' in an integer to maximize its value
// Approach: Convert the number to a string, find the first occurrence of '6', replace it with '9', and convert back to integer

// Steps:
// 1. Convert the integer to a string.
// 2. Iterate through the string and find the first '6'.
// 3. Replace the first '6' with '9'.
// 4. Convert the modified string back to an integer and return it.
// 5. If no '6' is found, return the original number.

// Time Complexity: O(d) — where d is the number of digits in the input number, as we traverse the string once.
// Space Complexity: O(d) — for storing the string representation of the number.

class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        for (char &c : s) {
            if (c == '6') { c = '9'; break; }
        }
        return std::stoi(s);
    }
};