#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        // Set to keep track of visited strings to avoid cycles
        unordered_set<string> vis;
        // Initialize the smallest string as the original string
        string smallest = s;
        // BFS queue to explore all possible transformations
        queue<string> q;
        q.push(s);
        vis.insert(s);

        // BFS to explore all reachable strings
        while (!q.empty()) {
            string cur = q.front(); 
            q.pop();
            
            // Update smallest string if current is lexicographically smaller
            if (cur < smallest) smallest = cur;

            // Operation 1: Add 'a' to all odd-indexed digits
            string added = cur;
            for (int i = 1; i < added.size(); i += 2)
                added[i] = ((added[i] - '0' + a) % 10) + '0';
            if (!vis.count(added)) {
                vis.insert(added);
                q.push(added);
            }

            // Operation 2: Rotate string to the left by 'b' positions
            string rotated = cur.substr(cur.size() - b) + cur.substr(0, cur.size() - b);
            if (!vis.count(rotated)) {
                vis.insert(rotated);
                q.push(rotated);
            }
        }
        return smallest;
    }
};