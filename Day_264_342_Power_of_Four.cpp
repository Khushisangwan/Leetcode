#include<bits/stdc++.h>
using namespace std;

// Problem: Check if a number is a power of four
// Approach: Continuously divide the number by 4 until it is no longer divisible, then check if it equals 1
// Steps:
// 1. If the number is less than or equal to zero, return false.
// 2. While the number is divisible by 4, divide it by 4.
// 3. After the loop, if the number equals 1, return true; otherwise, return false.

// Time Complexity: O(log n) — where n is the input number, as we divide it by 4 repeatedly.
// Space Complexity: O(1) — uses only a constant amount of extra memory.
class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        while (n % 4 == 0) n /= 4;
        return n == 1;
    }
};