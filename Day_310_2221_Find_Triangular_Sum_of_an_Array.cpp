#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        
        // Iterate from bottom to top of the triangle
        // Each iteration reduces the array size by 1
        for (int i = n - 1; i >= 1; i--) {
            // For each level, calculate sum of adjacent pairs
            for (int j = 0; j < i; j++) {
                // Add adjacent elements and take modulo 10
                // Store result in the left position
                nums[j] = (nums[j] + nums[j + 1]) % 10;
            }
        }
        
        // Return the final single element at the top of triangle
        return nums[0]; 
    }
};