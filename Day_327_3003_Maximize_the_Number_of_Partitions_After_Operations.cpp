#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    typedef long long ll;
    unordered_map<long long, int> dp; // Memoization map
    
    // Recursive function to find maximum partitions
    // i: current index, mask: bitmask of characters seen, change: whether we've used our change operation, k: max distinct chars per partition
    ll solve(ll i, ll mask, ll change, int k, string& s) {

        int n = s.size();
        // Base case: reached end of string
        if (i == n) {
            return 1;
        }

        // Create unique state for memoization: combine index, mask, and change flag
        ll currState = (i << 27) | (mask << 1) | (change);

        // Return cached result if exists
        if (dp.find(currState) != dp.end()) {
            return dp[currState];
        }

        // Get character value and update mask
        int val = s[i] - 'a';
        ll newMask = mask | (1 << val);

        // Count distinct characters in current partition
        int count = __builtin_popcount(newMask);

        ll ans = 0;
        ll maxi = 0;

        // Check if adding current character exceeds k distinct characters
        if (count > k) {
            // Start new partition
            ans = 1 + solve(i + 1, 1 << val, change, k, s);
            maxi = max(maxi, ans);
        } else {
            // Continue current partition
            ans = solve(i + 1, newMask, change, k, s);
            maxi = max(maxi, ans);
        }

        // If we've already used our change operation, return result
        if (change) {
            return dp[currState] = maxi;
        }

        // Try changing current character to any of 26 possible characters
        for (int j = 0; j < 26; j++) {

            ll newMask = mask | (1 << j);
            ll count = __builtin_popcount(newMask);

            // Check if changing to character j would exceed k distinct characters
            if (count > k) {
                // Start new partition with changed character
                maxi = max(maxi, 1 + solve(i + 1, 1 << j, 1, k, s));
            } else {
                // Continue current partition with changed character
                maxi = max(maxi, solve(i + 1, newMask, 1, k, s));
            }
        }

        return dp[currState] = maxi;
    }
    
    // Main function to find maximum partitions after operations
    int maxPartitionsAfterOperations(string s, int k) {
        return solve(0, 0, 0, k, s);
    }
};