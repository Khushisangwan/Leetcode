#include<bits/stdc++.h>
using namespace std;
// 3170. Lexicographically Minimum String After Removing Stars
// This code defines a solution to remove stars from a string and return the lexicographically smallest string possible.
// The solution uses a vector of buckets to store indices of characters and processes stars accordingly.
// commit: add Solution class for lexicographically minimum string after removing stars

class Solution {
public:
    string clearStars(string s) {
         string ans = s;
    vector<vector<int>> buckets(26);

    for (int i = 0; i < s.length(); ++i)
      if (s[i] == '*') {
        ans[i] = ' ';
        int j = 0;
        while (buckets[j].empty())
          ++j;
        ans[buckets[j].back()] = ' ', buckets[j].pop_back();
      } else {
        buckets[s[i] - 'a'].push_back(i);
      }

    std::erase(ans, ' ');
    return ans;
    }
};