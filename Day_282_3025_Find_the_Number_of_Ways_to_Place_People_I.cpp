#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int ans = 0;
        int n = points.size();

        // Try every pair of points as potential upper-left and lower-right corners
        for (int i = 0; i < n; i++) {
            auto& pointA = points[i]; // Upper-left corner candidate
            for (int j = 0; j < n; j++) {
                vector<int> pointB = points[j]; // Lower-right corner candidate
                
                // Skip if same point or if pointB is not lower-right of pointA
                if (i == j ||
                    !(pointA[0] <= pointB[0] && pointA[1] >= pointB[1])) {
                    continue;
                }
                
                // Special case: if only 2 points, any valid rectangle is counted
                if (n == 2) {
                    ans++;
                    continue;
                }

                // Check if any other point lies strictly inside the rectangle
                bool illegal = false;
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) {
                        continue;
                    }

                    auto& pointTmp = points[k];
                    // Check if point k is within the rectangle boundaries
                    bool isXContained =
                        pointTmp[0] >= pointA[0] && pointTmp[0] <= pointB[0];
                    bool isYContained =
                        pointTmp[1] <= pointA[1] && pointTmp[1] >= pointB[1];
                    
                    // If point is inside rectangle, this pair is invalid
                    if (isXContained && isYContained) {
                        illegal = true;
                        break;
                    }
                }
                
                // Count valid rectangle if no points inside
                if (!illegal) {
                    ans++;
                }
            }
        }
        return ans;
    }
};