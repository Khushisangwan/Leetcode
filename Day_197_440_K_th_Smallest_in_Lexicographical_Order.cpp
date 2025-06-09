#include<bits/stdc++.h>
using namespace std;
// 440. K-th Smallest in Lexicographical Order
// This code defines a solution to find the k-th smallest number in lexicographical order from 1 to n.
// The solution uses a method to calculate the gap between two numbers in lexicographical order and iteratively finds the k-th number.

class Solution {
public:
    int findKthNumber(int n, int k) {
         long ans = 1;

    for (int i = 1; i < k;) {
      const long gap = getGap(ans, ans + 1, n);
      if (i + gap <= k) {
        i += gap;
        ++ans;
      } else {
        ++i;
        ans *= 10;
      }
    }

    return ans;
  }

 private:
  long getGap(long a, long b, long n) {
    long gap = 0;
    while (a <= n) {
      gap += min(n + 1, b) - a;
      a *= 10;
      b *= 10;
    }
    return gap;+
    }
};