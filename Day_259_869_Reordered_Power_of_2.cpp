#include<bits/stdc++.h>
using namespace std;
// Problem: Reordered Power of 2
// Approach: Check if the digits of a number can be reordered to form a power of two.
// Steps:
// 1. Count the digits of the number and sort them.
// 2. For each power of two from 2^0 to 2^30, count its digits and sort them.
// 3. If the sorted digits of the number match the sorted digits of any power of two, return true.
// Time Complexity: O(1) since it involves a constant number of operations for checking up to 31 powers of two.
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        auto countDigits = [](int x) {
            string s = to_string(x);
            sort(s.begin(), s.end());
            return s;
        };
        string target = countDigits(n);
        for (int i = 0; i < 31; i++) {
            if (countDigits(1 << i) == target) return true;
        }
        return false;
    }
};