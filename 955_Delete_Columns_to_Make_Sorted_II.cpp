#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();

        // resolved[i] indicates that strs[i] < strs[i+1] is already guaranteed
        vector<bool> resolved(n - 1, false);
        // Track how many adjacent pairs still need to be resolved
        int unresolved = n - 1;
        int deletions = 0;

        // Process each column from left to right
        for (int col = 0; col < m && unresolved > 0; col++) {
            bool bad = false;

            // Check if this column violates lexicographical order for any unresolved pair
            for (int i = 0; i < n - 1; i++) {
                if (!resolved[i] && strs[i][col] > strs[i + 1][col]) {
                    bad = true;
                    break;
                }
            }

            // If violation found, delete this column
            if (bad) {
                deletions++;
                continue;
            }

            // Mark pairs as resolved where this column strictly orders them
            for (int i = 0; i < n - 1; i++) {
                if (!resolved[i] && strs[i][col] < strs[i + 1][col]) {
                    resolved[i] = true;
                    unresolved--;
                }
            }
        }

        return deletions;
    }
};