#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        // m and n are the lengths of s1 and s2
        int m = s1.size(), n = s2.size();
        // dp[i][j] = minimum ASCII delete sum for s1[0..i-1] and s2[0..j-1]
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        // Initialize first row: delete all characters from s2
        for (int j = 1; j <= n; j++)
            dp[0][j] = dp[0][j-1] + s2[j-1];
        
        // Fill the dp table
        for (int i = 1; i <= m; i++) {
            // Initialize first column: delete all characters from s1
            dp[i][0] = dp[i-1][0] + s1[i-1];
            
            for (int j = 1; j <= n; j++) {
                // If characters match, no deletion needed
                if (s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                // Otherwise, delete from either s1 or s2 (choose minimum)
                else 
                    dp[i][j] = min(dp[i-1][j] + s1[i-1], dp[i][j-1] + s2[j-1]);
            }
        }
        // Return the minimum delete sum for both strings
        return dp[m][n];
    }
};