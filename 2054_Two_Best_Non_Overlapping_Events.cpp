#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Tuple to store: time, isEnd (0=start, 1=end), value
    using info = tuple<int, bool, int>;
    
    static int maxTwoEvents(vector<vector<int>>& events) {
        const int n = events.size();
        
        // Create events array with start and end times
        vector<info> time(n * 2);
        for (int i = 0; i < n; i++) {
            int s = events[i][0], e = events[i][1], v = events[i][2];
            time[2 * i] = {s, 0, v};           // Start event
            time[2 * i + 1] = {e, 1, v};       // End event
        }
        
        // Sort by time, then by event type (ends before starts)
        sort(time.begin(), time.end());
        
        int ans = 0, maxV = 0, n2 = n * 2;
        
        // Process events in chronological order
        for (auto& [t, isEnd, v] : time) {
            if (isEnd)                          // If event ends, update max value seen
                maxV = max(maxV, v);
            else                                // If event starts, combine with best previous
                ans = max(ans, maxV + v);
        }
        
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();