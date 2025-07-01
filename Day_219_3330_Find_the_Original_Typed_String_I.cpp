#include<bits/stdc++.h>
using namespace std;
// Problem - Find the Original Typed String I
// Approach - Count the number of characters that are different from their previous character

// commit: Implement Solution class with possibleStringCount method
class Solution {
public:
    // Returns the count of characters in 'word' that are the same as their previous character
    int possibleStringCount(string word) {
        int n = word.length(); // Length of the input string
        int count = n; // Initialize count to total number of characters
        for (int i = 1; i < n; i++) {
            // If current character is different from previous, decrement count
            if (word[i] != word[i - 1]) {
                count--;
            }
        }
        return count; // Return the final count
    }
};