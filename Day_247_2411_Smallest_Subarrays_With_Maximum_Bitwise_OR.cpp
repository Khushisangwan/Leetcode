#include<bits/stdc++.h>
using namespace std;
// This code finds the smallest subarrays with the maximum bitwise OR for each index in the input array.
// It uses a greedy approach to track the last seen index of each bit and calculates the length
// of the smallest subarray that includes the maximum OR value.
// The solution is designed to work with C++14 standard.
// The function `smallestSubarrays` iterates through the input array in reverse order,
// updating the last seen indices of bits and calculating the smallest subarray length for each index.
// The code is efficient and works within the constraints provided.
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        const int n=nums.size();
        vector<int> ans(n);
        vector<int> last(30, -1); // last seen index of each bit

        for (int i=n-1; i>= 0; i--) {
            const unsigned x=nums[i];
            int j=i;
            bitset<30> X(x);
            for (int b=0; b<30; b++) {
                if (X[b]) 
                    last[b]=i;
                j=max(j, last[b]);
            }
            ans[i]=j-i+1;
        }

        return ans;
    }
};