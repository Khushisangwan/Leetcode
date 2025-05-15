#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> result;

        if (words.empty()) return result;

        result.push_back(words[0]); // First word is always included

        for (int i = 1; i < words.size(); ++i) {
            if (groups[i] != groups[i - 1]) {
                result.push_back(words[i]);
            }
        }

        return result;
    }
};
