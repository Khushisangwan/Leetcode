#include<bits/stdc++.h>
using namespace std;
// Problem: Generate Pascal's Triangle up to a given number of rows.
// Approach: Use a nested loop to build each row based on the previous row's values.
// Steps:
// 1. Initialize a vector to hold the triangle.
// 2. Start with the first row containing a single element 1.
// 3. For each subsequent row, start with 1, then compute the inner values as the sum of two values from the previous row.
// 4. End each row with 1.
// 5. Return the complete triangle as a vector of vectors.
// Time Complexity: O(numRows^2) since each row takes linear time to build.
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        triangle.push_back({1});

        for (int rowNum = 1; rowNum < numRows; ++rowNum) {
            vector<int> row;
            vector<int>& prevRow = triangle[rowNum - 1];

            row.push_back(1);

            for (int j = 1; j < rowNum; ++j) {
                row.push_back(prevRow[j - 1] + prevRow[j]);
            }

            row.push_back(1);
            triangle.push_back(row);
        }

        return triangle;
    }
};