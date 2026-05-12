class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {

        // sort by (minimum - actual) in descending order
        sort(tasks.begin(), tasks.end(),
            [&](vector<int> &a, vector<int> &b) {

                return (a[1] - a[0]) >
                       (b[1] - b[0]);
            });

        long long ans = 0;
        long long energy = 0;

        for(int i=0;i<tasks.size();i++) {
            int actual = tasks[i][0];
            int minimum = tasks[i][1];

            if(energy < minimum) { // increase initial energy if needed
                ans += (minimum - energy);
                energy = minimum;
            }
            energy -= actual;  // perform task
        }

        return (int)ans;
    }
};  