#include <bits/stdc++.h>
using namespace std;

// Problem: Divide a String Into Groups of Size k
// Approach: Iterate through the string, creating groups of size k and padding with fill character if necessary.

// Steps:
// 1. Calculate the number of groups needed based on the string length and k.
// 2. For each group, collect characters from the string.
// 3. If the group is not full (less than k characters), pad it with the fill character.
// 4. Store each group in a result vector.

// Time Complexity: O(n), where n is the length of the string.
// Space Complexity: O(n/k), where n/k is the number of groups created.

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size();
        // Calculate the number of groups needed
        int groups = (n + k - 1) / k;
        vector<string> result(groups);
        
        // Iterate over each group
        for (int i = 0; i < groups; i++) {
            string group;
            // Collect up to k characters for the current group
            for (int j = 0; j < k; j++) {
                int index = i * k + j;
                if (index < n) {
                    group += s[index]; // Add character from string
                } else {
                    group += fill; // Pad with fill character if needed
                }
            }
            result[i] = group; // Store the group in the result
        }
        
        return result; // Return all groups
    }
};