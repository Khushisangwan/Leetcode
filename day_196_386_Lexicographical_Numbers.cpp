
#include <bits/stdc++.h>
using namespace std;
// 386. Lexicographical Numbers
// This code defines a solution to generate numbers from 1 to n in lexicographical order.
// The solution uses a vector to store the results and iteratively builds the lexicographical order by multiplying and incrementing.

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans; // Vector to store the result
        int curr = 1;    // Start from 1

        // Continue until we have n numbers
        while (ans.size() < n) {
            ans.push_back(curr); // Add current number to result

            // Try to go deeper in lexicographical order (i.e., append a zero)
            if (curr * 10 <= n) {
                curr *= 10;
            } else {
                // If we can't go deeper, move to the next number
                // Go up until we can increment
                while (curr % 10 == 9 || curr == n)
                    curr /= 10;
                ++curr;
            }
        }

        return ans;
    }
};