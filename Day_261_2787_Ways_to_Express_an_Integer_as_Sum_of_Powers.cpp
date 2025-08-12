#include <vector>
using namespace std;
// Problem: 2787 Ways to Express an Integer as Sum of Powers
// Approach: Dynamic programming to count ways to express n as a sum of powers of integers raised to x.

// Time Complexity: O(n * log n) where n is the target integer and log n is the number of powers considered.
// Space Complexity: O(n) for the dp array.
// Note: The solution uses modular arithmetic to handle large numbers.

static const int MOD = 1'000'000'007;

class Solution {
public:
    int numberOfWays(int n, int x) {
        // collect powers i^x <= n
        vector<int> powers;
        for (int i = 1; ; ++i) {
            long long p = 1;
            for (int k = 0; k < x; ++k) p *= i;
            if (p > n) break;
            powers.push_back((int)p);
        }

        vector<long long> dp(n + 1, 0);
        dp[0] = 1;
        for (int p : powers) {
            for (int s = n; s >= p; --s) {
                dp[s] = (dp[s] + dp[s - p]) % MOD;
            }
        }
        return (int)dp[n];
    }
};