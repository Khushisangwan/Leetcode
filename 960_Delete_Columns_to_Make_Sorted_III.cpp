#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        // n = number of columns, m = number of rows
        int n = (int)strs[0].size();
        int m = (int)strs.size();
        
        // dp[i] = length of longest increasing subsequence of columns ending at column i
        vector<int> dp(n, 1);

        // For each column i, check all previous columns j
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                // Check if column j can come before column i
                // (all rows must be non-decreasing from column j to i)
                bool ok = true;
                for (int r = 0; r < m; r++) {
                    if (strs[r][j] > strs[r][i]) { 
                        ok = false; 
                        break; 
                    }
                }
                // Update dp[i] with the longest valid subsequence
                if (ok) dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        // Find the maximum length of valid column subsequence
        int mx = 0;
        for (int v : dp) mx = max(mx, v);
        
        // Return number of columns to delete
        return n - mx;
    }
};