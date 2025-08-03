#include<bits/stdc++.h>
using namespace std;
// Problem: Maximum Fruits Harvested After at Most K Steps
// Approach: Use a sliding window technique to find the maximum number of fruits that can be harvested within k steps from startPos.
// Steps:
// 1. Initialize two pointers for the sliding window: left and right.
// 2. Maintain a sum of fruits in the current window.
// 3. Expand the right pointer to include more fruits until the total steps exceed k.
// 4. If the steps exceed k, move the left pointer to reduce the window size until the steps are within k.
// 5. Keep track of the maximum number of fruits harvested during this process.
// Time Complexity: O(n) where n is the number of fruit trees.

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int left = 0, sum = 0, maxFruits = 0;
        for (int right = 0; right < fruits.size(); ++right) {
            sum += fruits[right][1];
            while (left <= right && minSteps(fruits[left][0], fruits[right][0], startPos) > k) {
                sum -= fruits[left][1];
                left++;
            }
            maxFruits = max(maxFruits, sum);
        }
        return maxFruits;
    }

    int minSteps(int left, int right, int start) {
        return min(abs(start - left) + (right - left),
                   abs(start - right) + (right - left));
    }
};