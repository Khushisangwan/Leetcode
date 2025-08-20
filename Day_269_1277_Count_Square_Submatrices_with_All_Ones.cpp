#include <bits/stdc++.h>
using namespace std;

// Problem: Count the number of square submatrices with all ones in a given binary matrix.
// Approach: Use dynamic programming to keep track of the size of the largest square submatrix ending at each cell.

// Steps:
// 1. Initialize a variable to store the number of square submatrices.
// 2. Iterate through each cell in the matrix.
// 3. If the cell contains a 1 and is not in the first row or first column, update its value to be the minimum of the values from the top, left, and top-left cells plus one.
// 4. Add the value of the current cell to the total count, as it represents the number of square submatrices ending at that cell.
// 5. Return the total count of square submatrices.

// Time Complexity: O(m * n) where m is the number of rows and n is the number of columns in the matrix.
// Space Complexity: O(1) since we are modifying the input matrix in place.

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        int res = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1 && i > 0 && j > 0) {
                    matrix[i][j] = min({matrix[i-1][j], matrix[i][j-1], matrix[i-1][j-1]}) + 1;
                }
                res += matrix[i][j];
            }
        }
        return res;
    }
};