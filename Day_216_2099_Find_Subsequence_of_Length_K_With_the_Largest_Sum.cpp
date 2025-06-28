#include<bits/stdc++.h>
using namespace std;
// LeetCode problem 2099: Find Subsequence of Length K With the Largest Sum
// Problem link: https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/
// Time complexity: O(n log n) due to sorting
// Space complexity: O(n) for storing the pairs of values and indices
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> numsWithIndices;
        for (int i = 0; i < nums.size(); i++) {
            numsWithIndices.push_back({nums[i], i});
        }

        // Sort by value descending
        sort(numsWithIndices.begin(), numsWithIndices.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.first > b.first;
             });

        // Take top k and sort by original index
        vector<pair<int, int>> topK(numsWithIndices.begin(), numsWithIndices.begin() + k);
        sort(topK.begin(), topK.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.second < b.second;
             });

        // Extract values
        vector<int> result;
        for (auto& p : topK) {
            result.push_back(p.first);
        }

        return result;
    }
};