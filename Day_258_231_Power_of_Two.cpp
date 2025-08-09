#include<bits/stdc++.h>
using namespace std;
// Problem: Power of Two
// Approach: Check if a number is a power of two using bit manipulation.
// Steps:
// 1. A number is a power of two if it is greater than zero and the bitwise AND of the number and one less than the number is zero.
// 2. This works because powers of two have only one bit set in their binary representation.
// Time Complexity: O(1) since it involves a constant number of operations.
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0 && (n & n-1) == 0 ;
    }
};