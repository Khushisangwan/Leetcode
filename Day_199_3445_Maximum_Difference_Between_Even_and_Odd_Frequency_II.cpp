#include <bits/stdc++.h>
using namespace std;
// 3445. Maximum Difference Between Even and Odd Frequency II
// This code defines a solution to find the maximum difference between the frequency of characters with even and odd counts in a string,
// considering only characters with frequencies greater than zero and a minimum length of k for the substring.

// Prefix sum frequency array for digits 0-4
array<vector<int>, 5> freq;
int n;

class Solution {
public:
    // Helper function to compute the maximum difference between freq[a] and freq[b]
    // for substrings of at least length k
    static int maxD_ab(int a, int b, int k) {
        int cnt = INT_MIN;
        // minFreq[x][y]: minimum value of freq[a]-freq[b] seen so far
        // for prefix with parity x (freq[a]%2) and y (freq[b]%2)
        const int INF = 1e8;
        int minFreq[2][2] = { {INF, INF}, {INF, INF} }; // 4 parity cases
        int freq_a = 0, freq_b = 0, prev_a = 0, prev_b = 0;
        // Sliding window: r is right end, l is left end
        for (int l = 0, r = k - 1; r < n; r++) {
            // Compute prefix sums for a and b up to r+1 (1-indexed)
            freq_a = freq[a][r + 1], freq_b = freq[b][r + 1];
            // Shrink window from left if there are at least 2 b's in the window
            while (r - l + 1 >= k && freq_b - prev_b >= 2) {
                // Update minimum freq[a]-freq[b] for current parity
                minFreq[prev_a & 1][prev_b & 1] = min(minFreq[prev_a & 1][prev_b & 1], prev_a - prev_b);
                // Move left pointer and update previous prefix sums
                prev_a = freq[a][l + 1];
                prev_b = freq[b][l + 1];
                l++;
            }
            // Update answer using the minimum value with opposite parity for freq[a]
            cnt = max(cnt, freq_a - freq_b - minFreq[1 - (freq_a & 1)][freq_b & 1]);
        }
        return cnt;
    }

    // Main function to compute the maximum difference for all pairs (a, b)
    static int maxDifference(string& s, int k) {
        n = s.size();
        freq.fill(vector<int>(n + 1, 0)); // Initialize prefix sum arrays
        // Build prefix sums for each digit 0-4
        for (int i = 0; i < n; i++) {
            for (int d = 0; d <= 4; d++) freq[d][i + 1] = freq[d][i];
            freq[s[i] - '0'][i + 1]++;
        }

        int ans = INT_MIN;
        // Try all pairs (a, b) where a != b and both appear in the string
        for (int a = 0; a <= 4; a++) {
            if (freq[a][n] == 0) continue; // Skip if a does not appear
            for (int b = 0; b <= 4; b++) {
                if (a == b || freq[b][n] == 0) continue; // Skip if same or b not present
                ans = max(ans, maxD_ab(a, b, k));
            }
        }

        return ans;
    }
};