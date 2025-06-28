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
        // Store each number with its original index
        for (int i = 0; i < nums.size(); i++) {
            numsWithIndices.push_back({nums[i], i});
        }

        // Sort by value in descending order to get the largest elements
        sort(numsWithIndices.begin(), numsWithIndices.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.first > b.first;
             });

        // Take the top k elements (with their indices)
        vector<pair<int, int>> topK(numsWithIndices.begin(), numsWithIndices.begin() + k);
        // Sort the selected k elements by their original indices to maintain order
        sort(topK.begin(), topK.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.second < b.second;
             });

        // Extract the values from the sorted pairs
        vector<int> result;
        for (auto& p : topK) {
            result.push_back(p.first);
        }

        return result;
    }
};