#include <bits/stdc++.h>
using namespace std;

// Problem: Determine if a given integer is a power of three
// Approach: Use iterative division by 3 to check if the number can be reduced to 1

// Steps:
// 1. If n is less than or equal to 0, return false since powers of three are positive.
// 2. While n is divisible by 3, repeatedly divide n by 3.
// 3. After the loop, check if n is equal to 1.
// 4. If yes, n was a power of three; otherwise, it was not.

// Time Complexity: O(log₃ n) — each division by 3 reduces n by a factor of 3.
// Space Complexity: O(1) — uses only a constant amount of extra memory.

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        while (n % 3 == 0) {
            n /= 3;
        }
        return n == 1;
    }
};