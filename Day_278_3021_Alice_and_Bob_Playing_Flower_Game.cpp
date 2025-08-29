#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Function to calculate the number of ways Alice and Bob can play the flower game
    // Alice wins when the total number of flowers is odd
    // This happens when one player picks from an odd pile and the other from an even pile
    long long flowerGame(int n, int m) {
        // Total combinations where Alice wins:
        // - Alice picks odd (from 1 to n), Bob picks even (from 1 to m)
        // - Alice picks even (from 1 to n), Bob picks odd (from 1 to m)
        // This equals: (odd_count_n * even_count_m) + (even_count_n * odd_count_m)
        // Which simplifies to: n * m / 2
        return 1LL * n * m / 2;
    }
};