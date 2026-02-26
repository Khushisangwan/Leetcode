class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<int> prev(n,0);
        prev[0]=1;
        if(obstacleGrid[0][0]==1||obstacleGrid[m-1][n-1]==1){
            return 0;

        }
        for(int i=0;i<m;i++){
            int temp=0;
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]==1){
                    prev[j]=0;
                }
                else{
                    prev[j]=prev[j]+temp;
                }
                temp=prev[j];
            }
        }
        return prev[n-1];
    }
};