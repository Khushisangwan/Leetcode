#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        // done[i] represents the minimum time to brew potions using first i skills
        vector<long long> done(n + 1, 0);
        
        // Process each mana type
        for (int j = 0; j < m; ++j) {
            // Forward pass: calculate minimum time for each prefix of skills
            for (int i = 0; i < n; ++i) {
                // Either don't use current skill or use it (take max of previous states + cost)
                done[i + 1] = max(done[i + 1], done[i]) + 1LL * mana[j] * skill[i];
            }
            // Backward pass: propagate optimal solutions back
            for (int i = n - 1; i > 0; --i) {
                // Update current state based on next state minus current cost
                done[i] = done[i + 1] - 1LL * mana[j] * skill[i];
            }
        }
        
        // Return minimum time to use all skills
        return done[n];
    }
};