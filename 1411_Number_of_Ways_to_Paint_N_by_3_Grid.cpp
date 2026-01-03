#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Recursive function to count valid ways to paint the grid
    // i: current row, n: total rows, prev1/prev2/prev3: colors of previous row
    // mod: modulo value, dp: memoization table
    int solve(int i, int n, int prev1, int prev2, int prev3, int mod,
              vector<vector<vector<vector<int>>>>& dp) {
        // Base case: all rows painted
        if (i == n) {
            return 1;
        }
        // Return memoized result if available
        if (dp[i][prev1][prev2][prev3] != -1) {
            return dp[i][prev1][prev2][prev3];
        }
        
        int ans = 0;
        // Try all valid colors for column 1 (must differ from previous row)
        for (int col1 = 1; col1 <= 3; col1++) {
            if (col1 == prev1) {
                continue;
            }
            // Try all valid colors for column 2 (must differ from col1 and prev2)
            for (int col2 = 1; col2 <= 3; col2++) {
                if (col2 == prev2 || col2 == col1) {
                    continue;
                }
                // Try all valid colors for column 3 (must differ from col2 and prev3)
                for (int col3 = 1; col3 <= 3; col3++) {
                    if (col3 == prev3 || col3 == col2) {
                        continue;
                    }
                    // Recursively solve for next row and accumulate result
                    ans = (ans + solve(i + 1, n, col1, col2, col3, mod, dp)) %
                          mod;
                }
            }
        }
        // Store and return the result
        return dp[i][prev1][prev2][prev3] = ans;
    }
    
    int numOfWays(int n) {
        int mod = 1e9 + 7;
        // Initialize DP table with -1 for memoization
        vector<vector<vector<vector<int>>>> dp(
            n, vector<vector<vector<int>>>(
                   4, vector<vector<int>>(4, vector<int>(4, -1))));
        // Start solving from row 0 with no previous constraints
        return solve(0, n, 0, 0, 0, mod, dp);
    }
};