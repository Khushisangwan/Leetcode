#include<bits/stdc++.h>
using namespace std;
// 2616. Minimize the Maximum Difference of Pairs
// This code defines a solution to minimize the maximum difference of pairs in an array.
// The goal is to form p pairs such that the maximum difference between any two elements in a pair is minimized.
// The approach uses binary search to find the minimum possible maximum difference.
// The function sorts the array and then uses a two-pointer technique to count how many pairs can be formed with a given maximum difference.

class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        if (p == 0) return 0;
        sort(nums.begin(), nums.end());
        int n = nums.size(), left = 0, right = nums[n - 1] - nums[0];

        while (left < right) {
            int mid = left + (right - left) / 2, pairs = 0;
            for (int i = 1; i < n; ++i) {
                if (mid >= nums[i] - nums[i - 1]) {
                    ++pairs, ++i;
                }
            }
            if (pairs >= p) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};