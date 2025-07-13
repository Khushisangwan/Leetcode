#include <bits/stdc++.h>
using namespace std;

// Problem: Match players with trainers such that each player is paired with a trainer whose strength meets or exceeds the player's requirement
// Approach: Use a two-pointer technique after sorting both players and trainers arrays

// Steps:
// 1. Sort both the players and trainers arrays.
// 2. Initialize two pointers, one for players and one for trainers.
// 3. Iterate through both arrays:
//    - If the current player can be matched with the current trainer (i.e., player's strength <= trainer's strength), increment both pointers and count this as a valid match.
//    - If the current player cannot be matched, move the trainer pointer to find a suitable
//      trainer.
// 4. Continue until either all players or all trainers have been considered.
// 5. Return the count of valid matches.

// Time Complexity: O(n log n + m log m) for sorting, where n is the number of players and m is the number of trainers.
// Space Complexity: O(1) for the two-pointer approach.

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int i = 0, j = 0, ans = 0, n = players.size(), m = trainers.size();
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        while (i < n && j < m) {
            if (players[i] <= trainers[j]) {
                ans++;
                i++;
                j++;
            }
            while (j < m && i < n && players[i] > trainers[j])
                j++;
        }

        return ans;
    }
};