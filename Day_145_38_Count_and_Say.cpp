#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        string result= "1";

    while (--n > 0) {
      string next;
      for (int i = 0; i < ans.length(); ++i) {
        int count = 1;
        while (i + 1 < ans.length() && ans[i] == ans[i + 1]) {
          ++count;
          ++i;
        }
        next += to_string(count) + ans[i];
      }
      result= std::move(next);
    }

    return ans;
    }
};