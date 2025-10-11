#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        // Count frequency of each power value
        unordered_map<int, long long> freq;
        for (int p : power) freq[p]++;
        
        // Extract unique power values and sort them
        vector<int> keys;
        for (auto& [k, _] : freq) keys.push_back(k);
        sort(keys.begin(), keys.end());
        
        int n = keys.size();
        // dp[i] represents maximum damage using powers from keys[0] to keys[i]
        vector<long long> dp(n);
        
        // Base case: only first power value
        dp[0] = freq[keys[0]] * keys[0];
        
        for (int i = 1; i < n; i++) {
            // Damage if we take current power (all spells with this power)
            long long take = freq[keys[i]] * keys[i];
            
            // Find last power that can be used with current power (difference >= 3)
            int prev = upper_bound(keys.begin(), keys.begin() + i, keys[i] - 3) - keys.begin() - 1;
            if (prev >= 0) take += dp[prev];
            
            // Take maximum of including or excluding current power
            dp[i] = max(dp[i - 1], take);
        }
        
        return dp[n - 1];
    }
};