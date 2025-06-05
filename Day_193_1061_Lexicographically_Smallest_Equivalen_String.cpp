#include <bits/stdc++.h>
using namespace std;
// 1061. Lexicographically Smallest Equivalent String

class Solution {
public:
    // DFS to find the smallest lex character in the component
    // adj: adjacency list representing equivalence relations
    // cur: current character being visited
    // vis: visited array to avoid cycles
    char dfs(unordered_map<char, vector<char>>& adj, char cur, vector<int>& vis) {
        vis[cur - 'a'] = 1; // Mark current character as visited
        char minChar = cur; // Initialize minimum character as current
        for (char neighbor : adj[cur]) {
            if (vis[neighbor - 'a'] == 0) {
                // Recursively visit neighbors and update minimum character
                minChar = min(minChar, dfs(adj, neighbor, vis));
            }
        }
        return minChar; // Return the smallest character found in the component
    }

    // Main function to find the lexicographically smallest equivalent string
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.length();
        unordered_map<char, vector<char>> adj; // Adjacency list for equivalence graph

        // Step 1: Build the equivalence graph from s1 and s2
        for (int i = 0; i < n; ++i) {
            char u = s1[i];
            char v = s2[i];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Step 2: Replace each character in baseStr with the smallest equivalent character
        string result;
        for (char ch : baseStr) {
            vector<int> vis(26, 0); // Visited array for DFS
            char minChar = dfs(adj, ch, vis); // Find smallest equivalent character
            result.push_back(minChar); // Append to result
        }

        return result; // Return the final string
    }
};