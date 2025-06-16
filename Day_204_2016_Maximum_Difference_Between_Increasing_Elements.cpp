#include<bits/stdc++.h>
using namespace std;
// 2016. Maximum Difference Between Increasing Elements
// This code defines a solution to find the maximum difference between increasing elements in an array.

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size();
        int maxD=-1, xMinL=1e9, xMaxR=-1;
        for(int l=0, r=n-1; l<r; l++){
            xMinL=min(nums[l], xMinL);
            while(l<r && nums[l+1]>nums[l]){
                l++;
                maxD=max(maxD, nums[l]-xMinL);
            }
            xMaxR=max(nums[r], xMaxR);
            while(l<r && nums[r-1]<nums[r]){
                r--;
                maxD=max(maxD, nums[r]-xMaxR);
            }
            maxD=max(maxD, xMaxR-xMinL);
        } 
        return maxD==0?-1:maxD;
    }
};