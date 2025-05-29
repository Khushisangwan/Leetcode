#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        // Build adjacency lists for both trees
        vector<vector<int>> graph1(n);
        vector<vector<int>> graph2(m);
        for (const auto& edge : edges1) {
            graph1[edge[0]].push_back(edge[1]);
            graph1[edge[1]].push_back(edge[0]);
        }
        for (const auto& edge : edges2) {
            graph2[edge[0]].push_back(edge[1]);
            graph2[edge[1]].push_back(edge[0]);
        }

        // Vectors to store parity (0 for even, 1 for odd) of depths
        vector<int> parity1(n, 0);
        vector<int> parity2(m, 0);

        // Count of even depth nodes in both trees
        int even1 = dfs(graph1, 0, -1, parity1, 0);
        int even2 = dfs(graph2, 0, -1, parity2, 0);

        int odd1 = n - even1;
        int odd2 = m - even2;

        vector<int> result(n);
        for (int i = 0; i < n; ++i) {
            // For each node in Tree1, calculate the maximum number of target nodes
            int tree1Targets = (parity1[i] == 0) ? even1 : odd1;
            int tree2Targets = max(even2, odd2);
            result[i] = tree1Targets + tree2Targets;
        }

        return result;
    }

private:
    // DFS to determine depth parity and count even depth nodes
    int dfs(const vector<vector<int>>& graph, int node, int parent, vector<int>& parity, int depth) {
        parity[node] = depth % 2;
        int count = (parity[node] == 0) ? 1 : 0;
        for (int neighbor : graph[node]) {
            if (neighbor != parent) {
                count += dfs(graph, neighbor, node, parity, depth + 1);
            }
        }
        return count;
    }
};
