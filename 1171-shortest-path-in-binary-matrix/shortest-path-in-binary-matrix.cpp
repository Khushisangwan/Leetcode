class Solution {
    vector<pair<int, int>> dir = {{1, 1}, {1, 0}, {-1, 0}, {1, -1}, {-1, -1}, {-1, 1}, {0, 1}, {0, -1}};
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] || grid[n-1][n-1]) return -1;

        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;
        int ans = 0;

        while(!q.empty()) {
            int sz = q.size();
            ans++;
            while(sz--) {
                auto [x, y] = q.front();
                q.pop();
                if(x == n-1 && y == n-1) return ans;
                for(auto i : dir) {
                    int dx = x + i.first, dy = y + i.second;
                    if(dx >= 0 && dy >= 0 && dx < n && dy < n && !grid[dx][dy]) {
                        q.push({dx, dy});
                        grid[dx][dy] = 1;
                    }
                }
            }
        }  
        return -1;
    }
};