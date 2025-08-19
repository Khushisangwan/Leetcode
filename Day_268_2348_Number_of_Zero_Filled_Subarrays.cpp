#include <bits/stdc++.h>
using namespace std;

// Problem: Count the number of zero-filled subarrays in a given array.
// Approach: Iterate through the array, maintaining a count of consecutive zeros.

// Steps:
// 1. Initialize a counter for the total number of zero-filled subarrays and a streak counter for consecutive zeros.
// 2. Traverse the array, checking each element.
// 3. If the element is zero, increment the streak counter and add it to the total count.
// 4. If the element is not zero, reset the streak counter to zero.
// 5. Return the total count of zero-filled subarrays.

// Time Complexity: O(n) where n is the number of elements in the array.
// Space Complexity: O(1) since we are using a constant amount of extra space.

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long cnt = 0, streak = 0;
        for (int num : nums) {
            if (num == 0) {
                streak++;
                cnt += streak;
            } else {
                streak = 0;
            }
        }
        return cnt;
    }
};