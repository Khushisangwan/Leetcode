#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char res = letters[0];  // Initialize result with first letter
        bool flag = false;      // Flag to track if we've found first letter > target

        for (char ch : letters) {
            if (!flag) {
                // First iteration: find the first letter greater than target
                if (ch > target) {
                    res = ch;
                    flag = !flag;  // Set flag to true
                }
            } else {
                // Subsequent iterations: find the smallest letter > target
                if (ch > target && ch < res) res = ch;
            }
        }

        return res;  // Return the smallest letter greater than target
    }
};