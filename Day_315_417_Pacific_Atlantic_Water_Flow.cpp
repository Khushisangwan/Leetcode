#include <bits/stdc++.h>
using namespace std;
uint8_t status[40000];
int dir[5]={0, 1, 0, -1, 0};

class Solution {
public:
    int m, n;
    
    // Check if coordinates are outside the grid boundaries
    inline bool isOutside(int i, int j) {
        return i < 0 || i >= m || j < 0 || j >= n;
    }
    
    // Convert 2D coordinates to 1D index
    inline int idx(int i, int j) { return i * n + j; }

    // BFS to mark cells reachable from ocean borders
    void bfs(queue<int>& q, vector<vector<int>>& heights, uint8_t mark) {
        while (!q.empty()) {
            int ij = q.front();
            q.pop();
            auto [i, j] = div(ij, n); // Convert 1D index back to 2D coordinates
            
            // Check all 4 directions
            for (int a = 0; a < 4; a++) {
                int r = i + dir[a], s = j + dir[a + 1];
                if (isOutside(r, s)) continue;
                
                int rs = idx(r, s);
                // Skip if already marked or water can't flow (height is lower)
                if ((status[rs] & mark) || heights[r][s] < heights[i][j])
                    continue;
                    
                status[rs] |= mark; // Mark cell as reachable
                q.push(rs);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        memset(status, 0, m * n); // Initialize status array

        queue<int> pac, atl;
        
        // Pacific Ocean: Initialize top row and left column
        for (int j = 0; j < n; j++) {
            status[idx(0, j)] |= 1; // Mark as Pacific reachable (bit 0)
            pac.push(idx(0, j));
        }
        for (int i = 1; i < m; i++) {
            status[idx(i, 0)] |= 1;
            pac.push(idx(i, 0));
        }
        
        // Atlantic Ocean: Initialize bottom row and right column
        for (int j = 0; j < n; j++) {
            status[idx(m-1, j)] |= 2; // Mark as Atlantic reachable (bit 1)
            atl.push(idx(m-1, j));
        }
        for (int i = 0; i < m-1; i++) {
            status[idx(i, n-1)] |= 2;
            atl.push(idx(i, n-1));
        }

        // Run BFS from both oceans
        bfs(pac, heights, 1); // Pacific BFS
        bfs(atl, heights, 2); // Atlantic BFS

        // Collect cells reachable from both oceans (status == 3)
        vector<vector<int>> ans;
        for (int ij = 0; ij < m * n; ij++) {
            if (status[ij] == 3) { // Both bits set (1 | 2 = 3)
                auto [i, j] = div(ij, n);
                ans.push_back({i, j});
            }
        }
        return ans;
    }
};