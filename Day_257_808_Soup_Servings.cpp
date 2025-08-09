#include<bits/stdc++.h>
using namespace std;
// Problem: Soup Servings
// Approach: Use memoization to efficiently compute the probability of serving soup A before soup B.
// Steps:
// 1. Define a recursive function that calculates the probability based on the current servings of soup A and B.
// 2. Use a cache to store already computed probabilities to avoid redundant calculations.
// 3. Base cases: if both soups are empty, return 0.5; if soup A is empty, return 1.0; if soup B is empty, return 0.0.
// 4. For each recursive call, consider the four possible serving combinations and compute their probabilities.
// Time Complexity: O(n^2) where n is the number of servings, due to memoization.
class Solution {
    vector<vector<double>> cache;
public:
    double soupServings(int n) {
        if (n > 5000) return 1.0;
        int units = (n + 24) / 25;
        cache.assign(units + 1, vector<double>(units + 1, -1.0));
        return calcProb(units, units);
    }

private:
    double calcProb(int soupA, int soupB) {
        if (soupA <= 0 && soupB <= 0) return 0.5;
        if (soupA <= 0) return 1.0;
        if (soupB <= 0) return 0.0;
        if (cache[soupA][soupB] != -1.0) return cache[soupA][soupB];
        double prob = 0.25 * (
            calcProb(soupA - 4, soupB) +
            calcProb(soupA - 3, soupB - 1) +
            calcProb(soupA - 2, soupB - 2) +
            calcProb(soupA - 1, soupB - 3)
        );
        cache[soupA][soupB] = prob;
        return prob;
    }
};