#include <bits/stdc++.h>
using namespace std;
// Solution class to solve the Triangle minimum path sum problem
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // Start from the second last row and move upwards
        for (int i = triangle.size() - 2; i >= 0; i--)
            // For each element in the current row
            for (int j = 0; j < triangle[i].size(); j++)
                // Add the minimum of the two adjacent numbers from the row below
                triangle[i][j] +=
                    min(triangle[i + 1][j], triangle[i + 1][j + 1]);

        // The top element contains the minimum path sum
        return triangle[0][0];
    }
};