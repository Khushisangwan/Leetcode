class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        if (n == 0) return 0;

        sort(walls.begin(), walls.end());

        vector<pair<int,int>> vp;
        for(int i = 0; i < n; i++) vp.push_back({robots[i], distance[i]});
        sort(vp.begin(), vp.end());

        vector<vector<long long>> intervals(n, vector<long long>(4));

        for(int i = 0; i < n; i++){
            long long pos = vp[i].first;
            long long d = vp[i].second;

            long long left_block = (i > 0 ? vp[i-1].first : LLONG_MIN);
            long long right_block = (i < n - 1 ? vp[i+1].first : LLONG_MAX);

            intervals[i][0] = max(pos - d, left_block);
            intervals[i][1] = pos;
            intervals[i][2] = pos;
            intervals[i][3] = min(pos + d, right_block);
        }

        auto getCount = [&](long long l, long long r){
            if (l > r) return 0; 
            auto it1 = lower_bound(walls.begin(), walls.end(), l);
            auto it2 = upper_bound(walls.begin(), walls.end(), r);
            return (int)(it2 - it1);
        };

        // memo[i][prev_dir]
        // prev_dir mapping: 0 = Left, 1 = Right, 2 = No previous robot
        vector<vector<int>> memo(n, vector<int>(3, -1));

        // Using a lambda for recursion in C++ requires passing `self` to call it recursively
        auto solve = [&](auto& self, int i, int prev_dir) -> int {
            // Base case
            if (i == n) return 0;
            
            // Check memoization table
            if (memo[i][prev_dir] != -1) return memo[i][prev_dir];

            long long prev_r = LLONG_MIN;
            if (prev_dir == 0) prev_r = intervals[i-1][1];
            else if (prev_dir == 1) prev_r = intervals[i-1][3];

            // Option 1: Move LEFT
            long long l1 = intervals[i][0], r1 = intervals[i][1];
            int walls_left = getCount(max(l1, prev_r + 1), r1);
            int ans_left = walls_left + self(self, i + 1, 0);

            // Option 2: Move RIGHT
            long long l2 = intervals[i][2], r2 = intervals[i][3];
            int walls_right = getCount(max(l2, prev_r + 1), r2);
            int ans_right = walls_right + self(self, i + 1, 1);

            // Store and return max
            return memo[i][prev_dir] = max(ans_left, ans_right);
        };

        // Start from index 0 with state 2 (no previous direction)
        return solve(solve, 0, 2);
    }
};