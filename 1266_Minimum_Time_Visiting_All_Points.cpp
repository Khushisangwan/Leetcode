#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& p) {
        int ans = 0;
        // Iterate through each point starting from the second one
        for (int i = 1; i < p.size(); i++) {
            // Calculate the Chebyshev distance (max of absolute differences)
            // This represents the minimum time to move from one point to another
            ans += max(
                abs(p[i][0] - p[i - 1][0]),  // Horizontal distance
                abs(p[i][1] - p[i - 1][1])   // Vertical distance
            );
        }
        return ans;
    }
};