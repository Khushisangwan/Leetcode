#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double max_area = 0.0;
        int n = points.size();
        
        // Try all possible combinations of 3 points to form triangles
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    // Extract coordinates of the three points
                    int x1 = points[i][0], y1 = points[i][1];
                    int x2 = points[j][0], y2 = points[j][1];
                    int x3 = points[k][0], y3 = points[k][1];
                    
                    // Calculate area using the cross product formula
                    // Area = 0.5 * |x1(y2-y3) + x2(y3-y1) + x3(y1-y2)|
                    double area = 0.5 * abs(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2));
                    
                    // Update maximum area found so far
                    max_area = max(max_area, area);
                }
            }
        }
        return max_area;
    }
};