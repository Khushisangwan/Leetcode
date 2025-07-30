#include <vector>
#include <algorithm>
// This code finds the longest subarray with the maximum bitwise AND in a given array.
// It iterates through the array to find the maximum value and then calculates the length
// of the longest contiguous subarray that contains this maximum value.
// The solution is designed to work with C++14 standard.
// The function `longestSubarray` returns the length of the longest subarray
// that consists entirely of the maximum value found in the input array.

class Solution {
public:
    int longestSubarray(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        // 1. Find the maximum value in the array.
        int maxVal = 0;
        for (int num : nums) {
            if (num > maxVal) {
                maxVal = num;
            }
        }
        
        // 2. Find the length of the longest subarray of maxVal.
        int maxLen = 0;
        int currentLen = 0;
        
        for (int num : nums) {
            if (num == maxVal) {
                currentLen++;
            } else {
                maxLen = std::max(maxLen, currentLen);
                currentLen = 0;
            }
        }
        
        // 3. Final check for a trailing streak.
        return std::max(maxLen, currentLen);
    }
};