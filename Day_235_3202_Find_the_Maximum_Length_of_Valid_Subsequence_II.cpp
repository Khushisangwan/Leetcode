#include <bits/stdc++.h>
using namespace std;

// Problem: Find the maximum length of a valid subsequence where the subsequence has a specific modulo constraint.
// Approach: Use dynamic programming to keep track of the maximum lengths of subsequences based on modulo
// constraints. Iterate through the array and update the lengths based on the current number's modulo value.

// Steps:
// 1. Initialize a variable to keep track of the maximum length of valid subsequences.
// 2. Create a vector to store the maximum lengths of subsequences for each modulo value.
// 3. Iterate through the array of integers.
// 4. For each number, calculate its modulo with respect to a given value k.
// 5. Update the maximum length of the subsequence for that modulo value by considering the
//    maximum length of the subsequence for the complementary modulo value plus one.
// 6. After processing all numbers, return the maximum length found.

// Time Complexity: O(n * k), where n is the number of elements in the array and k is the modulo value.
// Space Complexity: O(k), where k is the modulo value.

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        short ans=0;
        vector<short> dp;
        for (int i=0; i<k; i++){
            dp.assign(k, 0);
            for (int x : nums){
                int j=x%k;
                dp[j]=max(dp[j], short(dp[(i+k-j)%k]+1));
                ans=max(ans, dp[j]);
            }
        }
        return ans;
        
    }
};