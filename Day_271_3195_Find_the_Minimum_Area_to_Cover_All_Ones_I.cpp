#include<bits/stdc++.h>
using namespace std;
// Problem: Find the minimum area of a rectangle that can cover all the 1s in a binary grid.
// Approach: Traverse the grid to find the minimum and maximum row and column indices of 1s, then calculate the area of the rectangle formed by these indices.
// Steps:
// 1. Initialize variables to track the minimum and maximum row and column indices of 1s.
// 2. Traverse the grid to update these indices whenever a 1 is encountered.
// 3. Calculate the area of the rectangle using the formula: (maxRow - minRow + 1) * (maxCol - minCol + 1).
// 4. Return the calculated area.
// Time Complexity: O(m * n) where m is the number of rows and n is
// Space Complexity: O(1) as we are using a constant amount of extra space.
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int minRow = m, maxRow = -1;
        int minCol = n, maxCol = -1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    minRow = min(minRow, i);
                    maxRow = max(maxRow, i);
                    minCol = min(minCol, j);
                    maxCol = max(maxCol, j);
                }
            }
        }
        return (maxRow - minRow + 1) * (maxCol - minCol + 1);
    }
};