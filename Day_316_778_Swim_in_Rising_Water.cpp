//Greedy & Union Find
#include <bits/stdc++.h>
using namespace std;
class UnionFind {    
    vector<int> root, rank;  // root stores parent of each node, rank stores tree height
public:
    // Constructor: initialize union-find with n elements
    UnionFind(int n) : root(n), rank(n) {
        rank.assign(n, 1);  // Initialize all ranks to 1
        iota(root.begin(), root.end(), 0);  // Each node is its own parent initially
    }

    // Find operation with path compression
    int Find(int x) {
        return (x == root[x])?x:root[x]=Find(root[x]);
    }

    // Union operation with union by rank
    void Union(int x, int y) {
        x= Find(x), y= Find(y);  // Find roots of both components
        if (x == y)  return;  // Already in same component
        if (rank[x] > rank[y]) swap(x, y);  // Ensure y has higher rank
        root[x] = y;  // Make y the parent of x
        if (rank[x]==rank[y]) rank[y]++;  // Update rank if needed
    }
};

class Solution {
public:
    using int3=tuple<int, int, int>; // (weight, vertex1, vertex2)
    int n;
    
    // Convert 2D coordinates to 1D index
    int to1D(int i, int j){
        return i*n+j;
    }
    
    int swimInWater(vector<vector<int>>& grid) {
        n=grid.size();
        if (n==1) return 0;  // Edge case: single cell
        
        // Build edges (weight, vertex1, vertex2) for all adjacent cells
        vector<int3> edges;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                // Add edge to cell below (if exists)
                if (i<n-1){
                    int wt=max(grid[i][j], grid[i+1][j]);  // Weight is max of both cells
                    edges.emplace_back(wt, to1D(i, j), to1D(i+1, j));
                }
                // Add edge to cell right (if exists)
                if (j<n-1){
                    int wt=max(grid[i][j], grid[i][j+1]);  // Weight is max of both cells
                    edges.emplace_back(wt, to1D(i, j), to1D(i, j+1));
                }
            }
        }
        
        // Sort edges by weight (Kruskal's algorithm approach)
        sort(edges.begin(), edges.end());
        
        int V=n*n;  // Total number of vertices
        UnionFind uf(V);
        
        // Process edges in ascending order of weight
        for(auto& [wt, v, w]: edges){
            // If vertices not connected, union them
            if (uf.Find(v)!=uf.Find(w))
                uf.Union(v, w);
            // Check if top-left (0) and bottom-right (V-1) are connected
            if (uf.Find(0)==uf.Find(V-1))
                return wt;  // Return minimum time when path exists
        }
        return 0;  // Should never reach here for valid input
    }
};