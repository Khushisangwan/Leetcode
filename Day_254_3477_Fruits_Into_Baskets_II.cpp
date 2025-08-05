#include<bits/stdc++.h>
using namespace std;
// Problem: Fruits Into Baskets II
// Approach: Use a greedy approach to place fruits into baskets.
// Steps:
// 1. Iterate through the list of fruits and try to place each fruit into the baskets.
// 2. Maintain a boolean array to track which baskets have been used.
// 3. For each fruit, check if there is a basket that can accommodate it.
// 4. If a basket can accommodate the fruit, mark that basket as used.
// 5. If no basket can accommodate the fruit, increment the count of unplaced fruits.
// Time Complexity: O(n^2) where n is the number of fruits and baskets, as we may need to check each basket for each fruit.
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<bool> used(n, false); 
        int unplaced = 0;

        for (int i = 0; i < n; i++) {
            bool placed = false;
            for (int j = 0; j < n; j++) {
                if (!used[j] && baskets[j] >= fruits[i]) {
                    used[j] = true;
                    placed = true;
                    break;
                }
            }
            if (!placed) {
                unplaced++;
            }
        }
        return unplaced;
    }
};