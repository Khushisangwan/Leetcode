#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        
        // Process each query [l, r]
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            long long S = 0;  // Total sum of steps needed
            int dMax = 0;     // Maximum steps for any single number
            
            // Check each bit position k (numbers 2^(k-1) to 2^k - 1)
            for (int k = 1; k <= 31; k++) {
                long long low = 1LL << (k - 1);    // Start of range for k bits
                long long high = (1LL << k) - 1;   // End of range for k bits
                
                // If range starts beyond our query range, break
                if (low > r) break;
                
                // Find intersection of [low, high] with [l, r]
                long long a = max((long long)l, low);
                long long b = min((long long)r, high);
                
                // Skip if no intersection
                if (a > b) continue;
                
                long long cnt = b - a + 1;  // Count of numbers in intersection
                int stepsForK = (k + 1) / 2;  // Steps needed to make k-bit number zero
                
                S += cnt * stepsForK;  // Add to total sum
                dMax = max(dMax, stepsForK);  // Update maximum steps
            }
            
            // Minimum operations is max of: max steps for any number, or ceiling(total_sum/2)
            long long ops = max((long long)dMax, (S + 1) / 2);
            ans += ops;
        }
        return ans;
    }
};