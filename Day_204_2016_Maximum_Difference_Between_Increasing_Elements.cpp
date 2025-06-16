#include<bits/stdc++.h>
using namespace std;
// 2016. Maximum Difference Between Increasing Elements
// This code defines a solution to find the maximum difference between increasing elements in an array.

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int maxD = -1, xMinL = 1e9, xMaxR = -1;
        // Iterate with two pointers from both ends
        for (int l = 0, r = n - 1; l < r; l++) {
            // Track minimum value from the left
            xMinL = min(nums[l], xMinL);
            // Move left pointer forward while the sequence is increasing
            while (l < r && nums[l + 1] > nums[l]) {
                l++;
                maxD = max(maxD, nums[l] - xMinL);
            }
            // Track maximum value from the right
            xMaxR = max(nums[r], xMaxR);
            // Move right pointer backward while the sequence is decreasing
            while (l < r && nums[r - 1] < nums[r]) {
                r--;
                maxD = max(maxD, nums[r] - xMaxR);
            }
            // Update max difference between current right max and left min
            maxD = max(maxD, xMaxR - xMinL);
        }
        // If no valid difference found, return -1
        return maxD == 0 ? -1 : maxD;
    }
};