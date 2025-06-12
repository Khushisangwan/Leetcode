#include<bits/stdc++.h>
using namespace std;
// 3423. Maximum Difference Between Adjacent Elements in a Circular Array
// This code defines a solution to find the maximum absolute difference between adjacent elements in a circular array.

class Solution {
public:
    // Function to find the maximum absolute difference between adjacent elements in a circular array
    int maxAdjacentDistance(vector<int>& nums) {
        int maxi = 0; // Initialize the maximum difference to 0
        // Iterate through the array and compare each pair of adjacent elements
        for (int i = 0 ; i < nums.size() - 1 ; i++)
            maxi = max(maxi , abs(nums[i + 1] - nums[i]));
        // Compare the last and first element to account for the circular nature
        maxi = max(maxi , abs(nums[nums.size() - 1] - nums[0]));
        return maxi; // Return the maximum absolute difference found
    }
};