class Solution {
public:
    // Memoization table to store computed results
    // dp[i][j] represents the minimum score for triangulating polygon from vertex i to j
    int dp[50][50] = {};
    
    int minScoreTriangulation(vector<int>& values, int i = 0, int j = 0, int res = 0) {
        // Initialize j to the last vertex if not specified (for initial call)
        if (j == 0) j = values.size() - 1;
        
        // Return memoized result if already computed
        if (dp[i][j] != 0) return dp[i][j];
        
        // Try all possible intermediate vertices k between i and j
        for (int k = i + 1; k < j; ++k) {
            // Calculate score: left subproblem + triangle (i,k,j) + right subproblem
            res = min(res == 0 ? INT_MAX : res,
                minScoreTriangulation(values, i, k) +          // Left partition
                values[i] * values[k] * values[j] +            // Current triangle score
                minScoreTriangulation(values, k, j));          // Right partition
        }
        
        // Store and return the minimum score for this subproblem
        return dp[i][j] = res;
    }
};