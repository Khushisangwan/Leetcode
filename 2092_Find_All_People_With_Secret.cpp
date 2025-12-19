//UnionFind modified from my old code https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/solutions/3930534/c-kruskal-s-algorithm-beats-95-26-math/
#include<bits/stdc++.h>
using namespace std;
class UnionFind {    
    vector<int> root, rank;
public:
    UnionFind(int n) : root(n), rank(n) {
        rank.assign(n, 1);
        iota(root.begin(), root.end(), 0);
    }

    // Path compression for efficient find
    int Find(int x) {
        return (x == root[x])?x: root[x]=Find(root[x]);
    }

    // Union by rank
    void Union(int x, int y) {
        int rX = Find(x), rY = Find(y);
        if (rX == rY)  return;
        if (rank[rX] > rank[rY]) swap(rX, rY);   
        root[rX] = rY;
        if (rank[rX]==rank[rY]) rank[rY]++;
    }
    
    // Check if two nodes are in same component
    bool connected(int x, int y) {
        return Find(x) == Find(y);
    }

    // Reset node to its own component (remove edges)
    void reset(int x){
        root[x]=x;
        rank[x]=1;
    }
};

class Solution {
public:
    using int2=pair<int, int>;
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson)
    {
        // Group meetings by time using counting sort (time <= 10^5)
        vector<int2> meet_time[100001];
        int tMax=-1;
        
        // Build meeting list indexed by time
        for(auto& meet: meetings){
            int x=meet[0], y=meet[1], t=meet[2];
            meet_time[t].emplace_back(x, y);
            tMax=max(tMax, t);
        }
        
        UnionFind uf(n);
        uf.Union(0, firstPerson); // Person 0 knows firstPerson from start
        
        // Process meetings in chronological order
        for (int t=0; t<=tMax; t++){
            // Union all people meeting at time t
            for(auto& [x, y]: meet_time[t])
                uf.Union(x, y);
            
            // Remove edges of people not connected to person 0
            for(auto& [x, y]: meet_time[t]){
                if (!uf.connected(0, x)){
                    uf.reset(x);
                    uf.reset(y);
                }
            }
        }
        
        // Collect all people connected to person 0
        vector<int> list={0};
        for(int i=1; i<n; i++)
            if (uf.connected(0, i)) list.push_back(i);

        return list;
    }
};

// Fast I/O optimization
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();