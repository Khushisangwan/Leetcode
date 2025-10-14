#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), inc = 1, prevInc = 0, maxLen = 0;
        
        // Iterate through the array starting from index 1
        for (int i = 1; i < n; i++) {
            // If current element is greater than previous, extend current increasing sequence
            if (nums[i] > nums[i - 1]) {
                inc++;
            } else {
                // Current increasing sequence ends, save its length and reset
                prevInc = inc;
                inc = 1;
            }
            
            // Calculate maximum possible k for adjacent increasing subarrays
            // Either split current sequence in half, or use previous + current sequences
            maxLen = max(maxLen, max(inc >> 1, min(prevInc, inc)));
            
            // If we found valid adjacent increasing subarrays of length k, return true
            if (maxLen >= k) return true;
        }
        
        return false;
    }
};