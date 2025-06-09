#include<bits/stdc++.h>
using namespace std;
// 440. K-th Smallest in Lexicographical Order
// This code defines a solution to find the k-th smallest number in lexicographical order from 1 to n.
// The solution uses a method to calculate the gap between two numbers in lexicographical order and iteratively finds the k-th number.

class Solution {
public:
    // Finds the k-th smallest number in lexicographical order from 1 to n
    int findKthNumber(int n, int k) {
        long ans = 1; // Start from 1 (the smallest number)

        // Iterate k-1 times to find the k-th number
        for (int i = 1; i < k;) {
            const long gap = getGap(ans, ans + 1, n); // Calculate the number of numbers between ans and ans+1 in lex order
            if (i + gap <= k) {
                // If the k-th number is not in the subtree rooted at ans, move to next sibling
                i += gap;
                ++ans;
            } else {
                // Otherwise, go deeper into the subtree (next digit)
                ++i;
                ans *= 10;
            }
        }

        return ans;
    }

private:
    // Calculates the number of numbers between prefix a and b (exclusive) up to n
    long getGap(long a, long b, long n) {
        long gap = 0;
        while (a <= n) {
            // Add the count of numbers in the current range
            gap += min(n + 1, b) - a;
            a *= 10;
            b *= 10;
        }
        return gap;
    }
};