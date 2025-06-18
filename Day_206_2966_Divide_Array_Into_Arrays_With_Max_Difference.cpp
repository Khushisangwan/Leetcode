#include<bits/stdc++.h>
using namespace std;
//         formula = (formula * nCr(n-1, k)) % MOD;
//         return formula;
//     }
// };

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        int n = nums.size();
        // Sort the array to group close elements together
        sort(nums.begin(), nums.end());
        // Iterate through the array in steps of 3
        for (int i = 0; i < n - 2; i += 3) {
            // Check if the difference between the largest and smallest in the group is within k
            if (nums[i + 2] - nums[i] > k) return {};
            // Add the group of 3 to the answer
            ans.push_back({nums[i], nums[i + 1], nums[i + 2]});
        }
        // Return the list of groups
        return ans;
    }
};