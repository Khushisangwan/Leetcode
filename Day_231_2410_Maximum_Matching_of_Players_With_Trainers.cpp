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