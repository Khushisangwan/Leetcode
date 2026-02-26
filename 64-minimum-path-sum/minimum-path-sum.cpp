class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int> prev(m,0);
        prev[0] = grid[0][0];
        // Fill first row
        for (int j = 1; j < m; j++) {
            prev[j] = prev[j - 1] + grid[0][j];
        }

        for(int i=1;i<n;i++){
            vector<int> curr(m,0);
            curr[0] = prev[0] + grid[i][0]; // first column
            for(int j=1;j<m;j++){
                curr[j]=min(curr[j-1],prev[j])+grid[i][j];
            }
            swap(curr,prev);
        }
        return prev[m-1];
    }
};
