#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        // Sort array in descending order to check largest possible triangles first
        sort(nums.begin(), nums.end(), greater<int>());
        
        // Check each triplet starting from the largest values
        for (int i = 0; i < nums.size() - 2; i++) {
            // Triangle inequality: sum of two smaller sides must be greater than the largest side
            if (nums[i + 1] + nums[i + 2] > nums[i]) {
                // Return the perimeter of the first valid triangle found
                return nums[i] + nums[i + 1] + nums[i + 2];
            }
        }
        
        // No valid triangle found
        return 0;
    }
};