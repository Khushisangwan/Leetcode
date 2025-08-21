#include <bits/stdc++.h>
using namespace std;

// Problem: Count the number of submatrices with all ones in a given binary matrix.
// Approach: Use dynamic programming to calculate the height of consecutive ones in each column and then count
//           the number of submatrices that can be formed using these heights.

// Steps:
// 1. Initialize a vector to keep track of the height of consecutive ones for each column
// 2. Iterate through each row of the matrix.
// 3. For each cell, if it contains a 1, increment the height for that column; if it contains a 0, reset the height to 0.
// 4. For each row, iterate through the columns and calculate the number of submat rices that can be formed using the heights.
// 5. For each column, maintain a minimum height while iterating backwards to count the number of submatrices.
// 6. Return the total count of submatrices with all ones.

// Time Complexity: O(m * n^2) where m is the number of rows and n is the number of columns in the matrix.
// Space Complexity: O(n) for the height vector.

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> height(n, 0);
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0)
                    height[j] = 0;
                else
                    height[j] += 1;
            }

            for (int j = 0; j < n; j++) {
                int min_h = height[j];
                for (int k = j; k >= 0 && min_h > 0; k--) {
                    min_h = min(min_h, height[k]);
                    ans += min_h;
                }
            }
        }

        return ans;
    }
};