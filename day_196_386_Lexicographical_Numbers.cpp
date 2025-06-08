
#include <bits/stdc++.h>
using namespace std;
// 386. Lexicographical Numbers
// This code defines a solution to generate numbers from 1 to n in lexicographical order.
// The solution uses a vector to store the results and iteratively builds the lexicographical order by multiplying and incrementing.

class Solution {
public:
    vector<int> lexicalOrder(int n) {
         vector<int> ans;
    int curr = 1;

    while (ans.size() < n) {
      ans.push_back(curr);
      if (curr * 10 <= n) {
        curr *= 10;
      } else {
        while (curr % 10 == 9 || curr == n)
          curr /= 10;
        ++curr;
      }
    }

    return ans;
    }
};