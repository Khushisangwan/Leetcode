#include <bits/stdc++.h>
using namespace std;
// 3442. Maximum Difference Between Even and Odd Frequency I
// This code defines a solution to find the maximum difference between the frequency of characters with odd and even counts in a string.

class Solution {
public:
    // Function to find the maximum difference between the frequency of characters
    // with odd and even counts in a string
    int maxDifference(string s) {
        vector<int> mpp(26); // Frequency map for each lowercase letter
        int maxi = 0, mini = s.size(); // Initialize max odd freq and min even freq
        for (char c : s) mpp[c - 'a']++; // Count frequency of each character
        for (int i = 0 ; i < 26; i++) {
            if (mpp[i] % 2 != 0) // If frequency is odd
                maxi = max(maxi, mpp[i]); // Update maximum odd frequency
            if (mpp[i] % 2 == 0 && mpp[i] > 0) // If frequency is even and > 0
                mini = min(mini, mpp[i]); // Update minimum even frequency
        } 
        return maxi - mini; // Return the difference
    }
};