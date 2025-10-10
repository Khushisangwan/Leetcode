#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> dp(n);  // dp[i] stores maximum energy obtainable starting from index i
        int result = INT_MIN;  // Track the maximum energy across all possible starting positions
        
        // Work backwards from the end of the array
        for (int i = n - 1; i >= 0; --i) {
            // Current position energy + maximum energy from position i+k (if valid)
            dp[i] = energy[i] + ((i + k < n) ? dp[i + k] : 0);
            // Update global maximum
            result = max(result, dp[i]);
        }
        return result;
    }
};