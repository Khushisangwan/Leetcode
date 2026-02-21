class Solution {
private:
    vector<int> parent;
    int find(int i){
        if(parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    void unite(int u , int v){
        int root_u = find(u);
        int root_v = find(v);
        if(root_u != root_v) parent[root_u] = root_v;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        parent.resize(n);
        iota(parent.begin() , parent.end() , 0);
        for(int i = 0, m = edges.size(); i < m; ++i) unite(edges[i][0] , edges[i][1]);
        return find(source) == find(destination); 
    }
};