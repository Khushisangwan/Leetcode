#include <bits/stdc++.h>
using namespace std;

// Problem: Find the earliest and latest rounds where two players can meet in a knockout tournament
// Approach: Use recursive dynamic programming to explore all possible matchups

// Steps:
// 1. Define a recursive function that takes the current round, the two players' positions, and the total number of players.
// 2. Use memoization to avoid recalculating results for the same state.
// 3. Base case: if the two players are in the same position, record the round.
// 4. For each round, calculate the possible matchups and recursively call the function for the next round.
// 5. Return the earliest and latest rounds where the two players can meet.

// Time Complexity: O(n^3) in the worst case due to the nested loops and recursive calls.
// Space Complexity: O(n) for the memoization table.

class Solution {
public:
    int rMin=6, rMax=1;
    bool dp[6][28][29]={};
    void f(int round, int l, int r, int n){
        if (dp[round][l][r]) return;
        dp[round][l][r]=1;
        if (l>r) return f(round, r, l, n);
        if (l==r){
            rMin=min(round, rMin);
            rMax=max(round, rMax);
            return ;
        }
        int half=(n+1)/2, iN=min(l, half);
        for(int i=1; i<=iN; i++){
            int j0=max(l-i+1, 1);
            for(int j=min(half, r)-i; j>=j0; j--)
                if (l+r-(i+j)<=n/2)
                    f(round+1, i, j, half);
        }
    }


    vector<int> earliestAndLatest(int n, int first, int second) {
        f(1, first, n+1-second, n);
        return {rMin, rMax};
        
    }
};