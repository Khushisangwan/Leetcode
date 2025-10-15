#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int up = 1;        // Length of current increasing subarray
        int preUp = 0;     // Length of previous increasing subarray
        int res = 0;       // Maximum length found so far
        
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                up++;  // Extend current increasing subarray
            } else {
                preUp = up;  // Store previous subarray length
                up = 1;      // Reset current subarray length
            }
            
            // Try two scenarios:
            int half = up >> 1;           // Split current subarray in half
            int m = min(preUp, up);       // Use previous and current subarrays
            int candidate = max(half, m); // Take the better option
            
            if (candidate > res) res = candidate;
        }
        return res;
    }
};