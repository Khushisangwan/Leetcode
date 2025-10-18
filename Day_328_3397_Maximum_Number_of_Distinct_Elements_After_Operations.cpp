#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        // Handle empty array edge case
        if (nums.empty()) return 0;
        
        // Sort array to process elements in ascending order
        sort(nums.begin(), nums.end());
        
        int count = 0;
        // Initialize previous assigned value to very small number
        int prev = INT_MIN >> 1;
        
        for (int a : nums) {
            // Calculate the valid range for current element after operation
            int low = a - k;   // Minimum possible value
            int high = a + k;  // Maximum possible value
            
            // Try to assign the smallest possible value greater than prev
            int x = prev + 1;
            
            // Ensure x is within the valid range
            if (x < low) x = low;
            
            // If we can assign a valid distinct value
            if (x <= high) {
                count++;        // Increment count of distinct elements
                prev = x;       // Update previous assigned value
            }
            // If x > high, we can't assign any value to this element
        }
        
        return count;
    }
};