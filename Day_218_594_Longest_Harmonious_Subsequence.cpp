#include<bits/stdc++.h>
using namespace std;
// Problem - Longest Harmonious Subsequence
// Approach - Two Pointers Technique
class Solution {
public:
    int findLHS(vector<int>& nums) {
        // Sort the array to bring equal and consecutive numbers together
        sort(nums.begin(), nums.end());
        int j = 0, maxLength = 0;

        // Use two pointers: i (end of window), j (start of window)
        for (int i = 0; i < nums.size(); ++i) {
            // Move j forward if the difference is more than 1
            while (nums[i] - nums[j] > 1) {
                ++j;
            }
            // If the difference is exactly 1, update maxLength
            if (nums[i] - nums[j] == 1) {
                maxLength = max(maxLength, i - j + 1);
            }
        }
        // Return the length of the longest harmonious subsequence
        return maxLength;
    }
};