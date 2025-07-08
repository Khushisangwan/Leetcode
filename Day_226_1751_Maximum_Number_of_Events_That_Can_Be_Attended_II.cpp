#include<bits/stdc++.h>
using namespace std;
// Problem: 1751. Maximum Number of Events That Can Be Attended II
// Approach: Dynamic Programming with Binary Search
// Steps:
class Solution {
public:
    // Main function to find the maximum value by attending at most k non-overlapping events
    int maxValue(vector<vector<int>>& events, int k) {
        // Sort events by their end time
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int n = events.size();
        // dp[i][j]: max value by considering first i events and attending at most j events
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        for (int i = 1; i <= n; ++i) {
            // Find the last event that doesn't overlap with the current event
            int prev = binarySearch(events, events[i - 1][0]);

            for (int j = 1; j <= k; ++j) {
                // Either skip the current event or attend it and add its value
                dp[i][j] = max(dp[i - 1][j], dp[prev + 1][j - 1] + events[i - 1][2]);
            }
        }

        return dp[n][k];
    }

private:
    // Binary search to find the last event that ends before currentStart
    int binarySearch(vector<vector<int>>& events, int currentStart) {
        int left = 0, right = events.size() - 1;
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (events[mid][1] < currentStart) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
};