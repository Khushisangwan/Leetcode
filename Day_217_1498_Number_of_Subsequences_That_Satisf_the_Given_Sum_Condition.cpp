#include<bits/stdc++.h>
using namespace std;

// Problem - Number of Subsequences That Satisfy the Given Sum Condition
// Approach - Two Pointers with Precomputed Powers of 2

// Steps:
// 1. Sort the input array.
// 2. Precompute powers of 2 up to the size of the array.
// 3. Use two pointers to find valid subsequences:
//    - One pointer starts from the beginning (left).
//    - The other pointer starts from the end (right).
// 4. If the sum of the elements at these pointers is less than or equal to the target,
//    count all subsequences formed by the elements between these pointers.
// 5. If the sum exceeds the target, move the right pointer leftward.


class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int mod = 1e9 + 7, n = nums.size();
        sort(nums.begin(), nums.end()); // Step 1: Sort the array

        // Step 2: Precompute powers of 2 up to n (for subsequence counts)
        vector<int> power(n, 1);
        for (int i = 1; i < n; ++i) {
            power[i] = (power[i - 1] * 2) % mod;
        }

        int left = 0, right = n - 1, result = 0;

        // Step 3: Two pointers to find valid subsequences
        while (left <= right) {
            // If the sum of the smallest and largest is within target
            if (nums[left] + nums[right] <= target) {
                // All subsequences between left and right are valid
                result = (result + power[right - left]) % mod;
                ++left; // Move left pointer to the right
            } else {
                --right; // Otherwise, move right pointer to the left
            }
        }
        return result; // Return the total count modulo 1e9+7
    }
};