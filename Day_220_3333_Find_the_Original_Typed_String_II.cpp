#include <bits/stdc++.h>
using namespace std;    

// Problem - Find the Original Typed String II
// Approach - Count the number of ways to form a string with k groups of consecutive characters 

// Steps:
// 1. Count the number of groups of consecutive characters in the input string.
// 2. Calculate the total number of ways to form a string with these groups.    
// 3. Use dynamic programming to count the number of valid strings with exactly k groups.
// 4. Return the total count modulo 1e9 + 7.

// Time Complexity: O(n * k), where n is the length of the input string and k is the number of groups.
// Space Complexity: O(k), for the dynamic programming array.

class Solution {
public:
    const int MOD = 1e9 + 7;

    // Returns the number of ways to form a string with exactly k groups of consecutive characters
    int possibleStringCount(string word, int k) {
        if (word.empty()) return 0;

        vector<int> groups;
        int count = 1;

        // Count the size of each group of consecutive characters
        for (int i = 1; i < word.size(); i++) {
            if (word[i] == word[i - 1])
                count++;
            else {
                groups.push_back(count);
                count = 1;
            }
        }
        groups.push_back(count); // Add the last group

        // Calculate the total number of ways to form the string (product of group sizes)
        long total = 1;
        for (int g : groups)
            total = (total * g) % MOD;

        // If k is less than or equal to the number of groups, return total
        if (k <= groups.size()) return total;

        // Dynamic programming to count valid strings with exactly k groups
        vector<int> dp(k, 0);
        dp[0] = 1;

        for (int g : groups) {
            vector<int> new_dp(k, 0);
            long sum = 0;
            for (int s = 0; s < k; s++) {
                if (s > 0)
                    sum = (sum + dp[s - 1]) % MOD;
                if (s > g)
                    sum = (sum - dp[s - g - 1] + MOD) % MOD;
                new_dp[s] = sum;
            }
            dp = new_dp;
        }

        // Subtract invalid cases where the number of groups exceeds the original
        long invalid = 0;
        for (int s = groups.size(); s < k; s++)
            invalid = (invalid + dp[s]) % MOD;

        return (total - invalid + MOD) % MOD;
    }
};