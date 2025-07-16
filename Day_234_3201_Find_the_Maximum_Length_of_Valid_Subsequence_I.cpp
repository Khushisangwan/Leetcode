#include<bits/stdc++.h>
using namespace std;
// Problem: Find the maximum length of a valid subsequence where the subsequence alternates between even and odd numbers.
// Approach: Use dynamic programming to keep track of the maximum lengths of subsequences ending with even
// and odd numbers. Iterate through the array and update the lengths based on the current number's parity.
// Steps:
// 1. Initialize two variables to keep track of the maximum lengths of subsequences ending with
//    even and odd numbers.
// 2. Iterate through the array of integers.
// 3. For each number, check if it is even or odd.
// 4. If it is even, update the maximum length of the subsequence ending with an even number
//    by taking the maximum of the current even length and the odd length plus one.
// 5. If it is odd, update the maximum length of the subsequence ending with an odd number
//    by taking the maximum of the current odd length and the even length plus one.
// 6. After processing all numbers, return the maximum of the lengths of subsequences ending with even and odd numbers.


class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int count_even = 0, count_odd = 0;
        for (int num : nums) {
            if (num % 2 == 0) count_even++;
            else count_odd++;
        }

        int even_dp = 0, odd_dp = 0;
        for (int num : nums) {
            if (num % 2 == 0)
                even_dp = max(even_dp, odd_dp + 1);
            else
                odd_dp = max(odd_dp, even_dp + 1);
        }

        return max({count_even, count_odd, even_dp, odd_dp});
    }
};