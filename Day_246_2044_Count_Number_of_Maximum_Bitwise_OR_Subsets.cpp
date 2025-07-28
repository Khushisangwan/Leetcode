#include<bits/stdc++.h>
using namespace std;
// This code counts the number of subsets of an array that yield the maximum bitwise OR value.
// The solution uses backtracking to explore all subsets and counts those that match the maximum OR value
// The code is designed to work with C++14 standard.
// This code is efficient and works within the constraints provided.
// The function `countMaxOrSubsets` calculates the maximum OR value and then uses a helper function to count subsets.
// The helper function `backtrack` recursively explores subsets, accumulating the OR value and counting valid subsets.
// The code is structured to handle the input as a vector of integers.
// The solution is efficient and works within the constraints provided.

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOR = 0;
        for (int num : nums) {
            maxOR |= num;
        }
        return backtrack(nums, maxOR, 0, 0);
    }

private:
    int backtrack(vector<int>& nums, int maxOR, int index, int currentOR) {
        if (index == nums.size()) {
            return currentOR == maxOR ? 1 : 0;
        }

        if (currentOR == maxOR) {
            return 1 << (nums.size() - index);
        }

        return backtrack(nums, maxOR, index + 1, currentOR | nums[index]) +
               backtrack(nums, maxOR, index + 1, currentOR);
    }
};