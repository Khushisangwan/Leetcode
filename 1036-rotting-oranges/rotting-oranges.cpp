class Solution {

public:

    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=-1, oneCount=0;

        queue<pair<int, int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) oneCount++;
                if(grid[i][j]==2) q.push({i, j});
            }
        }
        if(!oneCount) return 0;
        while(!q.empty()){
            int k=q.size();
            ans++;
            int r[4]={1, -1, 0, 0};
            int c[4]={0, 0, -1, 1};
            for(int i=0;i<k;i++){
                int row=q.front().first;
                int col=q.front().second;
                q.pop();
                for(int l=0;l<4;l++){
                    int nr=row+r[l];
                    int nc=col+c[l];
                    if((nr>=0 && nr<n) && (nc>=0 && nc<m) && grid[nr][nc]==1){
                        grid[nr][nc]=2;
                        q.push({nr, nc});
                        oneCount--;
                    }
                }
            }
        }
        if(oneCount>0) return -1;
        return ans;
    }
};