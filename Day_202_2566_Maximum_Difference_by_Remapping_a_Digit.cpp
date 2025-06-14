#include<bits/stdc++.h>
using namespace std;
// 2566. Maximum Difference by Remapping a Digit
// This code defines a solution to find the maximum difference by remapping a digit in a number.
// The goal is to replace one digit in the number with another digit to maximize the difference between the new number and the original number.

class Solution {
public:
    int minMaxDifference(int num) {
        const string s = to_string(num);
    const char to9 = s[firstNotNineIndex(s)];
    const char to0 = s[0];
    return getMax(s, to9) - getMin(s, to0);
  }

 private:
  int firstNotNineIndex(const string& s) {
    for (int i = 0; i < s.length(); ++i)
      if (s[i] != '9')
        return i;
    return 0;
  }

  int getMax(string s, char to9) {
    for (char& c : s)
      if (c == to9)
        c = '9';
    return stoi(s);
  }

  int getMin(string s, char to0) {
    for (char& c : s)
      if (c == to0)
        c = '0';
    return stoi(s);
    }
};