#include<bits/stdc++.h>
using namespace std;
// Problem: Minimum Deletions to Make String K-Special
// Contest: Codeforces - Codeforces Round #308 (Div. 2)
class Solution {
public:
    // Returns the minimum number of deletions required to make the string k-special
    int minimumDeletions(string word, int k) {
        int ans = INT_MAX;
        vector<int> count(26); // Count frequency of each character

        // Count the frequency of each character in the string
        for (const char c : word)
            ++count[c - 'a'];

        // Try each possible minimum frequency as the base
        for (const int minFreq : count) {
            int deletions = 0;
            for (const int freq : count) {
                if (freq < minFreq)  // Delete all the letters with smaller frequency
                    deletions += freq;
                else  // Delete letters with exceeding frequency
                    deletions += max(0, freq - (minFreq + k));
            }
            ans = min(ans, deletions); // Update the answer with the minimum deletions found
        }

        return ans;
    }
};