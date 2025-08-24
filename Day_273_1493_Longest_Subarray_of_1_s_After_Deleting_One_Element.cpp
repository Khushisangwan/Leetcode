#include <bits/stdc++.h>
using namespace std;

// Problem: Given a binary array, find the length of the longest subarray containing only 1s after deleting one element.
// Approach: Use a sliding window technique to maintain a window with at most one 0, and calculate the maximum length of
//           such a window minus one (to account for the deleted element).

// Steps:
// 1. Initialize two pointers (left and right) to represent the current window, a counter for zeros, and a variable to store the result.
// 2. Expand the right pointer to include new elements in the window.
// 3. If the count of zeros exceeds one, move the left pointer to the right until there is at most one zero in the window.
// 4. Update the result with the maximum length of the window minus one.
// 5. Return the result after processing all elements in the array.

// Time Complexity: O(n) where n is the number of elements in the array.
// Space Complexity: O(1) as we are using a constant amount of extra space.

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0, zeros = 0, res = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) zeros++;
            
            while (zeros > 1) {
                if (nums[left] == 0) zeros--;
                left++;
            }
            
            res = max(res, right - left);
        }
        
        return res;
    }
};