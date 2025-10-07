// this variant version uses different UnionFind class
#include<bits/stdc++.h>
using namespace std;
class UnionFind{
public:
    vector<int> root;
    
    // Constructor: Initialize Union-Find structure for tracking next available dry day
    UnionFind(vector<int>& rains, int n){
        root.resize(n+1);
        root[n]=n; // Boundary condition
        
        // For each day, if it's rainy, point to next day; if dry, point to itself
        for(int i=n-1; i>=0; i--)
            root[i]=(rains[i])?root[i+1]:i;
    }
    
    // Find the next available dry day with path compression
    int Find(int x){
        return (x==root[x])?x:root[x]=Find(root[x]);
    }
    
    // Union current day with next day (mark current day as used)
    void UnionNext(int x){
        root[x]=Find(x+1);// union x & x+1
    }
};

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        const int n=rains.size();

        // Union-Find to track next available dry day after consecutive rainy days
        UnionFind G(rains, n); 
        
        unordered_map<int, int> rainDay; // Maps lake -> last rainy day for that lake
        rainDay.reserve(n);
        
        vector<int> ans(n, 1); // Result array, default dry lake 1
        
        for(int i=0; i<n; i++){
            const int lake=rains[i];
            
            if (lake>0){ // Rainy day
                ans[i]=-1; // Mark as rainy day in result
                
                auto it=rainDay.find(lake);
                if (it!=rainDay.end()){ // Lake has rained before
                    int prev=it->second; // Previous rainy day for this lake
                    int dry=G.Find(prev+1); // Find next available dry day after previous rain
                    
                    if (dry>=i) return {}; // No dry day available before current day - impossible
                    
                    ans[dry]=lake;      // Use this dry day to empty the lake
                    G.UnionNext(dry);   // Mark this dry day as used
                    it->second=i;       // Update last rain day for this lake
                }
                else rainDay[lake]=i; // First time this lake rains
            } 
            // If rains[i]==0 (dry day), keep default ans[i]=1
        }
        return ans;
    }
};