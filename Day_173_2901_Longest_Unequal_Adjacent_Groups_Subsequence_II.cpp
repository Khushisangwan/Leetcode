#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    std::vector<std::string> getWordsInLongestSubsequence(std::vector<std::string>& words, std::vector<int>& groups) {
        int n = words.size();
        std::vector<int> dp(n, 1);       // dp[i]: length of longest valid subsequence ending at i
        std::vector<int> prev(n, -1);    // prev[i]: previous index in the subsequence ending at i

        // Helper function to compute Hamming distance
        auto hammingDist = [](const std::string& s1, const std::string& s2) {
            if (s1.length() != s2.length()) return -1;
            int dist = 0;
            for (size_t i = 0; i < s1.length(); ++i) {
                if (s1[i] != s2[i]) ++dist;
            }
            return dist;
        };

        // Build dp and prev arrays
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (groups[i] != groups[j] &&
                    words[i].length() == words[j].length() &&
                    hammingDist(words[i], words[j]) == 1 &&
                    dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
        }

        // Find the index of the last word in the longest subsequence
        int max_len = 0, last_idx = 0;
        for (int i = 0; i < n; ++i) {
            if (dp[i] > max_len) {
                max_len = dp[i];
                last_idx = i;
            }
        }

        // Reconstruct the longest subsequence
        std::vector<std::string> result;
        while (last_idx != -1) {
            result.push_back(words[last_idx]);
            last_idx = prev[last_idx];
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};
