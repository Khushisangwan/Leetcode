#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        // Sort horizontal and vertical bars
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        // Lambda function to find the maximum consecutive span of bars
        auto maxSpan = [](vector<int>& bars) {
            int res = 1, streak = 1;
            // Count consecutive bars (bars that differ by exactly 1)
            for (int i = 1; i < bars.size(); i++) {
                if (bars[i] - bars[i - 1] == 1) {
                    streak++;
                } else {
                    streak = 1;
                }
                res = max(res, streak);
            }
            // Add 1 to convert span to hole size
            return ++res;
        };

        // The square side length is limited by the minimum span
        int s = min(maxSpan(hBars), maxSpan(vBars));
        // Return the area of the square
        return s * s;
    }
};
