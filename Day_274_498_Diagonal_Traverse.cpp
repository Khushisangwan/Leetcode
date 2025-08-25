#include <bits/stdc++.h>
using namespace std;

// Problem: Given a matrix, return all elements of the matrix in diagonal order.
// Approach: Use a single loop to traverse the matrix while maintaining the current position (row, col).
//           Change direction based on the sum of the current indices (row + col).  
// Steps:
// 1. Initialize variables for the number of rows (m), columns (n), and a result vector.
// 2. Use a loop to iterate through all elements of the matrix.
// 3. Depending on whether the sum of the current indices is even or odd, move in the appropriate diagonal direction.
// 4. Handle boundary conditions to ensure the traversal stays within the matrix.
// 5. Return the result vector after processing all elements.

// Time Complexity: O(m * n) where m is the number of rows and n is the number of columns in the matrix.
// Space Complexity: O(1) additional space, excluding the output array.

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};

        int m = matrix.size(), n = matrix[0].size();
        vector<int> result(m * n);
        int row = 0, col = 0;

        for (int i = 0; i < m * n; i++) {
            result[i] = matrix[row][col];

            if ((row + col) % 2 == 0) {
                if (col == n - 1) row++;
                else if (row == 0) col++;
                else { row--; col++; }
            } else {
                if (row == m - 1) col++;
                else if (col == 0) row++;
                else { row++; col--; }
            }
        }

        return result;
    }
};