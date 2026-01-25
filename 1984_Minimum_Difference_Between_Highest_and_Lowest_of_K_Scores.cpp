#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        // Sort the array to find consecutive k elements with minimum difference
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        // Iterate through all possible windows of size k
        for (int i = 0; i + k - 1 < n; ++i) {
            // Update the minimum difference between the largest and smallest in the window
            ans = min(ans, nums[i + k - 1] - nums[i]);
        }
        return ans;
    }
};