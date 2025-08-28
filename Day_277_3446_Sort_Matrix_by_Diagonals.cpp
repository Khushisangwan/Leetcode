#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        // Use max heaps for diagonals with non-negative keys (i-j >= 0)
        unordered_map<int, priority_queue<int>> maxHeaps;
        // Use min heaps for diagonals with negative keys (i-j < 0)
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> minHeaps;

        // First pass: collect elements from each diagonal
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int key = i - j; // Diagonal identifier: same diagonal has same i-j value
                if (key < 0) minHeaps[key].push(grid[i][j]);
                else maxHeaps[key].push(grid[i][j]);
            }
        }

        // Second pass: place sorted elements back into the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int key = i - j;
                if (key < 0) {
                    // Get smallest element from min heap (ascending order)
                    grid[i][j] = minHeaps[key].top();
                    minHeaps[key].pop();
                } else {
                    // Get largest element from max heap, but we process in traversal order
                    // This effectively gives us descending order for this diagonal
                    grid[i][j] = maxHeaps[key].top();
                    maxHeaps[key].pop();
                }
            }
        }
        return grid;
    }
};