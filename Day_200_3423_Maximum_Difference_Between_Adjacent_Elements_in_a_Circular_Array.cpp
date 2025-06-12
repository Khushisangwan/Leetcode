#include<bits/stdc++.h>
using namespace std;
// 3423. Maximum Difference Between Adjacent Elements in a Circular Array
// This code defines a solution to find the maximum absolute difference between adjacent elements in a circular array.

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxi = 0;
        for (int i = 0 ; i < nums.size() - 1 ; i++)
            maxi = max(maxi , abs(nums[i + 1] - nums[i]));
        maxi = max(maxi , abs(nums[nums.size() - 1] - nums[0]));
        return maxi;
    }
};