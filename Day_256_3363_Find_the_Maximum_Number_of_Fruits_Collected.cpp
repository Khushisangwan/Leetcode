#inlcude <bits/stdc++.h
using namespace std;

// Problem: Find the Maximum Number of Fruits Collected
// Approach: Use dynamic programming to calculate the maximum fruits collected from a grid.

// Steps:   
// 1. Iterate through the grid and calculate the maximum fruits collected from each cell.
// 2. Use two passes: one for the original grid and another for the transposed grid.
// 3. Maintain a previous and current state to track the maximum fruits collected at each step.
// 4. Return the total maximum fruits collected after both passes.

// Time Complexity: O(n^2) where n is the size of the grid, as we iterate through each cell multiple times. 
// Space Complexity: O(n) for the previous and current state arrays.

class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& grid) {
        int n = grid.size(), res = 0;

        for (int i = 0; i < n; i++) {
            res += grid[i][i];
        }

        for (int pass = 0; pass < 2; pass++) {
            if (pass == 1) {
                for (int i = 0; i < n; i++) {
                    for (int j = i + 1; j < n; j++) {
                        swap(grid[i][j], grid[j][i]);
                    }
                }
            }

            vector<int> prev(n, -1), curr(n, -1);
            prev[n - 1] = grid[0][n - 1];

            for(int row = 1; row < n - 1; row++) {
                fill(curr.begin(), curr.end(), -1);
                for (int i = 0; i < n; i++) {
                    if (prev[i] < 0) continue;
                    if (i > 0) 
                        curr[i - 1] = max(curr[i - 1], prev[i] + grid[row][i - 1]);
                    if (i < n - 1) 
                        curr[i + 1] = max(curr[i + 1], prev[i] + grid[row][i + 1]);
                    curr[i] = max(curr[i], prev[i] + grid[row][i]);
                }
                swap(prev, curr);
            }
            res += prev[n - 1];
        }
        return res;
    }
};