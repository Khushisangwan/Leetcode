
#include <bits/stdc++.h>
using namespace std;
// 2434. Using a Robot to Print the Lexicographically Smallest String
// This code uses a stack to build the lexicographically smallest string
// by pushing characters from the input string and popping them based on the smallest remaining character.

// commit: add Solution class for lexicographically smallest string using stack

// Solution class to solve the problem using a stack
class Solution {
public:
    // Helper function to find the lexicographically smallest remaining character
    char l(vector<int>& freq) {
        // Iterate over all lowercase letters
        for (int i = 0; i < 26; i++) {
            if (freq[i]) return 'a' + i; // Return the first character with non-zero frequency
        }
        return 'a'; // Default return (should not be reached)
    }

    // Main function to return the lexicographically smallest string
    string robotWithString(string s) {
        stack<char> st;         // Stack to simulate the robot's holding area
        string t = "";          // Result string
        vector<int> freq(26);   // Frequency array for remaining characters

        // Count frequency of each character in s
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        // Iterate over characters in s
        for (char ch : s) {
            st.push(ch);            // Push current character to stack
            freq[ch - 'a']--;       // Decrement its frequency

            // Pop from stack to result if stack top ≤ smallest remaining char
            while (!st.empty() && st.top() <= l(freq)) {
                t += st.top();      // Add top of stack to result
                st.pop();           // Remove top of stack
            }
        }

        // Pop remaining characters from stack to result
        while (!st.empty()) {
            t += st.top();
            st.pop();
        }

        return t; // Return the final result
    }
};