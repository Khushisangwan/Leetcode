#include <bits/stdc++.h>
using namespace std;

// Problem: Fruits Into Baskets III
// Approach: Use a segment tree to efficiently manage the baskets and fruits.

// Steps:
// 1. Build a segment tree to represent the baskets.
// 2. For each fruit, find the appropriate basket using the segment tree.
// 3. If a basket can accommodate the fruit, mark it as used and update the segment tree.
// 4. If no basket can accommodate the fruit, increment the count of unplaced fruits.
// 5. Return the total count of unplaced fruits.

// Time Complexity: O(n log n) where n is the number of baskets, as we build the segment tree and perform updates.
// Space Complexity: O(n) for the segment tree.


class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        int N = 1;
        while (N <= n) N <<= 1;

        vector<int> segTree(N << 1);
        for (int i = 0; i < n; ++i)
            segTree[N + i] = baskets[i];
        
        for (int i = N - 1; i > 0; --i)
            segTree[i] = max(segTree[2 * i], segTree[2 * i + 1]);

        int count = 0;
        for (int fruit : fruits) {
            int index = 1;
            if (segTree[index] < fruit) {
                count++;
                continue;
            }

            while (index < N) {
                if (segTree[2 * index] >= fruit)
                    index = 2 * index;
                else
                    index = 2 * index + 1;
            }

            segTree[index] = -1;
            while (index > 1) {
                index >>= 1;
                segTree[index] = max(segTree[2 * index], segTree[2 * index + 1]);
            }
        }
        return count;
    }
};