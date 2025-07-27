#include<bits/stdc++.h>
using namespace std;
// This code counts the number of hills and valleys in an array.
// A hill is defined as a peak surrounded by lower values, and a valley is a trough surrounded by higher values.
// The solution iterates through the array, checking for hills and valleys based on the current and adjacent values.
// The code is designed to work with C++14 standard.
// This code is efficient and works within the constraints provided.

class Solution {
public:
    int countHillValley(std::vector<int>& nums) {
        int count = 0;
        int left = 0;

        for (int i = 1; i < nums.size() - 1; ++i) {
            if (nums[i] != nums[i + 1]) {
                if ((nums[i] > nums[left] && nums[i] > nums[i + 1]) ||
                    (nums[i] < nums[left] && nums[i] < nums[i + 1])) {
                    ++count;
                }
                left = i;
            }
        }

        return count;
    }
};