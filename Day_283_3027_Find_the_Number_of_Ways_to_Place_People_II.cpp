// this C++ uses ranges::sort with elapsed time 76ms
class Solution {
public:
    // Custom comparator: sort by x descending, then by y ascending
    static bool cmp(const vector<int>& p, const vector<int>& q){
        return (p[0]==q[0])?p[1]<q[1]:p[0]>q[0];// order by (x, >)
    }
    
    static int numberOfPairs(vector<vector<int>>& P) {
        // Sort points using custom comparator
        ranges::sort(P, cmp);
        int n = P.size(), ans = 0;
        
        // For each point as top-left corner
        for(int i=0; i<n-1; i++){
            int y=INT_MAX, yi=P[i][1]; // yi is y-coordinate of current top-left point
            
            // Check all points that could be bottom-right corner
            for(int j = i+1; j<n; j++){
                const int yj=P[j][1]; // yj is y-coordinate of potential bottom-right point
                
                // Valid pair if: yj >= yi (bottom-right below or same level as top-left)
                // and y > yj (no point blocking between them)
                if (yj>=yi && y>yj){//P[j] cannot be in between
                    ans++;
                    y=yj; // Update lowest y-coordinate found so far
                    if (yi==yj) break; // Same y-level, no need to check further
                }
            }
        }
        return ans;
    }
};

// Fast I/O optimization
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();