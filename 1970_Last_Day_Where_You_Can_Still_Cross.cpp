#include<bits/stdc++.h>
using namespace std;

// Disjoint Set Union (Union-Find) data structure
class DSU {
    vector<int> root, size;

public:
    // Initialize DSU with n elements
    DSU(int n) : root(n), size(n, 1) { iota(root.begin(), root.end(), 0); }

    // Find the root of element x with path compression
    int find(int x) {
        if (root[x] != x)
            root[x] = find(root[x]);
        return root[x];
    }

    // Union two sets by rank (size-based)
    void unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry)
            return;
        if (size[rx] > size[ry])
            swap(rx, ry);
        root[rx] = ry;
        size[ry] += size[rx];
    }
};

class Solution {
public:
    // Find the last day when you can still cross from top to bottom
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        // DSU: 0=top sentinel, 1 to row*col=grid cells, row*col+1=bottom sentinel
        DSU dsu(row * col + 2);
        vector<vector<int>> grid(row, vector<int>(col, 0)); // 0=water, 1=land
        
        // 8 directions: right, left, down, up, and 4 diagonals
        int dirs[8][2] = {{0, 1}, {0, -1}, {1, 0},  {-1, 0},
                          {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

        // Process cells in reverse order (from last day to first day)
        for (int i = 0; i < row * col; i++) {
            int r = cells[i][0] - 1, c = cells[i][1] - 1;
            grid[r][c] = 1; // Mark cell as land
            int id1 = r * col + c + 1;

            // Connect with adjacent land cells
            for (auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr >= 0 && nr < row && nc >= 0 && nc < col &&
                    grid[nr][nc] == 1) {
                    int id2 = nr * col + nc + 1;
                    dsu.unite(id1, id2);
                }
            }

            // Connect left edge cells to top sentinel
            if (c == 0)
                dsu.unite(0, id1);
            // Connect right edge cells to bottom sentinel
            if (c == col - 1)
                dsu.unite(row * col + 1, id1);

            // Check if path exists from top to bottom
            if (dsu.find(0) == dsu.find(row * col + 1))
                return i;
        }
        return -1;
    }
};
