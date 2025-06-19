#include<bits/stdc++.h>
#include <range/v3/all.hpp>
using namespace std;
using namespace ranges;
//         formula = (formula * nCr(n-1, k)) % MOD;
//         return formula;
//         return ans;
//         return ans;
//         return ans;
    
class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        ranges::sort(nums);

    int ans = 1;
    int mn = nums[0];

    for (int i = 1; i < nums.size(); ++i)
      if (mn + k < nums[i]) {
        ++ans;
        mn = nums[i];
      }

    return ans;
    }
};