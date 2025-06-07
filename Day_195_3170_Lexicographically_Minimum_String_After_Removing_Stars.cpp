#include<bits/stdc++.h>
using namespace std;
// 3170. Lexicographically Minimum String After Removing Stars
// This code defines a solution to remove stars from a string and return the lexicographically smallest string possible.
// The solution uses a vector of buckets to store indices of characters and processes stars accordingly.
// commit: add Solution class for lexicographically minimum string after removing stars

class Solution {
public:
    string clearStars(string s) {
        string ans = s; // Copy of the input string to modify
        vector<vector<int>> buckets(26); // Buckets to store indices of each character ('a' to 'z')

        // Iterate through the string
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '*') {
                ans[i] = ' '; // Mark the star for removal
                int j = 0;
                // Find the lexicographically smallest character to remove
                while (buckets[j].empty())
                    ++j;
                ans[buckets[j].back()] = ' '; // Mark the character for removal
                buckets[j].pop_back(); // Remove the index from the bucket
            } else {
                // Store the index of the character in its corresponding bucket
                buckets[s[i] - 'a'].push_back(i);
            }
        }

        std::erase(ans, ' '); // Remove all marked characters (spaces)
        return ans; // Return the resulting string
    }
};