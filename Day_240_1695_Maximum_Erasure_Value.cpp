#include<bits/stdc++.h>
using namespace std;
// Sliding Window Approach to find Maximum Unique Subarray Sum
// This code uses a hash set to track unique elements and a two-pointer technique to maintain the current subarray.
// The maximum sum is updated whenever a new unique element is added to the current subarray.
// Time Complexity: O(n), where n is the number of elements in the input array.

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> seen;
        int left = 0;
        int currentSum = 0;
        int maxSum = 0;
        
        for (int right = 0; right < n; ++right) {
            while (seen.find(nums[right]) != seen.end()) {
                currentSum -= nums[left];
                seen.erase(nums[left]);
                ++left;
            }
            currentSum += nums[right];
            seen.insert(nums[right]);
            maxSum = max(maxSum, currentSum);
        }
        
        return maxSum;
    }
};