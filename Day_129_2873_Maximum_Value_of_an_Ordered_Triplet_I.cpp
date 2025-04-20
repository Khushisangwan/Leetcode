#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftMax(n, 0), rightMax(n, 0);
        for(int i=1; i<n; i++){
            leftMax[i] = max(leftMax[i-1], nums[i-1]);
            rightMax[n-i-1] = max(rightMax[n-i], nums[n-i]);
        }

        long long ans=0; 
        for(int i=1; i<n-1; i++){
            result= max(ans, (long long)(leftMax[i] - nums[i]) * rightMax[i]);
        }

        return ans;
    }
};