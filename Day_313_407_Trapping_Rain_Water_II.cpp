#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        // Define a tuple to store height and coordinates for priority queue
        using HeightAndCoordinates = tuple<int, int, int>;

        // Min heap to process cells from lowest to highest height
        priority_queue<HeightAndCoordinates, vector<HeightAndCoordinates>, greater<HeightAndCoordinates>> min_heap;

        int rows = heightMap.size(), cols = heightMap[0].size();

        // Track visited cells to avoid reprocessing
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        // Add all boundary cells to the heap as they cannot trap water
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                    min_heap.emplace(heightMap[i][j], i, j);
                    visited[i][j] = true;
                }
            }
        }

        int trapped_water = 0;

        // Direction vectors for 4-directional movement (up, right, down, left)
        const int directions[5] = {-1, 0, 1, 0, -1};

        // Process cells from lowest height to highest using Dijkstra-like approach
        while (!min_heap.empty()) {
            auto [current_height, row, col] = min_heap.top();
            min_heap.pop();

            // Check all 4 adjacent cells
            for (int k = 0; k < 4; ++k) {
                int new_row = row + directions[k];
                int new_col = col + directions[k + 1];

                // Validate bounds and check if cell is unvisited
                if (new_row >= 0 && new_row < rows && new_col >= 0 && new_col < cols && !visited[new_row][new_col]) {
                    // Calculate trapped water: difference between current water level and ground height
                    trapped_water += max(0, current_height - heightMap[new_row][new_col]);

                    visited[new_row][new_col] = true;

                    // Add cell to heap with water level (max of ground height and current water level)
                    min_heap.emplace(max(heightMap[new_row][new_col], current_height), new_row, new_col);
                }
            }
        }

        return trapped_water;       
    }
};