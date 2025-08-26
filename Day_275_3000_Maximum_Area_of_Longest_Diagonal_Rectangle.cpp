#include <bits/stdc++.h>
using namespace std;

// Problem: Find the maximum area of a rectangle with the longest diagonal
// Approach: Iterate through all rectangles, calculate their diagonal and area, and keep track of the maximum area for the longest diagonal.

// Steps:
// 1. Initialize variables to keep track of the maximum area and diagonal.
// 2. Iterate through each rectangle's dimensions.
// 3. For each rectangle, calculate its diagonal and area.
// 4. Update the maximum area if the current rectangle has a longer diagonal or a larger area for the same diagonal.
// 5. Return the maximum area found.

// Time Complexity: O(n), where n is the number of rectangles
// Space Complexity: O(1)

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxArea = 0, maxDiag = 0;

        for (int i = 0; i < dimensions.size(); i++) {
            int l = dimensions[i][0];
            int w = dimensions[i][1];
            int currDiag = l * l + w * w;

            if (currDiag > maxDiag || (currDiag == maxDiag && l * w > maxArea)) {
                maxDiag = currDiag;
                maxArea = l * w;
            }
        }
        return maxArea;
    }
};