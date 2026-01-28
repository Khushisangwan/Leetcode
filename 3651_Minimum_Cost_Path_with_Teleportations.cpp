#include <bits/stdc++.h>
using namespace std;
const int M=1e4+1, NN=6400;
const int INF=1e9+7;

vector<int> x_pos[M]; // Maps each cost value to positions having that cost

unsigned dp[11][NN]; // dp[t][pos] = min cost to reach pos using at most t teleportations

unsigned suffixMin[M]; // suffixMin[x] = min cost among all cells with cost >= x

class Solution {
public:
    static inline int idx(int i, int j, int c) { return i*c+j; } // Convert 2D coords to 1D index

     static int minCost(vector<vector<int>>& grid, int k) {
          const int r=grid.size(), c=grid[0].size(), N=r*c;

          int xMax=0;
         // Build x_pos mapping: for each cost, store all cell positions with that cost
         for (int i=0; i<r; i++) {
                for (int j=0; j<c; j++) {
                     const int x=grid[i][j];
                     x_pos[x].push_back(idx(i, j, c));
                     xMax=max(xMax, x);
                }
          }

          // Initialize DP table
          for(int t=0; t<=k; t++)
                fill(dp[t], dp[t]+N, INF);

          // Base case: 0 teleportations, can only move right/down
          dp[0][0]=0;
          for (int i=0; i<r; i++) {
                for (int j=0; j <c; j++) {
                     const int pos=idx(i, j, c), x=grid[i][j];
                     if (i>0)
                          dp[0][pos]=
                                min(dp[0][pos], dp[0][idx(i-1, j, c)]+x);
                     if (j>0)
                          dp[0][pos]=
                                min(dp[0][pos], dp[0][idx(i, j-1, c)]+x);
                }
          }

         // Fill DP for each teleportation count t from 1 to k
         for (int t=1; t<=k; t++) {
                unsigned currMin=INF;
                // Compute suffix minimums: minimum cost to reach any cell with cost >= x
                for (int x=xMax; x>=0; x--) {
                     for (int idx : x_pos[x]) {
                          currMin=min(currMin, dp[t-1][idx]);
                     }
                     suffixMin[x]=currMin;
                }

                // Update DP using teleportation or normal moves
                for (int i=0; i<r; i++) {
                     for (int j=0; j<c; j++) {
                          const int pos=idx(i, j, c), x=grid[i][j];

                          // Option 1: Teleport to any cell with cost x
                          dp[t][pos]=min(dp[t-1][pos], suffixMin[x]);

                         // Option 2: Normal move from above
                          if (i>0)
                                dp[t][pos]=
                                     min(dp[t][pos], dp[t][idx(i-1, j, c)]+x);
                          // Option 3: Normal move from left
                          if (j>0)
                                dp[t][pos]=
                                     min(dp[t][pos], dp[t][idx(i, j-1, c)]+x);
                     }
                }
          }

          // Answer is minimum cost to reach bottom-right with at most k teleportations
          int ans=dp[k][N-1];

         // Cleanup
         for (int x=1; x<=xMax; x++)
                x_pos[x].clear();

          return ans;
     }
};