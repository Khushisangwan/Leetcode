#include<bits/stdc++.h>
using namespace std;
// LeetCode Problem 2081: Sum of k-Mirror Numbers
// Link: https://leetcode.com/problems/sum-of-k-mirror-numbers/
// Time Complexity: O(n * log(n)), where n is the number of k-mirror numbers to find.
// Space Complexity: O(log(n)), for storing the digits of the number in a vector.
class Solution {
public:
    // Helper function to create a palindrome number from 'num'.
    // If 'odd' is true, creates an odd-length palindrome, else even-length.
    long long createPalindrome(long long num, bool odd) {
        long long x = num;
        if (odd) x /= 10; // Skip the middle digit for odd-length palindromes
        while (x > 0) {
            num = num * 10 + x % 10; // Append reversed digits
            x /= 10;
        }
        return num;
    }

    // Checks if 'num' is a palindrome in the given 'base'.
    bool isPalindrome(long long num, int base) {
        vector<int> digits;
        // Convert number to the given base and store digits
        while (num > 0) {
            digits.push_back(num % base);
            num /= base;
        }
        // Check if the digits form a palindrome
        int i = 0, j = digits.size() - 1;
        while (i < j) {
            if (digits[i++] != digits[j--]) return false;
        }
        return true;
    }

    // Finds the sum of the first 'n' k-mirror numbers.
    long long kMirror(int k, int n) {
        long long sum = 0;
        // Generate palindromes by increasing length
        for (long long len = 1; n > 0; len *= 10) {
            // Odd-length palindromes
            for (long long i = len; n > 0 && i < len * 10; i++) {
                long long p = createPalindrome(i, true);
                if (isPalindrome(p, k)) {
                    sum += p;
                    n--;
                }
            }
            // Even-length palindromes
            for (long long i = len; n > 0 && i < len * 10; i++) {
                long long p = createPalindrome(i, false);
                if (isPalindrome(p, k)) {
                    sum += p;
                    n--;
                }
            }
        }
        return sum;
    }
};