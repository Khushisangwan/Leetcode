#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size(), i = 0;
        
        // Phase 1: Strictly increasing sequence
        while (i + 1 < n && nums[i] < nums[i + 1]) i++;
        // Must have at least one element in increasing phase
        if (i == 0 || i == n - 1) return false;
        
        int p = i;
        // Phase 2: Strictly decreasing sequence
        while (i + 1 < n && nums[i] > nums[i + 1]) i++;
        // Must have at least one element in decreasing phase
        if (i == p || i == n - 1) return false;
        
        // Phase 3: Strictly increasing sequence
        while (i + 1 < n && nums[i] < nums[i + 1]) i++;
        // Must reach the end of array
        return i == n - 1;
    }
};