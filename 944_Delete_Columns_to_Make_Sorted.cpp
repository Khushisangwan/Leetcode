#include<bits/stdc++.h>
using namespace std;
class Solution {
    // Helper function to check if a column is unsorted (not in non-decreasing order)
    bool isUnsorted(const vector<string>& strs, int j) {
        // Compare each character in column j with the previous row
        for (int i = 1; i < strs.size(); i++)
            if (strs[i][j] < strs[i - 1][j])
                return true;
        return false;
    }

public:
    // Count the number of columns that need to be deleted to make all columns sorted
    int minDeletionSize(vector<string>& strs) {
        int res = 0;
        // Iterate through each column
        for (int j = 0; j < strs[0].size(); j++)
            // Increment count if column is unsorted
            res += isUnsorted(strs, j);
        return res;
    }
};