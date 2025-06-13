#include<bits/stdc++.h>
using namespace std;
// 2616. Minimize the Maximum Difference of Pairs
// This code defines a solution to minimize the maximum difference of pairs in an array.
// The goal is to form p pairs such that the maximum difference between any two elements in a pair is minimized.
// The approach uses binary search to find the minimum possible maximum difference.
// The function sorts the array and then uses a two-pointer technique to count how many pairs can be formed with a given maximum difference.

class Solution {
public:
    // Function to minimize the maximum difference of pairs
    int minimizeMax(vector<int>& nums, int p) {
        if (p == 0) return 0; // If no pairs needed, return 0
        sort(nums.begin(), nums.end()); // Sort the array to make pairing easier
        int n = nums.size();
        int left = 0, right = nums[n - 1] - nums[0]; // Initialize binary search bounds

        // Binary search for the minimal possible maximum difference
        while (left < right) {
            int mid = left + (right - left) / 2; // Candidate maximum difference
            int pairs = 0;
            // Try to form as many pairs as possible with difference <= mid
            for (int i = 1; i < n; ++i) {
                if (mid >= nums[i] - nums[i - 1]) {
                    ++pairs; // Form a pair
                    ++i;     // Skip the next element as it's already paired
                }
            }
            // If enough pairs can be formed, try a smaller maximum difference
            if (pairs >= p) right = mid;
            else left = mid + 1; // Otherwise, increase the allowed difference
        }
        return left; // The minimal possible maximum difference
    }
};