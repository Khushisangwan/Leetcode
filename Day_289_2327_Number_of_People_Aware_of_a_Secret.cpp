#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        // dp[i] represents number of people who learned the secret on day i
        vector<long long> dp(n + 1, 0);
        dp[1] = 1; // On day 1, 1 person knows the secret
        
        long long share = 0; // Number of people currently sharing the secret
        long long MOD = 1000000007;
        
        for (int t = 2; t <= n; t++) {
            // Add people who start sharing (after delay period)
            if (t - delay > 0)
                share = (share + dp[t - delay] + MOD) % MOD;
            
            // Remove people who forget the secret (after forget period)
            if (t - forget > 0)
                share = (share - dp[t - forget] + MOD) % MOD;
            
            // Number of new people learning the secret on day t
            dp[t] = share;
        }
        
        // Count total people who know the secret on day n
        // (those who learned in the last 'forget' days)
        long long know = 0;
        for (int i = n - forget + 1; i <= n; i++)
            know = (know + dp[i]) % MOD;
        
        return (int)know;
    }
};