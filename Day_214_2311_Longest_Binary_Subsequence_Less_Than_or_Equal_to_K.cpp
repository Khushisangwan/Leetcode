#include<bits/stdc++.h>
using namespace std;
// LeetCode 2311. Longest Binary Subsequence Less Than or Equal to K
class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        int zeros = 0, ones = 0;
        long long value = 0, pow = 1;

        // Count the number of zeros in the string
        for (char c : s) {
            if (c == '0') zeros++;
        }

        // Traverse the string from right to left (least significant bit to most)
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '1') {
                // Check if adding this '1' keeps the value <= k
                if (value + pow > k) {
                    continue; // Skip this '1' as it would exceed k
                }
                value += pow; // Add the value of this '1'
                ones++;
            }
            pow <<= 1; // Move to the next higher bit
            if (pow > k) break; // Further bits would exceed k, so stop
        }

        // The answer is the total number of zeros and the selected ones
        return zeros + ones;
    }
};